#include <pokemon_swsh.h>
#include <asis+.h>
#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>

void den_skip1(void){
	//In Front of Den
	asis_click(BTN_A);
	asis_delay_ms(800);
	asis_click(BTN_B);
	asis_delay_s(3);
	asis_click(BTN_A);
	asis_delay_s(2);
	asis_click(BTN_A);
	asis_delay_s(4);
	asis_click(BTN_HOME);
	asis_delay_s(2);
	//Home Screen
	homescreen_to_skip1();
	asis_click(BTN_HOME);
	asis_delay_s(2);
	//Home Screen
	asis_click(BTN_HOME);
	asis_delay_s(2);
	//In Den
	asis_click(BTN_B);
	asis_delay_s(2);
	asis_click(BTN_A);
	asis_delay_s(5);
}

void swsh_farm_watt_main(uint32_t days){
	while(true){
		da_clear();
		da_print_str(0,0,"Count");
		da_print_str(0,2,"Total");
		da_print_u32r(16,3,days,10,' ');
		da_print_str(0,4,"Hold \nO to quit");
		da_print_str(0,5,"after skipping");
		da_print_str(0,6,"and returning");
		da_print_str(0,7,"to game");
		for(uint32_t i=0;i<days;i++){
			da_print_u32r(16,1,i,10,' ');
			den_skip1();
			if(ha_is_button_pressed(HA_PIN_BTN_OK)){
				break;
			}
		}
		da_clear();
		da_print_str(0,1,"Done");
		da_print_str(0,4,"\nU\nD\nL\nR to redo");
		da_print_str(0,5,"\nO to quit");
		bool quit=false;
		while(true){
			if(ha_is_button_pressed(HA_PIN_BTN_OK)){
				quit=true;
				break;
			}else if(ha_is_button_pressed(HA_PIN_BTN_UP)||
			ha_is_button_pressed(HA_PIN_BTN_DOWN)||
			ha_is_button_pressed(HA_PIN_BTN_LEFT)||
			ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
				break;
			}
		}
		if(quit)break;
	}
	
  
}