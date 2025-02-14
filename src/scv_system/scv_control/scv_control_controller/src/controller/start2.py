#!/usr/bin/python3

import time
from threading import Thread
#from scv_control_controller import moraiCtrl, hunterCtrl
from moraictrl2 import moraiCtrl
#from hunterctrl import hunterCtrl


def keyinput(id, moraictl:moraiCtrl):
    flag = True
    while flag:
        inpdata = input('input value: ').split()
        if len(inpdata) == 2 :
            command = int(inpdata[0])

            value = float(inpdata[1])
        elif len(inpdata) == 1 :
            command = int(inpdata[0])
        else :
            print("try again")
            break

        if command == -1:
            flag = False
        elif command == 0:
            moraictl.emergencyBrake(True)
            moraictl.setTargetSpeed(0)
        elif command == 1:
            moraictl.emergencyBrake(False)
            moraictl.setTargetSpeed(value)
            print('target vel: {}/{}'.format(moraictl.targetVel, value))
            print("val", value)
        elif command == 2:
            moraictl.setSteeringAngle(value)


    print('keyinput has been died')

if __name__ == '__main__':
    mct = moraiCtrl()
    #mct = hunterCtrl()
    th1 = Thread(target=keyinput, args=(1, mct))
    th1.start()
    mct.runCtrl()
    th1.join()
    print('process is all done')