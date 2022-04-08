# Navigation System for Blind People - `Smart Glove`

This project involves the development of an assistive smart glove using Light Detection and Ranging(LiDAR) technology and `Raspbery pi` to help individuals who are blind or with low vision to navigate with confidence. It contributes a `C++ library for TFMini s sensor` and use it in the development the hand glove.

## Status

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Contributors](https://img.shields.io/github/contributors/EvelynAnyebe/blind-nav-system)](https://github.com/EvelynAnyebe/blind-nav-system)
[![Open Issues](https://img.shields.io/github/issues-raw/EvelynAnyebe/blind-nav-system)](https://github.com/EvelynAnyebe/blind-nav-system/issues)
[![Closed Issues](https://img.shields.io/github/issues-closed-raw/EvelynAnyebe/blind-nav-system)](https://github.com/EvelynAnyebe/blind-nav-system)
[![PR](https://img.shields.io/github/issues-pr/EvelynAnyebe/blind-nav-system)](https://github.com/EvelynAnyebe/blind-nav-system)
[![Milestones](https://img.shields.io/github/milestones/all/EvelynAnyebe/blind-nav-system)](https://github.com/EvelynAnyebe/blind-nav-system)
[![Code Size](https://img.shields.io/github/languages/code-size/EvelynAnyebe/blind-nav-system)](https://github.com/EvelynAnyebe/blind-nav-system)

## Table of Contents

- [Motivation](#Motivation)
- [Hardware Requirements](#hardware-requirements)
- [Software Development](#software-development)
- [Installation](#installation)
- [Tests](#tests)
- [How to Use](#how-to-use)
- [Contributing Guide](#contributing-guide)
- [Social Media](#social-media)
- [Credits](#credits)
- [Reference Links](#reference-links)

## Motivation

There are many assistive technologies that aid blind people navigate their enviroment. These can be in eye glasses, walking canes, helmets etc. However, the usefulness of these devices are still in debate mbecause they are usually combined with guide dogs and canes.

Here a smart glove program is developed to tackle the navigation problem for blind people so that they can be confident to move without a cane or guide dog. [Find out more on our GitHub page here](https://embedded-programming-team-18.github.io/blind-nav-system/)

![smart hand glove to help blind people navigate](https://res.cloudinary.com/dxsty3st6/image/upload/v1643001489/blind-nav-system/smart_glove_3_pxaxcr.jpg)

```
    **Why Smart Glove?**
    1. Good for mobility as it is more compact.

    2. Flexible for position of a person.

    3. Ease of use than cane.

    4. More range than the stick.
```

## Hardware Requirements

The main componenents used for this project are:

```
    * Raspberry Pi 4
    * TFMini S LiDAR sensor
    * Servo motto
    * 5 mottos
    * Logic Converter
```

![Schematic Diagram of the blind navigation system](https://res.cloudinary.com/dxsty3st6/image/upload/v1649389827/blind-nav-system/Schematic-diagram-image_ty0cjs.jpg)

The servo motto board was coupled by the team and LEDs were used during the development stage. Logic converters were used to step-down voltage from +5V to +3V needed by the Lidar. The schematic diagram of the project is subject on changes. For instance, when using LEDs for the prototype `resistors` were added. [You can view this prototype here](https://www.instagram.com/p/CcE22h5jnIw/). The image gallery can be viewed on [instagram](https://www.instagram.com/blindnavsystem/)

## Software Development

![C++ Icon](https://res.cloudinary.com/dxsty3st6/image/upload/v1649395304/blind-nav-system/c_-48_mbi1wr.png) ![Vscode icon](https://res.cloudinary.com/dxsty3st6/image/upload/v1649395859/blind-nav-system/icons8-visual-studio-48_ss52sr.png) `CMAKE` `DOXYGEN`

This work followed Agile development approach. The various stages of the development process are outlined in order for simplicity.

**Requirement Analysis**

```
    * The LIDAR sensor(rotated by a servo motor) makes a map of 90o in front of the person.

    * According to the map, distance of the obstacles is calculated and returned.

    * Using that feedback, PWM is sent to a finger.
      Depending on the level of vibration on the fingers,
      the person gets an idea of where the obstacle is located, and he can go left or right.
```

**Software Design**

**Development**

**Testing**

**Releases**

**Documentation**

## Installation

**Downloading from GitHub**

The following steps serve as a guide for installation after Pi image is installed and hardware is built/coupled.

1. To use this Library, the following needs to be installed on your Pi.

   ```
       * PIGPIO: [this can be found here](https://abyz.me.uk/rpi/pigpio/download.html)
       * CMake
   ```

2. Enable Serioal port for `UART` on your Pi.
3. To compile and build the code after downloading from GitHub,
   ```
       * Cmake .
       * Make
   ```
4. ./blind-nav executable will be created.

**Installing the library**

## Tests

## How to Use

The usage of this work depends on your use case. In this repository, the Lidar library is configured to send PWM from the callback. The Lidar library can be customized to `output distance values` or any othe use case.

## Contributing Guide

'BLIND NAVIGATION SYSTEM' accepts PR's (pull requests) from _collaborators only_ only. Issues can be submitted by any of the collaborators. [The contributing guide can be found here](https://github.com/EvelynAnyebe/blind-nav-system/blob/gh-pages/CONTRIBUTING.md)

## Social Media

Find out more about the work on the following social media platforms.

- [twitter](https://twitter.com/BlindNav)
- [instagram](https://www.instagram.com/blindnavsystem/)
- [Youtube](https://www.youtube.com/channel/UC3s1xHjyCuRFFpUrwtq7xhg)

## Credits

- [Meghna Choudhury](Megna)
- [Faiza Abdul Salam](Faiza)
- [Abdul Ghani Zahid](Abdul)
- [Evelyn Onyi Anyebe](Evelyn)

### Reference Links

- [dfrobot.com](https://www.dfrobot.com/product-1702.html)
- [README FILE-Everything you need to know](https://www.mygreatlearning.com/blog/readme-file/)
- [Lidar code on GitHub](https://github.com/berndporr/neato-xv11-lidar)
- [pigpio](https://abyz.me.uk/rpi/pigpio)
