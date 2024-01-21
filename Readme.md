# Raspberry Pi Pico w ancs client demo

## Description

This code is based on pico-examples and adapted by picking up the ANCS client demo.  

[pico-examples](https://github.com/raspberrypi/pico-examples)  


## Requirement

- Raspberry Pi Pico w
- pico-sdk

## Usage

1. Build the source code
```
$ cd ancs_client_demo
$ mkdir build
$ cd build
$ cmake ..
$ make
```
2. Drag and drop the UF2 file onto the Pico W drive
3. Connect iPhone and Pico W via Bluetooth
4. When there is a notification on the iPhone, logs are output to the serial of Pico W


## Contribution

1. Fork this repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Create new Pull Request

## Author

[stonedev-app](https://github.com/stonedev-app)

## Licence

[MIT License](https://en.wikipedia.org/wiki/MIT_License).