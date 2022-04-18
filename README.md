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

![smart hand glove to help blind people navigate](https://res.cloudinary.com/dxsty3st6/image/upload/v1650268032/blind-nav-system/the_glove_fitted_gfcfet.jpg)

```
    **Why Smart Glove?**
    1. Good for mobility as it is more compact.

    2. Flexible for position of a person.

    3. Ease of use than cane.

    4. More range than the stick.
```

## Hardware Requirements

![raspberry pi](https://res.cloudinary.com/dxsty3st6/image/upload/v1649396693/blind-nav-system/icons8-raspberry-pi-48_wvkoak.png)

The main componenents used for this project are:

```
    * Raspberry Pi 4
    * TFMini S LiDAR sensor
    * Servo motto
    * 5 mottos
    * Logic Converter
```

![Schematic Diagram of the blind navigation system](https://res.cloudinary.com/dxsty3st6/image/upload/c_scale,h_388/v1649389827/blind-nav-system/Schematic-diagram-image_ty0cjs.jpg)

The servo motto board was coupled by the team and LEDs were used during the development stage. Logic converters were used to step-down voltage from +5V to +3V needed by the Lidar. The schematic diagram of the project is subject on changes. For instance, when using LEDs for the prototype `resistors` were added. [You can view this prototype here](https://www.instagram.com/p/CcE22h5jnIw/). The image gallery can be viewed on [instagram](https://www.instagram.com/blindnavsystem/)

## Software Development

![C++ Icon](https://res.cloudinary.com/dxsty3st6/image/upload/v1649395304/blind-nav-system/c_-48_mbi1wr.png) ![Vscode icon](https://res.cloudinary.com/dxsty3st6/image/upload/v1649395859/blind-nav-system/icons8-visual-studio-48_ss52sr.png)

This work followed Agile development approach. The various stages of the development process are outlined in order for simplicity.

**Requirement Analysis**

```
    * The LIDAR sensor(rotated by a servo motor) makes a map of 90o in front of the person.

    * According to the map, distance of the obstacles is calculated and returned.

    * Using that feedback, PWM is sent to a finger.
      Depending on the level of vibration on the fingers,
      the person gets an idea of where the obstacle is located, and he can go left or right.
```

![Image of the lidar full scan split](https://res.cloudinary.com/dxsty3st6/image/upload/v1649998685/blind-nav-system/field-of-view-split-in-5_vsp8rx.jpg)

A full scan of the LiDAR (90 degrees) split into 5 directions to guide the user. This is implemented in `main.cpp` where the driver is used

**Software Design**

The classes `Lidar`, `Servo`, `Pwm`, `DataInterface : Lidar::DataInterface` are defined for this work. The doxygen documentation [available here](https://embedded-programming-team-18.github.io/doxygen/index.html). The software design is described with the following use cases and diagrams.

- Use cases

  ![smart glove use case of the lidar driver](https://res.cloudinary.com/dxsty3st6/image/upload/v1650001317/blind-nav-system/blind-man-use-case_v94lsr.jpg)

  In this work, a blind navigation system as a smart glove is demonstrated with the LiDAR driver. A blind person puts on the glove and gets vibrations on his fingers. The intensity of the vibration tells the direction with the nearest obstacle. The individual can decide the direction to move.

  The driver can be used for other use cases as well.

  ![A mobile robot use case of the lidar driver](https://res.cloudinary.com/dxsty3st6/image/upload/v1650001331/blind-nav-system/robot-use-case_c97yjf.jpg)

- State Diagram

  The state diagram below shows the state changes of the `smart glove` application.

  ![State diagram for the smart glove](https://res.cloudinary.com/dxsty3st6/image/upload/v1649998685/blind-nav-system/State-diagram-class-diagram_nglqel.jpg)

  The state diagram for the lidar object running as a thread is displayed below.

  ![State diagram for the liDAR thread](https://res.cloudinary.com/dxsty3st6/image/upload/v1649998685/blind-nav-system/lidar-thread-state-diagram_gfo9hg.jpg)

- Sequence Diagram

  The following diagram models the communication between objects in the smart glove software.

  ![Sequence diagram for the smart glove application](https://res.cloudinary.com/dxsty3st6/image/upload/v1650067799/blind-nav-system/sequence_diagram_for_smart_glove_frxcj2.jpg)

**Development**

`c++` `CMAKE` `DOXYGEN` `googletest`

The - [Hardware Requirements](#hardware-requirements), [Software Development](#software-development)
and [Installation](#installation) guides should be reviewed before commencing development using this code.

**Testing**

Google test is used for unit test in this work. Test cases are:

**Pwm**

```
  Test the pwm sent according to the double threshold set

  1. distance = 0, pwm = 255
  2. distance = -2000, pwm =255
  3. distance = 100, pwm = 0
  3. distance = 167, pwm = 0
  4. distance = 26550, pwm = 0
```

**Servo::move**

```
  Test algorithm

  for(int i=0; i<89; i++)
    EXPECT_EQ(servoMove(), i+1);

```

**Releases**

- The current release of this work is release v1.0

**Documentation**

This work is documented here for quick start. You can also check:

- Doxygen documentation [available here](https://embedded-programming-team-18.github.io/doxygen/index.html).
- [The GitHub page](https://embedded-programming-team-18.github.io/blind-nav-system/)

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

## Tests

Steps to run tests are:

1. cmake .
2. make
3. ./testRunner

## How to Use

Using this work depends on your use case. In this repository, the Lidar library is designed to send its full scan `90 distance values` to a callback which is implemented depending on the use case. The smart glove implemented in this project shows this [here](https://github.com/Embedded-programming-Team-18/blind-nav-system/blob/gh-pages/main.cpp).

```
    class DataInterface : public Lidar::DataInterface {
        void newScanAvail(int (&data)[Lidar::nDistance]) {
                // implement this callback function

            }
    }

```

To use the smart glove application, follow the installation guide [Installation](#installation).

## Contributing Guide

'BLIND NAVIGATION SYSTEM' accepts PR's (pull requests) from _collaborators only_ only. Issues can be submitted by any of the collaborators. [The contributing guide can be found here](https://github.com/EvelynAnyebe/blind-nav-system/blob/gh-pages/CONTRIBUTING.md)

## Social Media

![twitter](https://res.cloudinary.com/dxsty3st6/image/upload/v1649395859/blind-nav-system/icons8-twitter-48_pt4icz.png) ![instagram](https://res.cloudinary.com/dxsty3st6/image/upload/v1649395859/blind-nav-system/icons8-instagram-48_k5kuwi.png) ![youtube](https://res.cloudinary.com/dxsty3st6/image/upload/v1649395859/blind-nav-system/icons8-youtube-48_kpall9.png)

Find out more about the work on the following social media platforms:

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
- [berndporr/neato-xv11-lidar](https://github.com/berndporr/neato-xv11-lidar)
- [pigpio](https://abyz.me.uk/rpi/pigpio)

```

  Cheers!

```
