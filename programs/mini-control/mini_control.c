
#include <mini_control.h>
#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>
#include <asis+.h>

void first_ok(void){
	asis_delay_ms(100);
	da_print_str(0,4,"\nR>A      ");
	da_print_str(0,5,"\nD>B      ");
	da_print_str(0,6,"\nU>X      ");
	da_print_str(0,7,"\nL>Y      ");
	da_clear_line(1);
	da_clear_line(2);
	da_clear_line(3);
	while(1){
		if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_LEFT)){
			asis_click(BTN_Y);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
			asis_click(BTN_A);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_UP)){
			asis_click(BTN_X);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_DOWN)){
			asis_click(BTN_B);
			return;
		}
		asis_delay_ms(100);
	}
}

void first_up(void){
	asis_delay_ms(100);
	da_print_str(0,4,"\nR>r stick");
	da_print_str(0,5,"\nD>-      ");
	da_print_str(0,6,"\nU>+      ");
	da_print_str(0,7,"\nL>l stick");
	da_clear_line(1);
	da_clear_line(2);
	da_clear_line(3);
	while(1){
		if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_LEFT)){
			asis_click(BTN_LSTK);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
			asis_click(BTN_RSTK);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_UP)){
			asis_click(BTN_PLUS);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_DOWN)){
			asis_click(BTN_MINUS);
			return;
		}
		asis_delay_ms(100);
	}
}

void first_down(void){
	asis_delay_ms(100);
	da_print_str(0,4,"\nR>dpad R ");
	da_print_str(0,5,"\nD>dpad D ");
	da_print_str(0,6,"\nU>dpad U ");
	da_print_str(0,7,"\nL>dpad L ");
	da_clear_line(1);
	da_clear_line(2);
	da_clear_line(3);
	while(1){
		if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_LEFT)){
			asis_dpad_click(DPAD_L);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
			asis_dpad_click(DPAD_R);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_UP)){
			asis_dpad_click(DPAD_U);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_DOWN)){
			asis_dpad_click(DPAD_D);
			return;
		}
		asis_delay_ms(100);
	}
}

void first_left(void){
	asis_delay_ms(100);
	da_print_str(0,4,"\nR>R     ");
	da_print_str(0,5,"\nD>SHARE ");
	da_print_str(0,6,"\nU>HOME  ");
	da_print_str(0,7,"\nL>L     ");
	da_clear_line(1);
	da_clear_line(2);
	da_clear_line(3);
	while(1){
		if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_LEFT)){
			asis_click(BTN_L);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
			asis_click(BTN_R);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_UP)){
			asis_click(BTN_HOME);
			return;
		}else if(ha_is_button_pressed(HA_PIN_BTN_DOWN)){
			asis_click(BTN_SHARE);
			return;
		}
		asis_delay_ms(100);
	}
}


int first_right(void){
	asis_delay_ms(100);
	da_print_str(0,4,"\nR>ZR    ");
	da_print_str(0,5,"\nD>      ");
	da_print_str(0,6,"\nU>      ");
	da_print_str(0,7,"\nL>ZL    ");
	da_clear_line(1);
	da_clear_line(2);
	da_clear_line(3);
	while(1){
		if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			return 1;
		}else if(ha_is_button_pressed(HA_PIN_BTN_LEFT)){
			asis_click(BTN_ZL);
			return 0;
		}else if(ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
			asis_click(BTN_ZR);
			return 0;
		}else if(ha_is_button_pressed(HA_PIN_BTN_UP)){
			asis_click(BTN_HOME);
			return 0;
		}else if(ha_is_button_pressed(HA_PIN_BTN_DOWN)){
			asis_click(BTN_SHARE);
			return 0;
		}
		asis_delay_ms(100);
	}
}

void mini_control_main(uint32_t arg){
	da_print_str(0,0,"Mini Control");
	

	while(1){
		da_print_str(0,1,"\nO\nR>A\nO\nD>B\nO\nU>X\nO\nL>Y");
		da_print_str(0,2,"\nL\nL>L \nL\nR>R");
		da_print_str(0,3,"\nR\nL>ZL \nR\nR>ZR");
		da_print_str(0,4,"\nU\nD>-\nU\nU>+\nU\nL>l\nU\nR>r");
		da_print_str(0,5,"\nL\nU>Home \nL\nD>Share");
		da_print_str(0,6,"\nD any>Dpad");
		da_print_str(0,7,"\nR\nO to exit");
		if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			first_ok();
		}else if(ha_is_button_pressed(HA_PIN_BTN_LEFT))
			first_left();
		else if(ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
			if(first_right()){
				break;
			}
		}else if(ha_is_button_pressed(HA_PIN_BTN_UP))
			first_up();
		else if(ha_is_button_pressed(HA_PIN_BTN_DOWN))
			first_down();
		
		asis_delay_ms(100);
	} 
	da_print_str(0,0,"Bye          ");
	asis_delay_s(1);
}