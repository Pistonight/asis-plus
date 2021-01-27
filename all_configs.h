/*
 * Configuration File
 */
#ifndef _ALL_CONFIGS_H_
#define _ALL_CONFIGS_H_

//ASIS Configs
#define ASIS_CLICK_DURATION 160 //Duration of click for asis_click()

//Joystick Adapter Configs
#define JA_TIMER        JA_TIMER_33MS
#define JA_TIMER_33MS   65007
#define JA_TIMER_50MS   64735
#define JA_TIMER_100MS  63935

//Display Adapter Configs
#define DA_DDR_SDA_1 	DDRD
#define DA_DDR_SCL_1 	DDRD
#define DA_PORT_SDA_1 	PORTD
#define DA_PORT_SCL_1 	PORTD
#define DA_PIN_SDA_1 	0
#define DA_PIN_SCL_1 	1
#define DA_DDR_SDA_2 	DDRD
#define DA_DDR_SCL_2 	DDRD
#define DA_PORT_SDA_2 	PORTD
#define DA_PORT_SCL_2 	PORTD
#define DA_PIN_SDA_2 	2
#define DA_PIN_SCL_2 	3
#define DA_CALLBACK_DISPLAY u8x8_d_ssd1306_128x32_univision
#define DA_CALLBACK_CAD     u8x8_cad_ssd13xx_fast_i2c
#define DA_CALLBACK_BYTE    u8x8_byte_sw_i2c

//Hardware Adapter Configs
#define HA_DDR_BTN 			DDRC
#define HA_PORT_BTN 		PORTC
#define HA_PIN_BTN 			PINC
#define HA_PIN_BTN_UP 		5
#define HA_PIN_BTN_DOWN 	0
#define HA_PIN_BTN_LEFT 	3
#define HA_PIN_BTN_RIGHT 	7
#define HA_PIN_BTN_OK 		1
#define HA_DDR_LED 			DDRD
#define HA_PORT_LED 		PORTD
#define HA_PIN_LED 			6


#endif
