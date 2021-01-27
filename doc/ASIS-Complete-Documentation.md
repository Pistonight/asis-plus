# Auto Switch Input System+ Complete Documentation
### Table of Contents
 - [Introduction](#introduction)
 - [Joystick Adapter](#joystick-adapter)
 - [Display Adapter](#display-adapter)
 - [Hardware Adapter](#hardware-adapter)
 - [Framework](#framework)
 - [ASIS Constants](#asis-constants)
 - [ASIS Modes](#asis-modes)
 - [ASIS Functions](#asis-functions)

## Introduction
This documentation serves as a guide to use the ASIS+ tool. The ASIS+ tool consists of a hardware component and many software components
### Hardware Prerequisite
You must have a Teensy 2.0 ++ and 2 i2C LCD displays. Follow the diagram to connect them. The pins can be configured in `all_configs.h`

### Software
ASIS+ framework and programs are all in C. There are 3 software components:

1. Joystick Adapter (JA)
2. Display Adapter (DA)
3. Hardware Adapter (HA)

JA is used to communicate with the console. Programmers do not need to interact direct with JA. DA is used to display text on the LCDs. HA is used to handle button presses.

## Joystick Adapter
The Joystick Adapter is used to send controller inputs to the console. This is handled by interrupts. You can config the frequency of sending input updates in `all_configs.h` by setting `JA_TIMER` to one of the pre-calculated values or calculate your own value.
```
//Joystick Adapter Configs
#define JA_TIMER        JA_TIMER_33MS
#define JA_TIMER_33MS   65007
#define JA_TIMER_50MS   64735
#define JA_TIMER_100MS  63935
```

The values are calculated with this formula: `JA_TIMER = 65535 - (MilliSeconds * MHzFreq)`. The default frequency is 16MHz.

## Display Adapter
The Display Adapter is used to display text on the LCDs. It has an internal buffer to keep track of the displayed text, and only necessary updates are sent to the LCDs to speed up the display. The [u8g2](https://github.com/olikraus/u8g2) library is used for the implementation 

### DA Constants
The DA constants are defined in `all_configs.h`. Use them to setup the pin configuration and u8x8 callbacks

### DA Functions

##### void da_setup(void)
Setup the display adapter. This is called by ASIS+ on start up. Programs should not call this.
##### void da_clear(void)
Clears the entire screen
##### void da_clear_line(uint8_t y);
Clear one line. The setup has 2 LCDs, each with 4 lines. The lines are numbered 0-7.
##### void da_clear_char(uint8_t x, uint8_t y);
Clear one character. The `y` position is the line (or row). The `x` position is the char count (or column). Each LCD has 16 chars per line and they are numbered 0-15
##### void da_print_char(uint8_t x,uint8_t y,unsigned char c);
Print the char `c` at `x` and `y`
##### void da_print_str(uint8_t x,uint8_t y,char* str);
Print the null terminated string starting at `x` and `y`. If the string is not null terminated, a max of 16 characters will be printed
##### void da_print_str_len(uint8_t x,uint8_t y,char* str,uint8_t len);
Print the null terminated string starting at `x` and `y`. If the string is not null terminated, a max of `len` characters will be printed
##### void da_print_u8l(uint8_t x,uint8_t y,uint8_t num);
Print an unsigned 8-bit integer, left-aligned at `x` and `y`
##### void da_print_u8r(uint8_t x,uint8_t y,uint8_t num,uint8_t length,char fill);
Print an unsigned 8-bit integer, right-algned at `x` and `y`. The field is `length` long, and spaces are filled with `fill` if the number is not long enough.
##### void da_print_u16l(uint8_t x,uint8_t y,uint16_t num);
Print an unsigned 16-bit integer, left-aligned
##### void da_print_u16r(uint8_t x,uint8_t y,uint16_t num,uint8_t length,char fill);
Print an unsigned 16-bit integer, right-aligned
##### void da_print_u32l(uint8_t x,uint8_t y,uint32_t num);
Print an unsigned 32-bit integer, left-aligned
##### void da_print_u32r(uint8_t x,uint8_t y,uint32_t num,uint8_t length,char fill);
Print an unsigned 32-bit integer, right-aligned

### Special Characters
There are 5 special characters that are escaped with `\n` by the Display Adapter. They are represented by 2 bytes in the string, but only counts as 1 character (i.e. a string with 5 normal characters and 2 special characters takes 10 bytes, but has length 7)

The special characters are summarized below

| Character | Escape Sequence |
|-----------|-----------------|
| Up Button Icon | \nU |
| Down Button Icon | \nD |
| Right Button Icon | \nR |
| Left Button Icon | \nL |
| OK Button Icon | \nO |

## Hardware Adapter
The Hardware Adapter is used to detect button presses and set LED.

### HA Constants
The HA constants are defined in `all_configs.h`. Use them to assign button pins and LED pins. The Teensy 2.0 ++ has a built in LED connected to D6.

### HA Functions
##### void ha_setup(void);
Setup the Hardware Adapter. This is called by ASIS+ at start up. Programs must not call this.
##### bool ha_is_button_pressed(uint8_t button);
Check if a button is pressed. Use one of the `HA_PIN_BTN_xxx` for `button`
##### void ha_led_on(void);
Turn on the LED
##### void ha_led_off(void);
Turn off the LED
##### void ha_led_toggle(void);
Toggle the LED

## Framework
ASIS+ has a built-in framework to support loading multiple programs in a single binary file. Programs are loaded through hooks. If you want to make your own program, look up `programs/template`. 

Programs use DA, HA and ASIS functions to make dynamic programs that automates controller inputs. For DA and HA functions, refer to [DA Functions](#da-functions) and [HA Functions](#ha-functions).

## ASIS Constants
ASIS defines button, D-pad and stick constants for use with its functions.

#### Buttons
Button constants are for functions with a button argument. Button press can be combined with add(+) or or(|)

| Const Name | HEX | Description |
|------------|-----|-------------|
| BTN_NULL    | 0x0000 | No Button
| BTN_Y       | 0x0001 | Y Button
| BTN_B       | 0x0002 | B Button
| BTN_A       | 0x0004 | A Button
| BTN_X       | 0x0008 | X Button
| BTN_L       | 0x0010 | L Button
| BTN_R       | 0x0020 | R Button
| BTN_ZL      | 0x0040 | ZL Button
| BTN_ZR      | 0x0080 | ZR Button
| BTN_MINUS   | 0x0100 | MINUS Button
| BTN_PLUS    | 0x0200 | PLUS Button
| BTN_LSTK    | 0x0400 | Left stick click
| BTN_RSTK    | 0x0800 | Right stick click
| BTN_HOME    | 0x1000 | Home button. 
| BTN_SHARE   | 0x2000 | Capture button

### D-pad 
These constants are for D-pad arguments. Note that D-pad inputs are different than joy-con D-pad buttons. ASIS is detected an a wired controller that does not have joy-con buttons.

| Const Name | HEX | Description |
|------------|-----|-------------|
| DPAD_U     | 0x01 | D-pad up input
| DPAD_UR    | 0x01 | D-pad up and right
| DPAD_R     | 0x02 | D-pad right
| DPAD_DR    | 0x03 | D-pad down and right
| DPAD_D     | 0x04 | D-pad down
| DPAD_DL    | 0x05 | D-pad down and left
| DPAD_L     | 0x06 | D-pad left
| DPAD_UL    | 0x07 | D-pad up and left
| DPAD_C     | 0x08 | No D-pad input

### Stick Input
These constants are convienient to use in stick functions. Each analog stick outputs values from `0x00` to `0xFF`. 

| Const Name | Hex | Description |
|------------|-----|-------------|
| STK_MAX, STK_R, STK_D    | 0xFF| Max position of the stick
| STK_MIN, STK_L, STK_U    | 0x00| Min position of the stick
| STK_CTR      | 0x80| Center position of the stick

## ASIS Modes
ASIS supports 2 mode of operations: single-command and multi-command.
#### Single Command Mode
In single command mode, each function call will immediately update the controller state and the updated state will be sent to the console on the next interrupt.
#### Multi Command Mode
In multi command mode, each function call only updates the internal controller state, but does not send the updated state to the console. When all updates are finished, it will then commit the update.
#### Switch Between Modes
Use `asis_multi()` to enter multi command mode, and use `asis_commit()` to commit the updates. After committing, the mode is automatically switched to single command mode.

## ASIS Functions
##### void asis_setup(void);
Setup ASIS. This is called by ASIS framework upon start up. Programs must not call this.
##### void asis_commit(void);
Commit all updates and switch to single command mode.
##### void asis_multi(void);
Switch to multi command mode
##### void asis_reset(void);
Release all buttons and D pad inputs. Set both sticks to center position.
##### void asis_click(uint16_t button);
Click the button (press and release). The duration the button is held is configurable in `all_configs.h` (`ASIS_CLICK_DURATION`). The value is in milliseconds.
##### void asis_press(uint16_t button);
Press the button
##### void asis_release(uint16_t button);
Release the button
##### void asis_releaseAll(void);
Release all buttons
##### void asis_dpad_down(uint8_t hat);
Press D pad
##### void asis_dpad_up(void);
Release D pad
##### void asis_dpad_click(uint8_t hat);
Similar to button clicks, this function clicks the D pad. The duration is configurable by the same constant.
##### void asis_stick_center();
This is macro. It centers both stick by calling `asis_stick()`
##### void asis_stickL(uint8_t x,uint8_t y);
Set the position of the left stick. This does not change the position of the right stick
##### void asis_stickR(uint8_t x,uint8_t y);
Set the position of the right stick. This does not change the position of the left stick
##### void asis_stick(uint8_t lx,uint8_t ly,uint8_t rx,uint8_t ry);
Set the position of both sticks
##### void asis_delay_ms(uint16_t ms);
Delay for `ms` milliseconds
##### void asis_delay_s(uint16_t s);
Delay for `s` seconds


