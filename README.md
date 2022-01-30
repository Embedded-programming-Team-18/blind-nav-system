# Navigation System for Blind People - `Smart Glove`
This project involves the development of an assistive smart glove using Light Detection and Ranging(LiDAR) technology and Raspbery pi to help individuals who are blind or with low vision to navigate with confidence.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![Contributors](https://img.shields.io/github/contributors/EvelynAnyebe/blind-nav-system)

## Contents

* [Introduction](#introduction)
* [Why Smart Glove](#why-Smart-Glove)
* [Hardware Specification](#hardware-specification)
* [How it Works](#how-it-works)
* [Contributors](#contributors)

### Introduction
There are many assistive technologies that aid blind people navigate their enviroment. These can be in eye glasses, walking canes, helmets etc. Some of these need to be combined with dogs, a smart phone or GPS and utilizes Ultrasonic sensors, IR or different light detection sensing for detecting obstacles and their distances. However, the usefulness of these devices are still in debate mostly due to a huge confidence in the traditional use of guide dogs and canes. 

Here a smart glove program is developed to tackle the navigation problem for blind people. Careful consideration is taken into ease of use for the blind individual, long range detection and real-time feedback using vibrotactile feedback.
   
![smart hand glove to help blind people navigate](https://res.cloudinary.com/dxsty3st6/image/upload/v1643001489/blind-nav-system/smart_glove_3_pxaxcr.jpg)

#### Why Smart Glove?
1. Good for mobility as it is more compact.
2. Flexible for position of a person because the direction of the sensor changes with the direction of the person.
3. Ease of use than cane   with vibratic signal sent to the fingers.
4. More range than the stick.

### Hardware Specification
- Raspberry Pi 3
- TFMini S LiDAR sensor
- Servo motto controller with Arduino and 5 mottos
- Logic Converter

### HOW IT WORKS
- The LIDAR sensor(rotated by a servo motor) makes a map of 90o in front of the person.
- According to the map and distance at which the obstacles the fingers get a feedback.
- Using that feedback the person and get an idea of where the obstacle is located, and he can go left or right.
  
### Contributors
- Meghna Choudhury
- Faiza Abdul Salam
- Abdul Ghani Zahid
- Evelyn Onyi Anyebe

### Reference Links
- [dfrobot.com](https://www.dfrobot.com/product-1702.html)