#adaptive_lighting-firmware
Firmware for the adaptive lighting hub.
##Setup
 Clone repostiory. 
```
git clone https://github.com/anuragmakineni/lighting_firmware.git
```
##Compiling
You'll need to install the following gcc arm cross compiler.

####Ubuntu
```
sudo apt-get install gcc-arm-none-eabi
```

####Mac OS
```
brew tap PX4/homebrew-px4
brew update
brew install gcc-arm-none-eabi-48
```

To build the files. Navigate to the root of the repository and run the following:
```
make
```
##Programming
You'll need to install dfu-util v0.9 or higher. 
####Mac OS
On Mac, the homebrew version is adequate. 
```
brew install dfu-util
```
####Ubuntu
On Ubuntu 14.04, dfu-util must be installed from source. See instructions here: http://dfu-util.sourceforge.net/build.html.

####Uploading code

1. Plug in board to computer via USB.
2. Enable bootloader mode by reseting the board while the bootloader button is held down.
3. Ensure that no other boards are connected that are also in bootloader mode.
4. Run the following to build and upload the code. ```make upload```

##Configuration
To configure the system for your particular LED setup, edit ```led_config.h```. This file contains the i2c address, enable pin, and DAC reference voltage associated with each LED.
