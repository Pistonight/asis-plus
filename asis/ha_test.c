#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>

void test_button(int y,uint8_t button){
	if(ha_is_button_pressed(button)){
		da_print_str(15,y,"X");
	}else{
		da_print_str(15,y," ");
	}
}

int main(void){
	da_setup();
	ha_setup();
	
	while(1){
		da_print_str(0,0,"Hardware Test");
		da_print_str(0,1,"0. Button - U");
		da_print_str(0,2,"1. Button - D");
		da_print_str(0,3,"2. Button - L");
		da_print_str(0,4,"3. Button - R");
		da_print_str(0,5,"4. Button - O");
		test_button(1,HA_PIN_BTN_UP);
		test_button(2,HA_PIN_BTN_DOWN);
		test_button(3,HA_PIN_BTN_LEFT);
		test_button(4,HA_PIN_BTN_RIGHT);
		test_button(5,HA_PIN_BTN_OK);
		_delay_ms(10);
	}
}