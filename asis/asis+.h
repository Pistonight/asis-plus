/*
 * Header for asis+.c
 */
#ifndef _ASIS_PLUS_H_
#define _ASIS_PLUS_H_

#include <LUFA/Platform/Platform.h>
#include <all_configs.h>

//Buttons
#define BTN_NULL  0x0000
#define BTN_Y     0x0001
#define BTN_B     0x0002
#define BTN_A     0x0004
#define BTN_X     0x0008
#define BTN_L     0x0010
#define BTN_R     0x0020
#define BTN_ZL    0x0040
#define BTN_ZR    0x0080
#define BTN_MINUS 0x0100
#define BTN_PLUS  0x0200
#define BTN_LSTK  0x0400
#define BTN_RSTK  0x0800
#define BTN_HOME  0x1000
#define BTN_SHARE 0x2000
//D-pad (HAT)
#define DPAD_U  0x00
#define DPAD_UR 0x01
#define DPAD_R  0x02
#define DPAD_DR 0x03
#define DPAD_D  0x04
#define DPAD_DL 0x05
#define DPAD_L  0x06
#define DPAD_UL 0x07
#define DPAD_C  0x08
//Sticks
#define STK_MAX 0xFF
#define STK_MIN 0x00
#define STK_U   STK_MIN
#define STK_L   STK_MIN
#define STK_D   STK_MAX
#define STK_R   STK_MAX
#define STK_CTR 0x80

//Packet type
typedef struct{
  uint16_t button;
  uint8_t hat;
  uint8_t lx;
  uint8_t ly;
  uint8_t rx;
  uint8_t ry;
} asis_packet_t;

//Setup
void asis_setup(void);
//Send (commit) the current packet, use with multi
void asis_commit(void);
//Disable auto-commit until the next commit
void asis_multi(void);

//Reset controller state
void asis_reset(void);
//Buttons and d-pad
//asis_click waits between press and release. Wait time is configurable in all_configs.h
//asis_click automatically enables auto-commit
void asis_click(uint16_t button);
void asis_press(uint16_t button);
void asis_release(uint16_t button);
void asis_releaseAll(void);
void asis_dpad_down(uint8_t hat);
void asis_dpad_up(void);
void asis_dpad_click(uint8_t hat);
//Stick
//Reset both sticks to center (inline function)
#define asis_stick_center() asis_stick(STK_CTR,STK_CTR,STK_CTR,STK_CTR);
//Move single stick
void asis_stickL(uint8_t x,uint8_t y);
void asis_stickR(uint8_t x,uint8_t y);
//Move both sticks
void asis_stick(uint8_t lx,uint8_t ly,uint8_t rx,uint8_t ry);

void asis_delay_ms(uint16_t ms);
void asis_delay_s(uint16_t s);

#endif
