# Clouduino

![Logo](/docs/images/logo.png)

Clouduino is a fully open-source, WiFi mesh-enabled embedded development platform. 

This project is still at it's infancy. At the moment, the schematic diagram, breadboard prototype, and PCB layout for the first version is available for building the first version of the board: Clouduino Stratus. We also included sample code to get you started. We will be producing limited quantities of the board soon. In the meantime, let's build our own boards, send us your feed back and help this project grow.

## Specs

- CPU: 160 MHz
- L106 32-bit RISC Tensilica Xtensa Diamond Standard 106Micro
- 3.3V supply power
- Flash Memory: 4MB
- 16 GPIO pins
- 8 analog input channels with 12-bit resolution (programmable as single-ended or pseudo-differential pairs)
- SPI
- I2C support
- 12-bit SAR ADC support
- IEEE 802.11 b/g/n WiFi (w/ WEP, WPA, WPA2)

## Getting Started
Check out our Get Started Guide [here](https://github.com/proudcloud/clouduino/tree/master/getStarted).

## Quickstart Guide

1. Download and install [Arduino IDE](https://www.arduino.cc/en/Main/Software)
2. Follow [this guide](https://github.com/proudcloud/clouduino/tree/master/getStarted) to configure the IDE and upload your first sketch
3. Follow our [examples](https://github.com/proudcloud/clouduino/tree/master/example)

## Build Your Own Board

Schematic diagrams and breadboard prototype can be found in [this folder](https://github.com/proudcloud/clouduino/tree/master/schematics)

The following parts and components are all you need for this project:
- ESP-12F (ESP8266 module) with breakout board.
- MCP23S17 - general purpose I/O expander IC
- MCP3208 - 12bit, 8 channel Analogue to Digital Converter IC
- FTDI breakout with 3.3V power supply
- 2 Breadboards
- Jumper wires or connecting wires
- Header pins (optional)
- 3.3V power supply (optional) - if to be deployed remotely :)
