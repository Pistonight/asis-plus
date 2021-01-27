
#include <mem_storage.h>
#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>
#include <asis+.h>
void execute_storage(uint16_t last_a_delay){
	int one_frame = 50;
	da_print_str(0,0,"Running");
	asis_delay_ms(500);
	//At compendium, over non-searching item
	asis_press(BTN_Y);
	asis_delay_ms(40);
	asis_release(BTN_Y);
	//asis_delay_ms(32);
	asis_press(BTN_PLUS);
	asis_delay_ms(one_frame);
	asis_release(BTN_PLUS);
	asis_delay_ms(one_frame*5);
	//At inventory, over travel medallion
	asis_click(BTN_A);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_A);
	asis_delay_ms(one_frame*5);
	asis_dpad_click(DPAD_U);
	asis_delay_ms(one_frame*5);
	asis_press(BTN_A);
	asis_delay_ms(one_frame);
	asis_release(BTN_A);
	asis_delay_ms(one_frame*4);
	asis_press(BTN_MINUS);
	asis_delay_ms(one_frame);
	asis_release(BTN_MINUS);
	asis_delay_ms(one_frame*5);
	//At compendium
	asis_click(BTN_L);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_L);
	asis_delay_ms(one_frame*5);
	asis_stickL(STK_CTR,STK_U);
	asis_delay_ms(one_frame*2);
	asis_stick_center();
	asis_delay_ms(one_frame*2);
	//Over quest mark
	asis_click(BTN_Y);
	asis_delay_ms(one_frame*5);
	asis_dpad_click(DPAD_D);
	asis_delay_ms(one_frame*5);
	//A, A
	asis_press(BTN_A);
	asis_delay_ms(100);
	asis_release(BTN_A);
	asis_delay_ms(100);
	asis_press(BTN_A);
	asis_delay_ms(100);
	asis_release(BTN_A);
	asis_delay_ms(100);
	//A, right, A
	
	// asis_press(BTN_A);
	// asis_delay_ms(297-last_a_delay);
	// asis_dpad_down(DPAD_R);
	// asis_release(BTN_A);
	// asis_delay_ms(last_a_delay);
	// asis_press(BTN_A);

	// asis_delay_ms(one_frame*2);
	// asis_release(BTN_A);
	// asis_dpad_up();

	//A, right, A, A, testing
	asis_press(BTN_A);
	asis_delay_ms(267);
	asis_dpad_down(DPAD_R);
	asis_release(BTN_A);
	asis_delay_ms(33);
	asis_press(BTN_A);
	asis_delay_ms(33);
	asis_release(BTN_A);
	asis_delay_ms(33);
	asis_press(BTN_A);
	asis_delay_ms(33);
	asis_release(BTN_A);
	asis_delay_ms(33);
	asis_press(BTN_A);
	asis_delay_ms(33);
	asis_release(BTN_A);
	asis_delay_ms(33);
	asis_press(BTN_A);

	asis_delay_ms(one_frame*2);
	asis_release(BTN_A);
	asis_dpad_up();

	asis_delay_ms(500);
	da_print_str(0,0,"Done   ");
}

void from_world_to_compendium(void){
	//Overworld
	int one_frame = 50;
	asis_click(BTN_R);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_B);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_B);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_MINUS);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_R);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_R);
	asis_delay_ms(one_frame*5);
}

void fix_pin(void){
	int one_frame = 50;
	asis_click(BTN_A);
	asis_delay_ms(one_frame*5);
	asis_dpad_click(DPAD_D);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_A);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_B);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_PLUS);
	asis_delay_ms(one_frame*5);
	asis_dpad_click(DPAD_D);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_A);
	asis_delay_ms(one_frame*5);
}

void fix_memory(void){
	int one_frame = 50;
	asis_dpad_click(DPAD_L);
	asis_delay_ms(one_frame*5);
	asis_dpad_click(DPAD_D);
	asis_delay_ms(one_frame*5);
	asis_click(BTN_A);
	asis_delay_ms(one_frame*5);
}

void mem_storage_main(uint32_t arg){
	uint16_t last_a_delay = (uint16_t) arg;
	da_print_str(0,0,"Mem Store");
	da_print_str(0,1,"Press \nO to run");
	da_print_str(0,2,"Press \nD to exit");
	da_print_str(0,3,"\nU to compend");
	da_print_str(0,4,"\nR\nU>A\nR\nD>dL\nR\nL>B");
	da_print_str(0,5,"\nL\nU to fix pin");
	da_print_str(0,6,"\nL\nD to fix memory");
	da_print_str(0,7,"\nL\nR to skip mem");
	while(1){
		if(ha_is_button_pressed(HA_PIN_BTN_DOWN))
			break;
		else if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			execute_storage(last_a_delay);
		}else if(ha_is_button_pressed(HA_PIN_BTN_UP)){
			from_world_to_compendium();
		}else if(ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
			while(1){
				if(ha_is_button_pressed(HA_PIN_BTN_UP)){
					asis_click(BTN_A);
					break;
				}else if(ha_is_button_pressed(HA_PIN_BTN_DOWN)){
					asis_dpad_click(DPAD_L);
					break;
				}else if(ha_is_button_pressed(HA_PIN_BTN_LEFT)){
					asis_click(BTN_B);
					break;
				}
			}
			
		}else if(ha_is_button_pressed(HA_PIN_BTN_LEFT)){
			while(1){
				if(ha_is_button_pressed(HA_PIN_BTN_UP)){
					fix_pin();
					break;
				}else if(ha_is_button_pressed(HA_PIN_BTN_DOWN)){
					fix_memory();
					break;
				}else if(ha_is_button_pressed(HA_PIN_BTN_RIGHT)){
					asis_click(BTN_X);
					asis_delay_ms(100);
					asis_click(BTN_PLUS);
					asis_delay_ms(100);
					asis_click(BTN_X);
					asis_delay_ms(100);
					asis_click(BTN_PLUS);
					asis_delay_ms(100);
					break;
				}
			}
			
		}
		
		asis_delay_ms(100);
	} 
	da_print_str(0,3,"Bye");
	asis_delay_s(1);
}

