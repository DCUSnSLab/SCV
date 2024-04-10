# LiDAR 네트워크 설정
echo 'wwwsnslab1!' | sudo -S ifconfig enp0s31f6 192.168.1.100
echo 'wwwsnslab1!' | sudo -S route add 192.168.1.100 enp0s31f6

# Ethernet 네트워크 설정
echo 'wwwsnslab1!' | sudo -S ifconfig enp7s0 192.168.1.2
echo 'wwwsnslab1!' | sudo -S route add 192.168.1.2 enp7s0

echo 'wwwsnslab1!' | sudo -S modprobe gs_usb
#rosrun hunter_bringup bringup_can2usb.bash

echo 'wwwsnslab1!' | sudo -S chmod 777 /dev/ttyACM*
