import time
import psutil
import matplotlib.pyplot as plt
import serial
from random import seed
from random import randint
import random
# seed random number generator
seed(1)

fig, axs = plt.subplots(3)
fig.suptitle('Accelerometer Datas')

axs[0].set_ylim([-1024,1024])
axs[1].set_ylim([-1024,1024])
axs[2].set_ylim([-1024,1024])

fig.show()
i = 0
x, acc_x, acc_y, acc_z = [], [], [], []

ser = serial.Serial('COM6', baudrate=9600)
if(ser.isOpen() == False):
   ser.open()

while True:
    datas = ser.readline().decode("utf-8").split(' ')
    print(int(datas[1]), int(datas[2]), int(datas[1]))
    x.append(i)
    acc_x.append(int(datas[1]))
    acc_y.append(int(datas[2]))
    acc_z.append(int(datas[3]))    
    axs[0].plot(x, acc_x, color='b')
    axs[1].plot(x, acc_y, color='b')
    axs[2].plot(x, acc_z, color='b')
    
    fig.canvas.draw()
    
    axs[0].set_xlim(left=max(0, i-50), right=i+50)
    axs[1].set_xlim(left=max(0, i-50), right=i+50)
    axs[2].set_xlim(left=max(0, i-50), right=i+50)

    i += 1


plt.close()