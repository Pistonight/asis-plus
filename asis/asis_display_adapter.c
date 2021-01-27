/*
 * ASIS Display Adapter
 */
#include <asis_display_adapter.h>
#include <u8x8.h>
#include <u8x8_avr.h>

unsigned char display_buffer[256];
uint8_t empty_tile[8]={0,0,0,0,0,0,0,0};
uint8_t down_button_tile[8]={0x7e,0x81,0x81,0xe1,0xe1,0x81,0x81,0x7e};
uint8_t up_button_tile[8]={0x7e,0x81,0x81,0x87,0x87,0x81,0x81,0x7e};
uint8_t left_button_tile[8]={0x7e,0x99,0x99,0x81,0x81,0x81,0x81,0x7e};
uint8_t right_button_tile[8]={0x7e,0x81,0x81,0x81,0x81,0x99,0x99,0x7e};
uint8_t ok_button_tile[8]={0x7e,0x81,0x81,0x81,0xb1,0xb1,0x81,0x7e};

bool is_da_setup = false;

void setup_pins_1(void){
  DA_DDR_SDA_1 |= _BV(DA_PIN_SDA_1);
  DA_DDR_SCL_1 |= _BV(DA_PIN_SCL_1);
}

void setup_pins_2(void){
  DA_DDR_SDA_2 |= _BV(DA_PIN_SDA_2);
  DA_DDR_SCL_2 |= _BV(DA_PIN_SCL_2);
}

void set_scl_1(uint8_t signal){
  if(signal)
    DA_PORT_SCL_1 |= (1 << DA_PIN_SCL_1);
  else
    DA_PORT_SCL_1 &= ~(1 << DA_PIN_SCL_1);
}

void set_scl_2(uint8_t signal){
  if(signal)
    DA_PORT_SCL_2 |= (1 << DA_PIN_SCL_2);
  else
    DA_PORT_SCL_2 &= ~(1 << DA_PIN_SCL_2);
}

void set_sda_1(uint8_t signal){
  if(signal)
    DA_PORT_SDA_1 |= (1 << DA_PIN_SDA_1);
  else
    DA_PORT_SDA_1 &= ~(1 << DA_PIN_SDA_1);
}

void set_sda_2(uint8_t signal){
  if(signal)
    DA_PORT_SDA_2 |= (1 << DA_PIN_SDA_2);
  else
    DA_PORT_SDA_2 &= ~(1 << DA_PIN_SDA_2);
}

uint8_t gpio_delay_cb_1(u8x8_t* u8x8, uint8_t msg, uint8_t arg_int, void* arg_ptr){
  if (u8x8_avr_delay(u8x8, msg, arg_int, arg_ptr))
    return 1;
	switch (msg) {
    case U8X8_MSG_GPIO_I2C_CLOCK: set_scl_1(arg_int); break;
	  case U8X8_MSG_GPIO_I2C_DATA:  set_sda_1(arg_int); break;
    default:
      u8x8_SetGPIOResult(u8x8, 1);
      break;
	}
  return 1;
}

uint8_t gpio_delay_cb_2(u8x8_t* u8x8, uint8_t msg, uint8_t arg_int, void* arg_ptr){
  if (u8x8_avr_delay(u8x8, msg, arg_int, arg_ptr))
    return 1;
	switch (msg) {
    case U8X8_MSG_GPIO_I2C_CLOCK: set_scl_2(arg_int); break;
	  case U8X8_MSG_GPIO_I2C_DATA:  set_sda_2(arg_int); break;
    default:
      u8x8_SetGPIOResult(u8x8, 1);
      break;
	}
  return 1;
}

u8x8_t lcd_1;
u8x8_t lcd_2;

void setup_u8x8(u8x8_t* u8x8, u8x8_msg_cb gpio_cb){
  u8x8_Setup(u8x8,
      DA_CALLBACK_DISPLAY,
      DA_CALLBACK_CAD    ,
      DA_CALLBACK_BYTE   ,
      gpio_cb);
	u8x8_InitDisplay(u8x8);
	u8x8_SetPowerSave(u8x8,0);
	u8x8_SetFont(u8x8, u8x8_font_amstrad_cpc_extended_r);
  u8x8_ClearDisplay(u8x8);
  
}

void da_setup(void){
  setup_pins_1();
  setup_pins_2();
  setup_u8x8(&lcd_1, gpio_delay_cb_1);
  setup_u8x8(&lcd_2, gpio_delay_cb_2);
  for(int i=0;i<256;i++){
	  display_buffer[i] = 0;
  }
  is_da_setup = true;
}

void da_clear(void){
	for(int y=0;y<8;y++){
		da_clear_line(y);
	}
}

void da_clear_line(uint8_t y){
  for(int x=0;x<16;x++){
	  da_clear_char(x,y);
  }
}

void da_clear_char(uint8_t x,uint8_t y){
	da_print_char(x,y,0);	
}


