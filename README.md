# AssistantWristband

## What's it about?

AssistantWristband is a primitive, smart-wristband developed in C programming language and ported to STM32F411 Nucleo Board. It keeps track of the steps taken throughout a walk and provides a nicely formatted GUI for both, the screen on it and a connected computer. It also has various modes, explained below, so that a user can take more advantage of it.

<p align="center">
  <img src="https://user-images.githubusercontent.com/23126077/87705015-edb7d300-c7a5-11ea-8c40-0abedbc965c5.jpg" />
</p>

## Features

* Step Mode
Number of steps as target is given and the buzzer rings once it is completed.

* Calorie Mode
Based on the height and the weight of a user, number of steps per calorie is calculated and the buzzer rings once the calories are burned accordingly. The relation between calorie, height and weight is based on the simplified version of the article.[1]

* ETA Information
Based on the number of steps taken and the amount of time passed during that, ETA is calculated and monitored onto screen.

## Hardware Components
Various hardware components are used throughtout the project. They are all listed below with their intentions and connections.

* STM32F411 Nucleo Board: The microcontroller that the software is ported to.
* HC06 Bluetooth Module:
  - It is used for transferring some informations to a computer so that they can be monitored via a control-panel-like-GUI.
  - Connections:
    - RX: CN10/12 - PA12
    - TX: CN10/14 - PA11
* MMA8452Q Accelerometer
  - It is used for obtaining 3D acceleration data so that a step can be detected.
  - Connections:
    - SDA: CN10/5 - PB9
    - SCL: CN10/3 - PB8
* Buzzer
  - It is used for notifying user that the number of steps set for a task is completed.
  - Connections:
    - CN7/28 - PA0
* Buttons
  - They are used for navigating modes and the wristband.
  - Connections:
    - CN7/35 - PC2 (left button)
    - CN7/36 - PC1 (middle button)
    - CN7/38 - PC0 (right button)
* ST7735S Led Screen
  - It is used for notifying user and navigating the wristband.
  - Connections:
    - SCLK(SCK): CN7/1 - PC10
    - MOSI(SDA): CN7/3 - PC12
    - A0(DC): CN7/2 - PC11
    - CS: CN7/4 - PD2
    - RST: CN7/17 - PA15

## Software Components
Various software modules are used throughtout the project. Modules with their corresponding hardwre components are listed below:
  - HC06: UART6
  - MMA8452Q: I2C1
  - BUZZER: TIM2-CH1(PWM)
  - BUTTONS: GPIO
  - ST7735S:
    - SPI3: SCLK(SCK), MOSI(SDA)
    - GPIO: CS, RST

## Step Detection Algorithm
A peak detection algorithm is used for detecting steps. Noise is reduced by using queue data structure for windowing the data and thresholds are determined by experimenting the movement. Pseudocode of the algorithm is below:

```
Note: walk_permission_enabled assigned true every 1 sec during timer interrupt
possible_step = false
window_acc_y = CreateQueue()
while True:
  y_acc = getYAxisAcceleration()
  enqueue(window_acc_y, y_acc)
  if (isFull(window_acc_y)) 
    dequeue(window_acc_y)
    if ((window_acc_y[2] - window_acc_y[0] < -40) and (window_acc_y[4] - window_acc_y[2] > 40)) 
          if (!possible_step and walk_permission_enabled) 
            possible_step = true
            walk_permission_enabled = false
            current_step +=1
          else 
            possible_step = false
      else 
        possible_step = false
```


## Demo

## References

[1] Ainsworth BE, Haskell WL, Herrmann SD, et al. 2011 Compendium of Physical Activities: a second update of codes and MET values. Med Sci Sports Exerc (2011).

## Built With
* [STM32F411RE Nucleo Board](https://www.st.com/en/evaluation-tools/nucleo-f411re.html)
