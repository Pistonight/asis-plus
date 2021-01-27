#include <pokemon_swsh.h>
#include <asis+.h>

void homescreen_to_skip1(void){
	asis_dpad_click(DPAD_D);
	asis_delay_ms(100);
	for(int i=0;i<4;i++){
		asis_dpad_click(DPAD_R);
		asis_delay_ms(100);
	}
	asis_click(BTN_A);
	asis_delay_s(1);
	//Inside setting now
	asis_stickL(STK_CTR,STK_D);
	asis_delay_s(2);
	asis_stick_center();
	asis_click(BTN_A);
	asis_delay_ms(200);
	for(int i=0;i<4;i++){
		asis_dpad_click(DPAD_D);
		asis_delay_ms(100);
	}
	asis_click(BTN_A);
	asis_delay_ms(200);
	for(int i=0;i<2;i++){
		asis_dpad_click(DPAD_D);
		asis_delay_ms(100);
	}
	asis_click(BTN_A);
	asis_delay_ms(200);
	//Date and time open now
	asis_dpad_click(DPAD_R);
	asis_delay_ms(100);
	asis_dpad_click(DPAD_R);
	asis_delay_ms(100);
	asis_dpad_click(DPAD_U);
	asis_delay_ms(100);
	asis_stickL(STK_R,STK_CTR);
	asis_delay_s(1);
	asis_stick_center();
	asis_click(BTN_A);
	asis_delay_ms(200);
}

void skip_another1(void){
  asis_click(BTN_A);
  asis_delay_ms(100);
  //Date and time open now
	for(int i=0;i<3;i++){
		asis_dpad_down(DPAD_L);
		asis_delay_ms(50);
		asis_dpad_up();
		asis_delay_ms(50);
	}
  asis_dpad_down(DPAD_U);
	asis_delay_ms(50);
	asis_dpad_up();
	asis_delay_ms(50);
	for(int i=0;i<3;i++){
		asis_dpad_down(DPAD_R);
		asis_delay_ms(50);
		asis_dpad_up();
		asis_delay_ms(50);
	}

  asis_click(BTN_A);
  asis_delay_ms(100);
}