# Setup SCV

## Requirements

- Hunter 2.0 (또는 댜른 차량 플랫폼)
- 데스크탑
- ROS Noetic

## Install dependencies per package

각 패키지 별 README 참고하여 진행

## Network setup

데스크탑의 경우 공유기 및 LiDAR 센서 각각에 대해 RJ45 단자를 사용하므로
.bashrc에서 아래와 같이 설정하는것이 편함

'''bash
Ethernet Network 설정
echo '(password)' | sudo -S ifconfig (인터넷 네트워크) 192.168.1.2
echo '(password)' | sudo -S route add 192.168.1.2 (인터넷 네트워크)

VLP LiDAR Network 설정
echo '(password)' | sudo -S ifconfig (LiDAR 네트워크) 192.168.1.100
echo '(password)' | sudo -S route add 192.168.1.100 (LiDAR 네트워크)
'''
