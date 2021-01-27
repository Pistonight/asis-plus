#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>
#include <asis+.h>

void test_buttons(void){
	da_print_str(0,0,"Test - Buttons");
	da_print_str(0,1,"A    ");
	asis_click(BTN_A);
	asis_delay_ms(100);
	da_print_str(0,1,"B    ");
	asis_click(BTN_B);
	asis_delay_ms(100);
	da_print_str(0,1,"X    ");
	asis_click(BTN_X);
	asis_delay_ms(100);
	da_print_str(0,1,"Y    ");
	asis_click(BTN_Y);
	asis_delay_ms(100);
	da_print_str(0,1,"L    ");
	asis_click(BTN_L);
	asis_delay_ms(100);
	da_print_str(0,1,"R    ");
	asis_click(BTN_R);
	asis_delay_ms(100);
	da_print_str(0,1,"ZL   ");
	asis_click(BTN_ZL);
	asis_delay_ms(100);
	da_print_str(0,1,"ZR   ");
	asis_click(BTN_ZR);
	asis_delay_ms(100);
	da_print_str(0,1,"MINUS");
	asis_click(BTN_MINUS);
	asis_delay_ms(100);
	da_print_str(0,1,"PLUS ");
	asis_click(BTN_PLUS);
	asis_delay_ms(100);
	da_print_str(0,1,"LSTK ");
	asis_click(BTN_LSTK);
	asis_delay_ms(100);
	da_print_str(0,1,"RSTK ");
	asis_click(BTN_RSTK);
	asis_delay_ms(100);
}

void test_stick(void){
	da_print_str(0,0,"Test - Sticks");
	asis_stick_center();
	da_print_str(0,1,"L");
	for(int x=0;x<256;x+=5){
		for(int y=0;y<256;y+=5){
			da_print_u8l(0,2,x);
			da_print_u8l(4,2,y);
			asis_stickL(x,y);
			asis_delay_ms(10);
		}
	}
	da_print_str(0,1,"R");
	for(int x=0;x<256;x+=5){
		for(int y=0;y<256;y+=5){
			da_print_u8l(0,2,x);
			da_print_u8l(4,2,y);
			asis_stickR(x,y);
			asis_delay_ms(10);
		}
	}
	asis_stick_center();
}

void test_dpad(void){
	da_print_str(0,0,"Test - D pad");
	asis_dpad_up();
	asis_delay_ms(100);
  asis_dpad_click(DPAD_U);
  asis_delay_ms(100);
  asis_dpad_click(DPAD_UR);
  asis_delay_ms(100);
  asis_dpad_click(DPAD_R);
  asis_delay_ms(100);
  asis_dpad_click(DPAD_DR);
  asis_delay_ms(100);
  asis_dpad_click(DPAD_D);
  asis_delay_ms(100);
  asis_dpad_click(DPAD_DL);
  asis_delay_ms(100);
  asis_dpad_click(DPAD_L);
  asis_delay_ms(100);
  asis_dpad_click(DPAD_UL);
  asis_delay_ms(100);
  asis_dpad_up();
}

void normal_test(void){
	while(1){
		test_buttons();
		test_dpad();
		test_stick();
		asis_delay_ms(1000);
	}
}

void switch_test(void){
	asis_click(BTN_L | BTN_R);
	asis_delay_ms(500);
	asis_click(BTN_L | BTN_R);
	asis_delay_ms(500);
  asis_click(BTN_L | BTN_R);
  asis_delay_s(1);
  asis_click(BTN_A);
  asis_delay_s(1);
  asis_click(BTN_B);
  asis_delay_s(1);
  
  asis_dpad_click(DPAD_R);
  asis_delay_ms(100);
  asis_click(BTN_A);
  asis_delay_s(1);
  for(int i=0;i<12;i++){
     asis_dpad_click(DPAD_D);
  asis_delay_ms(100);
  }
  asis_click(BTN_A);
  asis_delay_ms(500);
  asis_dpad_down(DPAD_D);
  asis_delay_s(2);
  asis_dpad_up();
  asis_delay_ms(100);
  asis_dpad_click(DPAD_U);
  asis_delay_ms(500);
  asis_click(BTN_A);
  asis_delay_ms(500);
  asis_click(BTN_A);
  asis_delay_s(1);
  da_print_str(0,2,"test starts ");
  //Test Start here
  test_buttons();
  test_dpad();

  //Last test home and capture
  asis_click(BTN_SHARE);
  asis_delay_ms(500);
  asis_click(BTN_HOME);
  asis_delay_s(2);
}
int main(void){
	ha_setup();
	asis_setup();
	da_setup();
	
	switch_test();
	while(1);
	
}
