#include <asis_display_adapter.h>

void test_text(void){
	da_clear();
	da_print_str(0,0,"0123456789ABCDEF");
	da_print_str(0,1,"0123456789ABCDEF");
	da_print_str(0,2,"0123456789ABCDEF");
	da_print_str(0,3,"0123456789ABCDEF");
	da_print_str(0,4,"0123456789ABCDEF");
	da_print_str(0,5,"0123456789ABCDEF");
	da_print_str(0,6,"0123456789ABCDEF");
	da_print_str(0,7,"0123456789ABCDEF");
	da_print_str(0,0,"Hello World!");
	da_print_str(0,1,"Hello World!");
	da_print_str(0,2,"Hello World!");
	da_print_str(0,3,"Hello World!");
	da_print_str(0,4,"Hello World!");
	da_print_str(0,5,"Hello World!");
	da_print_str(0,6,"Hello World!");
	da_print_str(0,7,"Hello World!");
}

void test_buttons(void){
	da_clear();
	da_print_str(0,0,"Test - Buttons");
	da_print_str(0,1,"\nU\nU\nU\nU\nU\nU\nU\nU\nU\nU\nU\nU\nU\nU\nU\nU");
	da_print_str(0,2,"\nD\nD\nD\nD\nD\nD\nD\nD\nD\nD\nD\nD\nD\nD\nD\nD");
	da_print_str(0,3,"\nL\nL\nL\nL\nL\nL\nL\nL\nL\nL\nL\nL\nL\nL\nL\nL");
	da_print_str(0,4,"\nR\nR\nR\nR\nR\nR\nR\nR\nR\nR\nR\nR\nR\nR\nR\nR");
	da_print_str(0,5,"\nO\nO\nO\nO\nO\nO\nO\nO\nO\nO\nO\nO\nO\nO\nO\nO");
}

void test_u8(void){
	da_clear();
	da_print_str(0,0,"Test - U8");
	for(uint8_t i = 0;i<=254;i++){
		da_print_u8l(0,1,i);
		da_print_u8r(16,2,i,3,' ');
		da_print_u8r(16,3,i,3,'_');
	}
	da_print_u8l(0,1,255);
	da_print_u8r(16,2,255,3,' ');
	da_print_u8r(16,3,255,3,'_');
}

void test_u32(void){
	da_clear();
	da_print_str(0,0,"Test - U32");
	for(uint32_t i = 1;i<=2000000000;i*=2){
		da_print_u32l(0,1,i);
		da_print_u32r(16,2,i,10,' ');
		da_print_u32r(16,3,i,10,'_');
		da_print_u32l(0,4,i);
		da_print_u32r(10,5,i,10,' ');
		da_print_u32r(10,6,i,10,'0');
	}
}
int main(void){
	da_setup();
	//test_text();
	test_buttons();
	
	da_print_str(0,0,"Finished.");
	
	while(1);
	return 0;
}