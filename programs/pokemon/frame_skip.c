#include <pokemon_swsh.h>
#include <asis+.h>
#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>


void swsh_frame_skip_main(uint32_t frames){
	da_print_str(0,0,"Fast Den Skip");
	da_print_str(0,3,"Hold \nO to quit");
  da_print_str(0,4,"Skipped");
  da_print_u32r(16,5,0,10,' ');
  da_print_str(0,6,"Total");
  da_print_u32r(16,7,frames,10,' ');
  da_print_str(0,1,"Mode: Fast 3000 ");
  uint32_t skipped = 0;
  while(frames>=3000){
    //In Game
    asis_click(BTN_HOME);
	  asis_delay_s(2);
	  //Home Screen
	  homescreen_to_skip1();
    skipped++;
    da_print_u32r(16,5,skipped,10,' ');
    // 1/2 now
    for(int j=0;j<99;j++){
      for(int i=0;i<29;i++){
        skip_another1();
        skipped++;
        da_print_u32r(16,5,skipped,10,' ');
        if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			    return;
		    }
      }
      // 1/31 now
      skip_another1();
      // 1/1 now
      skip_another1();
      skipped++;
      da_print_u32r(16,5,skipped,10,' ');
      if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			  return;
		  }
      // 1/2 now, skipped 30*(j+1)+1
    }
    // 1/2 now, skipped 30*99+1
    for(int i=0;i<29;i++){
      skip_another1();
      skipped++;
      da_print_u32r(16,5,skipped,10,' ');
      if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			  return;
		  }
    }
    // 1/31 now
    skip_another1();
    // 1/1 now, skipped 3000
    frames-=3000;
    asis_click(BTN_HOME);
	  asis_delay_s(2);
	  //Home Screen
    asis_click(BTN_HOME);
	  asis_delay_s(2);
    //In Game
    asis_delay_s(10);
    asis_click(BTN_X);
    asis_delay_s(10);
    asis_click(BTN_R);
    asis_delay_s(10);
    asis_click(BTN_A);
    asis_delay_s(10);
    //Saved, In Game
  }
  da_print_str(0,1,"Mode: Fast 300  ");
  while(frames>=300){
    //In Game
    asis_click(BTN_HOME);
	  asis_delay_s(2);
	  //Home Screen
	  homescreen_to_skip1();
    skipped++;
    da_print_u32r(16,5,skipped,10,' ');
    // 1/2 now
    for(int j=0;j<9;j++){
      for(int i=0;i<29;i++){
        skip_another1();
        skipped++;
        da_print_u32r(16,5,skipped,10,' ');
        if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			    return;
		    }
      }
      // 1/31 now
      skip_another1();
      // 1/1 now
      skip_another1();
      skipped++;
      da_print_u32r(16,5,skipped,10,' ');
      if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			  return;
		  }
      // 1/2 now, skipped 30*(j+1)+1
    }
    // 1/2 now, skipped 30*9+1
    for(int i=0;i<29;i++){
      skip_another1();
      skipped++;
      da_print_u32r(16,5,skipped,10,' ');
      if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			  return;
		  }
    }
    // 1/31 now 
    skip_another1();
    // 1/1 now, skipped 300
    frames-=300;
    asis_click(BTN_HOME);
	  asis_delay_s(2);
	  //Home Screen
    asis_click(BTN_HOME);
	  asis_delay_s(2);
    //In Game
    asis_delay_s(10);
    asis_click(BTN_X);
    asis_delay_s(10);
    asis_click(BTN_R);
    asis_delay_s(10);
    asis_click(BTN_A);
    asis_delay_s(10);
    //Saved, In Game
  }
  da_print_str(0,1,"Mode: Fast 30    ");
  while(frames>=30){
    //In Game
    asis_click(BTN_HOME);
	  asis_delay_s(2);
	  //Home Screen
	  homescreen_to_skip1();
    skipped++;
    da_print_u32r(16,5,skipped,10,' ');
    // 1/2 now
    for(int i=0;i<29;i++){
      skip_another1();
      skipped++;
      da_print_u32r(16,5,skipped,10,' ');
      if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			  return;
		  }
    }
    // 1/31 now
    skip_another1();

    // 1/1 now, skipped 30
    frames-=30;
    asis_click(BTN_HOME);
	  asis_delay_s(2);
	  //Home Screen
    asis_click(BTN_HOME);
	  asis_delay_s(2);
    //In Game
    asis_delay_s(10);
    asis_click(BTN_X);
    asis_delay_s(10);
    asis_click(BTN_R);
    asis_delay_s(10);
    asis_click(BTN_A);
    asis_delay_s(10);
    //Saved, In Game
  }
  da_print_str(0,1,"Mode: Less 30    ");
  if(frames>0){
    //In Game
    asis_click(BTN_HOME);
	  asis_delay_s(2);
	  //Home Screen
	  homescreen_to_skip1();
    skipped++;
    da_print_u32r(16,5,skipped,10,' ');
    // 1/2 now
    for(int i=0;i<frames-1;i++){
      skip_another1();
      skipped++;
      da_print_u32r(16,5,skipped,10,' ');
      if(ha_is_button_pressed(HA_PIN_BTN_OK)){
			  return;
		  }
    }

    asis_click(BTN_HOME);
	  asis_delay_s(2);
	  //Home Screen
    asis_click(BTN_HOME);
	  asis_delay_s(2);
    //In Game
    asis_delay_s(10);
    asis_click(BTN_X);
    asis_delay_s(10);
    asis_click(BTN_R);
    asis_delay_s(10);
    asis_click(BTN_A);
    asis_delay_s(10);
    //Saved, In Game
  }
  da_print_str(0,1,"Complete!       ");
  while(!ha_is_button_pressed(HA_PIN_BTN_OK)){
		asis_delay_ms(100);
	}
}