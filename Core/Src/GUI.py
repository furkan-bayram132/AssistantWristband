'''
import time
import psutil
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import serial
from matplotlib.animation import FuncAnimation
from random import seed
from random import randint
from tkinter import *
from PIL import ImageTk,Image
import random

# seed random number generator
seed(1)

fig, axs = plt.subplots(3, figsize=(6, 8))
fig.suptitle('Accelerometer Datas')

axs[0].set_ylim([-1024, 1024])
axs[1].set_ylim([-1024, 1024])
axs[2].set_ylim([-1024, 1024])

i = 0
x, acc_x, acc_y, acc_z = [], [], [], []


ser = serial.Serial('COM6', baudrate=9600)
if(ser.isOpen() == False):
  ser.open()


def OnClosing():
    plt.close()



def calculateETA(elapsed_time):
    current_hour = elapsed_time // 3600
    current_min = (elapsed_time - (3600 * current_hour)) // 60
    current_sec = elapsed_time - (3600 * current_hour) - (current_min * 60)
    return current_hour, current_min, current_sec


def HandleDatas(a):
    datas = ser.readline().decode("utf-8").split(' ')
    #print(int(datas[1]), int(datas[2]), int(datas[3]), int(datas[4]), int(datas[5]))
    if int(datas[7]) == 1:
        print('step: ')
    global i
    x.append(i)
    acc_x.append(int(datas[1]))
    acc_y.append(int(datas[2]))
    acc_z.append(int(datas[3]))
    axs[0].plot(x, acc_x, color='b')
    axs[1].plot(x, acc_y, color='b')
    axs[2].plot(x, acc_z, color='b')

    axs[0].set_xlim(left=max(0, i - 50), right=i + 50)
    axs[1].set_xlim(left=max(0, i - 50), right=i + 50)
    axs[2].set_xlim(left=max(0, i - 50), right=i + 50)

    # time.sleep(0.1)

    first_variable = int(datas[7]) ################## ADIM MIKTARI
    second_variable = int(datas[6])
    first_label = Label(root, text=str(first_variable) + " / " + str(second_variable), width=12, height=5, bg="white", font=("Courier", 20, "bold"))
    first_label.place(relx=0.78, rely=0.1)
    ETA = calculateETA(int(datas[4]))
    third_variable = ETA[0]
    fourth_variable = ETA[1]
    fifth_variable = ETA[2]
    first_label = Label(root, text=str(third_variable) + ":" + str(fourth_variable) + ":" + str(fifth_variable), width=12, height=5, bg="white", font=("Courier", 20, "bold"))
    first_label.place(relx=0.78, rely=0.7)

    i += 1



root = Tk()
root.configure(background="white")
root.resizable(False,False)
root.geometry("1000x600")
canvas = FigureCanvasTkAgg(fig, root)
canvas.draw()
canvas_widget = canvas.get_tk_widget()

canvas_widget.pack(expand=True)

weight_height = ser.readline().decode("utf-8").split(' ')

kilo = int(weight_height[1]) ############################ BOY
boy = int(weight_height[2]) ########################## KILO


ani = FuncAnimation(fig, HandleDatas, interval=50) ####################### INTERVAL


x_label = Label(root,text = "X",width = 5,height = 5,bg = "white",font = ("Courier",15,"bold"))
x_label.place(relx = 0.07,rely= 0.10)

y_label = Label(root,text = "Y",width = 5, height = 5,bg = "white",font=("Courier", 15, "bold"))
y_label.place(relx= 0.07,rely = 0.40)

z_label = Label(root,text = "Z",width = 5, height = 5,bg = "white",font=("Courier", 15, "bold"))
z_label.place(relx= 0.07,rely = 0.70)

boy_label = Label(root, text= str(boy) + " cm", width=10, height=5, bg="white", font=("Courier", 20, "bold"))
boy_label.place(relx=0.78, rely=0.3)

kilo_label = Label(root, text=str(kilo) + " kg", width=10, height=5, bg="white", font=("Courier", 20, "bold"))
kilo_label.place(relx=0.78, rely=0.5)


root.protocol("WM_DELETE_WINDOW", OnClosing)

root.mainloop()
'''

import time
import psutil
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import serial
from matplotlib.animation import FuncAnimation
from random import seed
from random import randint
from tkinter import *
from PIL import ImageTk,Image
import random

x, acc_x, acc_y, acc_z = [], [], [], []


ser = serial.Serial('COM6', baudrate=9600)
if(ser.isOpen() == False):
  ser.open()

while True:
    datas = ser.readline().decode("utf-8").split(' ')
    print(datas[7])