void print_char_helper(u8x8_t* u8x8, uint8_t x,uint8_t y, char c){
	if(!is_da_setup)return;
	if(c==0){
		u8x8_DrawTile(u8x8, x, y, 1, empty_tile);
	}else if(c==128){
		u8x8_DrawTile(u8x8, x, y, 1, up_button_tile);
	}else if(c==129){
		u8x8_DrawTile(u8x8, x, y, 1, down_button_tile);
	}else if(c==130){
		u8x8_DrawTile(u8x8, x, y, 1, left_button_tile);
	}else if(c==131){
		u8x8_DrawTile(u8x8, x, y, 1, right_button_tile);
	}else if(c==132){
		u8x8_DrawTile(u8x8, x, y, 1, ok_button_tile);
	}else{
		u8x8_DrawGlyph(u8x8, x, y, (uint8_t) c);
	}
}

void da_print_char(uint8_t x,uint8_t y,unsigned char c){
	unsigned char buf = c==' '? 0:c;
	int i = (y<<4)+x;
	if(display_buffer[i]!=buf){
		
		if(y < 4){
			print_char_helper(&lcd_1, x, y, c);
		}else{
			print_char_helper(&lcd_2, x, y-4,c);
		}
		display_buffer[i]=buf;
	}
  
}

void da_print_str(uint8_t x,uint8_t y, char* str){
  da_print_str_len(x,y,str,16);
}

void da_print_str_len(uint8_t x,uint8_t y,char* str,uint8_t len){
	int i=0;
	int j=0;
  for(;i<len && str[j]!='\0';i++,j++){
	  if(str[j]=='\n'){
		  j++;
		  switch(str[j]){
			  case 'U':
			  str[j]=128;
			  break;
			  case 'D':
			  str[j]=129;
			  break;
			  case 'L':
			  str[j]=130;
			  break;
			  case 'R':
			  str[j]=131;
			  break;
			  case 'O':
			  str[j]=132;
			  break;
		  }
	  }
    da_print_char(x+i,y,str[j]);
  }
}

uint8_t u8toa_helper(char* buf, uint8_t num){
  if(num==0){
    buf[0] = '0';
    return 1;
  }
  uint8_t div = 100;
  int i = 0;
  while(true){
    int d = num/div;
    num = num % div;
    div/=10;
    if(d>0){
      buf[i++] = '0'+d;
      break;
    }
  }
  while(div!=0){
    int d = num/div;
    num = num % div;
    div/=10;
    buf[i++] = '0'+d;
  }
  return i;
}

uint8_t u32toa_helper(char* buf, uint32_t num){
  if(num<0xFF){
    return u8toa_helper(buf, (uint8_t) num);
  }
  if(num==0){
    buf[0] = '0';
    return 1;
  }
  uint32_t div = 1000000000;
  int i = 0;
  while(true){
    int d = num/div;
    num = num % div;
    div/=10;
    if(d>0){
      buf[i++] = '0'+d;
      break;
    }
  }
  while(div!=0){
    int d = num/div;
    num = num % div;
    div/=10;
    buf[i++] = '0'+d;
  }
  return i;
}

void da_print_u8l(uint8_t x,uint8_t y,uint8_t num){
  static char buf[3];
  uint8_t len = u8toa_helper(buf, num);
  da_print_str_len(x,y,buf,len);
  for(int i = len;i<3;i++)
    da_print_char(x+i,y,' ');
}

void da_print_u8r(uint8_t x,uint8_t y,uint8_t num,uint8_t length,char fill){
  static char buf[3];
  uint8_t len = u8toa_helper(buf, num);
  for(int i = length;i>len;i--)
    da_print_char(x-i,y,fill);
  da_print_str_len(x-len,y,buf,len);
}

void da_print_u16l(uint8_t x,uint8_t y,uint16_t num){
  static char buf[5];
  uint8_t len = u32toa_helper(buf, (uint32_t)num);
  da_print_str_len(x,y,buf,len);
  for(int i = len;i<5;i++)
    da_print_char(x+i,y,' ');
}

void da_print_u16r(uint8_t x,uint8_t y,uint16_t num,uint8_t length, char fill){
  static char buf[5];
  uint8_t len = u32toa_helper(buf,(uint32_t) num);
  for(int i = length;i>len;i--)
    da_print_char(x-i,y,fill);
  da_print_str_len(x-len,y,buf,len);
}

void da_print_u32l(uint8_t x,uint8_t y,uint32_t num){
  static char buf[10];
  uint8_t len = u32toa_helper(buf, num);
  da_print_str_len(x,y,buf,len);
  for(int i = len;i<10;i++)
    da_print_char(x+i,y,' ');
}

void da_print_u32r(uint8_t x,uint8_t y,uint32_t num, uint8_t length,char fill){
  static char buf[10];
  uint8_t len = u32toa_helper(buf, num);
  for(int i = length;i>len;i--)
    da_print_char(x-i,y,fill);
  da_print_str_len(x-len,y,buf,len);
}
