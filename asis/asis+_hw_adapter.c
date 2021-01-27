/*
 * Hardware Adapter.
 */
#include <asis+_hw_adapter.h>

void ha_setup(void){
  //Set pin direction as input
  HA_DDR_BTN &= ~(1 << HA_PIN_BTN_UP);
  HA_DDR_BTN &= ~(1 << HA_PIN_BTN_DOWN);
  HA_DDR_BTN &= ~(1 << HA_PIN_BTN_LEFT);
  HA_DDR_BTN &= ~(1 << HA_PIN_BTN_RIGHT);
  HA_DDR_BTN &= ~(1 << HA_PIN_BTN_OK);

  //Enable pullup resistor
  HA_PORT_BTN |= (1 << HA_PIN_BTN_UP);
  HA_PORT_BTN |= (1 << HA_PIN_BTN_DOWN);
  HA_PORT_BTN |= (1 << HA_PIN_BTN_LEFT);
  HA_PORT_BTN |= (1 << HA_PIN_BTN_RIGHT);
  HA_PORT_BTN |= (1 << HA_PIN_BTN_OK);
  
  HA_DDR_LED |= (1 << HA_PIN_LED);
  ha_led_off();
}

bool ha_is_button_pressed(uint8_t button){
  //Button is connected to gnd when pushed down
  if (HA_PIN_BTN & (1<<button)){
    return false;
  }else{
    return true;
  }
}

void ha_led_on(void){
  HA_PORT_LED |= (1 << HA_PIN_LED);
}
void ha_led_off(void){
  HA_PORT_LED &= ~(1 << HA_PIN_LED);
}
void ha_led_toggle(void){
  HA_PORT_LED ^= (1 << HA_PIN_LED);
}


