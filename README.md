# Automatic Switch Input System+ (ASIS+)

This is a framework that runs on Teensy 2.0++ that allows you to make automated controllers for the Switch. It is a newer version of [ASIS](https://github.com/iTNTPiston/auto-switch-input)

## Credit 
The original [ASIS](https://github.com/iTNTPiston/auto-switch-input) is inspired by the work done by [Automatically throws snowballs in The Legend of Zelda: Breath of the Wild by emulating a controller on a Teensy++ v2.0](https://github.com/bertrandom/snowball-thrower).,[Splatoon post printer](https://github.com/shinyquagsire23/Switch-Fightstick), and [original discovery](https://github.com/progmem/Switch-Fightstick).

## New Features
The original ASIS is a simple framework for sending controller inputs. ASIS+, on the other hand, integrates both hardware and software. It allows multiple programs to be loaded and has a simple OS to switch between programs.

## Dependencies
ASIS depends on LUFA and u8g2, which are included as submodules.

Then, follow one of the instructions below to setup the environment
 - Linux Users: [Instructions](doc/Step1-Setup-Linux.md)
 - MacOS Users: [Instructions](doc/Step1-Setup-MacOS.md) **This is currently unavailable. If you know how to run avr-gcc on a mac, please contribute!**
 - Windows Users: [Instructions](doc/Step1-Setup-Windows.md)

## Build and Flash
1. Build the project with `make`
2. You want to flash `build/asis+_main.hax`

If you are using a Teensy like me, you can find the tool and instructions on their [website](https://www.pjrc.com/teensy/loader.html). 

## Documentation

#### [Complete ASIS Documentation](/doc/ASIS-Complete-Documentation.md)



