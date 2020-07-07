import time
import psutil
import matplotlib.pyplot as plt
import serial
from random import seed
from random import randint
import random
# seed random number generator
seed(1)

fig = plt.figure()
ax = fig.add_subplot(111)
fig.show()
plt.ylim([-1,1])
i = 0
x, y = [], []

ser = serial.Serial('COM6', baudrate=9600)
if(ser.isOpen() == False):
   ser.open()

while True:
    datas = ser.readline().decode("utf-8").split(' ')
    print(float(datas[1]))
    x.append(i)
    y.append(float(datas[1]))
    
    ax.plot(x, y, color='b')
    
    fig.canvas.draw()
    
    ax.set_xlim(left=max(0, i-50), right=i+50)
    
    time.sleep(0.1)
    i += 1


plt.close()