/*
 * Header file for the display adapter
 */
#ifndef _ASIS_DISPLAY_ADAPTER_H
#define _ASIS_DISPLAY_ADAPTER_H

#include <LUFA/Platform/Platform.h>
#include <all_configs.h>

void da_setup(void);
void da_clear(void);
void da_clear_line(uint8_t y);
void da_clear_char(uint8_t x, uint8_t y);
void da_print_char(uint8_t x,uint8_t y,unsigned char c);
void da_print_str(uint8_t x,uint8_t y,char* str);
void da_print_str_len(uint8_t x,uint8_t y,char* str,uint8_t len);
void da_print_u8l(uint8_t x,uint8_t y,uint8_t num);
void da_print_u8r(uint8_t x,uint8_t y,uint8_t num,uint8_t length,char fill);
void da_print_u16l(uint8_t x,uint8_t y,uint16_t num);
void da_print_u16r(uint8_t x,uint8_t y,uint16_t num,uint8_t length,char fill);
void da_print_u32l(uint8_t x,uint8_t y,uint32_t num);
void da_print_u32r(uint8_t x,uint8_t y,uint32_t num,uint8_t length,char fill);

#endif