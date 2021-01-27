/*
 * The ASIS Plus system
 */
#include <asis_joystick_adapter.h>
#include <asis+.h>

#define commit_if_not_multi() if(!asis_multi_enabled) send_packet(&packet);
bool asis_multi_enabled;// Set to true to enable multi mode
asis_packet_t packet;

void asis_setup(void){
  ja_setup();
  asis_reset();
}

void asis_commit(void){
  send_packet(&packet);
  asis_multi_enabled = false;
}

void asis_multi(void){
  asis_multi_enabled = true;
}

void asis_reset(void){
  asis_multi_enabled = false;
  packet.button = BTN_NULL;
  packet.hat    = DPAD_C;
  packet.lx     = STK_CTR;
  packet.ly     = STK_CTR;
  packet.rx     = STK_CTR;
  packet.ry     = STK_CTR;
  send_packet(&packet);
}

void asis_click(uint16_t button){
  asis_multi_enabled = false;
  asis_press(button);
  asis_delay_ms(ASIS_CLICK_DURATION);
  asis_release(button);
}

void asis_dpad_click(uint8_t hat){
  asis_multi_enabled = false;
  asis_dpad_down(hat);
  asis_delay_ms(ASIS_CLICK_DURATION);
  asis_dpad_up();
}

void asis_press(uint16_t button){
  packet.button |= button;
  commit_if_not_multi();
}

void asis_release(uint16_t button){
  packet.button &= ~button;
  commit_if_not_multi();
}

void asis_releaseAll(void){
  packet.button = BTN_NULL;
  commit_if_not_multi();
}

void asis_dpad_down(uint8_t hat){
  packet.hat = hat;
  commit_if_not_multi();
}

void asis_dpad_up(void){
  packet.hat = DPAD_C;
  commit_if_not_multi();
}

void asis_stickL(uint8_t x, uint8_t y){
  packet.lx = x;
  packet.ly = y;
  commit_if_not_multi();
}

void asis_stickR(uint8_t x, uint8_t y){
  packet.rx = x;
  packet.ry = y;
  commit_if_not_multi();
}

void asis_stick(uint8_t lx, uint8_t ly, uint8_t rx, uint8_t ry){
  packet.lx = lx;
  packet.ly = ly;
  packet.rx = rx;
  packet.ry = ry;
  commit_if_not_multi();
}

void asis_delay_ms(uint16_t ms){
	
	while(ms>0){
		_delay_ms(1);
		ms--;
	}
	
}
void asis_delay_s(uint16_t s){
	for(uint16_t i=0;i<s;i++){
		asis_delay_ms(1000);
	}
}
