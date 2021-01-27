//Change to your header file
#include <template_main.h>
#include <asis+.h>
#include <asis_display_adapter.h>

//Change function name here to match header
void template_main(uint32_t arg){
	//Code here
	asis_click(BTN_A);
	da_print_u32l(0,0,arg);
	asis_delay_s(1);
}