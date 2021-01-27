/*
 * Header for asis+_hw_adapter
 */
#ifndef _ASIS_PLUS_HW_ADAPTER_H_
#define _ASIS_PLUS_HW_ADAPTER_H_

#include <LUFA/Platform/Platform.h>
#include <all_configs.h>

void ha_setup(void);
bool ha_is_button_pressed(uint8_t button);
void ha_led_on(void);
void ha_led_off(void);
void ha_led_toggle(void);

#endif