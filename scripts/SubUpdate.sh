#!/bin/bash

git submodule foreach '
  git fetch origin
  current_commit=$(git rev-parse HEAD)
  matching_branch=$(git branch -r --contains "$current_commit" | grep -v "\->" | sed "s|origin/||" | head -n1 | xargs)

  if [ -n "$matching_branch" ]; then
    echo "[$name] Found matching branch: $matching_branch → checking out"
    git checkout "$matching_branch"
  else
    echo "[$name] No matching remote branch found for commit $current_commit"
  fi
'
