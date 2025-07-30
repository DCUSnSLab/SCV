#!/bin/bash

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 현재 디렉토리 확인
if [ ! -f ".gitmodules" ]; then
    echo -e "${RED}Error: .gitmodules file not found. Run this script from the root of your git repository.${NC}"
    exit 1
fi

echo -e "${BLUE}=== Git Submodule Manager ===${NC}\n"

# 메뉴 표시
echo "Choose an option:"
echo "1) Status - Check status of all submodules"
echo "2) Update - Pull latest changes from all submodules"
echo "3) Commit - Commit changes in modified submodules"
echo "4) Push - Push all submodules to their respective branches"
echo "5) Full sync - Update, commit, and push all changes"
echo "6) Custom command - Run custom command in all submodules"
echo "0) Exit"

read -p "Enter your choice: " choice

case $choice in
    1)
        echo -e "\n${YELLOW}Checking status of all submodules...${NC}\n"
        git submodule foreach --quiet '
            if [ -n "$(git status --porcelain)" ]; then
                echo -e "'${RED}'[Modified] $name ($(git rev-parse --abbrev-ref HEAD))'${NC}'"
                git status --short
            else
                echo -e "'${GREEN}'[Clean] $name ($(git rev-parse --abbrev-ref HEAD))'${NC}'"
            fi
            echo ""
        '
        ;;
        
    2)
        echo -e "\n${YELLOW}Updating all submodules...${NC}\n"
        git submodule update --recursive --remote
        git submodule foreach --quiet '
            branch=$(git rev-parse --abbrev-ref HEAD)
            echo -e "'${BLUE}'Pulling $name on branch $branch...'${NC}'"
            git pull origin $branch || echo -e "'${RED}'Failed to pull $name'${NC}'"
        '
        ;;
        
    3)
        echo -e "\n${YELLOW}Committing changes in modified submodules...${NC}\n"
        read -p "Enter commit message (or press Enter for default): " commit_msg
        if [ -z "$commit_msg" ]; then
            commit_msg="Update submodule - $(date +%Y-%m-%d)"
        fi
        
        git submodule foreach --quiet '
            if [ -n "$(git status --porcelain)" ]; then
                echo -e "'${YELLOW}'Committing changes in $name...'${NC}'"
                git add .
                git commit -m "'"$commit_msg"'" && echo -e "'${GREEN}'✓ Committed'${NC}'" || echo -e "'${RED}'✗ Commit failed'${NC}'"
                echo ""
            fi
        '
        ;;
        
    4)
        echo -e "\n${YELLOW}Pushing all submodules...${NC}\n"
        git submodule foreach --quiet '
            current_branch=$(git rev-parse --abbrev-ref HEAD)
            config_branch=$(git config -f $toplevel/.gitmodules submodule.$name.branch)
            
            # If no branch configured in .gitmodules, use current branch
            target_branch=${config_branch:-$current_branch}
            
            # Warning if branches are different
            if [ -n "$config_branch" ] && [ "$current_branch" != "$config_branch" ]; then
                echo -e "'${YELLOW}'⚠️  Warning: $name is on branch $current_branch but .gitmodules specifies $config_branch'${NC}'"
                echo -e "'${BLUE}'   Pushing to configured branch: $config_branch'${NC}'"
            else
                echo -e "'${BLUE}'Pushing $name to origin/$target_branch...'${NC}'"
            fi
            
            # Push to the target branch
            if [ "$current_branch" != "$target_branch" ]; then
                # Push current HEAD to different branch
                git push origin HEAD:$target_branch && echo -e "'${GREEN}'✓ Pushed successfully'${NC}'" || echo -e "'${RED}'✗ Push failed'${NC}'"
            else
                # Normal push
                git push origin $target_branch && echo -e "'${GREEN}'✓ Pushed successfully'${NC}'" || echo -e "'${RED}'✗ Push failed'${NC}'"
            fi
            echo ""
        '
        ;;
        
    5)
        echo -e "\n${YELLOW}Full sync: Update, commit, and push all changes...${NC}\n"
        
        # Update
        echo -e "${BLUE}Step 1: Updating submodules...${NC}"
        git submodule update --recursive --remote
        
        # Commit
        echo -e "\n${BLUE}Step 2: Committing changes...${NC}"
        read -p "Enter commit message: " commit_msg
        if [ -z "$commit_msg" ]; then
            commit_msg="Update submodule - $(date +%Y-%m-%d)"
        fi
        
        git submodule foreach --quiet '
            if [ -n "$(git status --porcelain)" ]; then
                echo -e "'${YELLOW}'Committing $name...'${NC}'"
                git add .
                git commit -m "'"$commit_msg"'"
            fi
        '
        
        # Push
        echo -e "\n${BLUE}Step 3: Pushing changes...${NC}"
        git submodule foreach --quiet '
            current_branch=$(git rev-parse --abbrev-ref HEAD)
            config_branch=$(git config -f $toplevel/.gitmodules submodule.$name.branch)
            target_branch=${config_branch:-$current_branch}
            
            if [ -n "$config_branch" ] && [ "$current_branch" != "$config_branch" ]; then
                echo -e "'${YELLOW}'⚠️  $name: $current_branch -> $config_branch'${NC}'"
                git push origin HEAD:$target_branch
            else
                echo -e "'${YELLOW}'Pushing $name to origin/$target_branch...'${NC}'"
                git push origin $target_branch
            fi
        '
        
        # Update main repo
        echo -e "\n${BLUE}Step 4: Updating main repository...${NC}"
        if [ -n "$(git status --porcelain)" ]; then
            git add .
            git commit -m "Update submodule references"
            git push
            echo -e "${GREEN}✓ Main repository updated${NC}"
        else
            echo -e "${GREEN}Main repository already up to date${NC}"
        fi
        ;;
        
    6)
        echo -e "\n${YELLOW}Custom command execution${NC}"
        read -p "Enter command to run in all submodules: " custom_cmd
        if [ -n "$custom_cmd" ]; then
            git submodule foreach "$custom_cmd"
        fi
        ;;
        
    0)
        echo -e "${GREEN}Exiting...${NC}"
        exit 0
        ;;
        
    *)
        echo -e "${RED}Invalid option${NC}"
        exit 1
        ;;
esac

echo -e "\n${GREEN}Done!${NC}"
