#include <pokemon_swsh_hatch.h>
#include <asis+.h>
#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>

void flyToBreeder(void)
{
  da_print_str(0, 1, "Flying to Breed ");
  //Arbitrary location
  asis_click(BTN_X); //Menu
  asis_delay_s(2);
  asis_click(BTN_A); //Open Map
  asis_delay_s(3);
  asis_stickL(STK_R, STK_U);
  asis_delay_ms(50);
  asis_stick_center();
  asis_delay_ms(500);
  asis_click(BTN_A);
  asis_delay_ms(500);
  asis_click(BTN_A);
  asis_delay_s(5);
}

void takeEgg(int egg)
{
  da_print_str(0, 1, "Taking Egg      ");
  //Get Egg
  asis_stickL(STK_L, STK_CTR);
  asis_delay_ms(250);
  asis_stickL(STK_CTR, STK_U);
  asis_delay_ms(250);
  asis_stickL(STK_R, STK_CTR);
  asis_delay_ms(65);
  asis_stick_center();
  asis_delay_s(1);
  asis_click(BTN_A); //You have an egg, do you want it | welcome
  asis_delay_s(2);
  asis_click(BTN_A); //you got an EGG!!  | what do you need
  asis_delay_s(5);
  asis_click(BTN_B);
  asis_delay_s(3);
  asis_click(BTN_A);
  asis_delay_s(2);
  asis_stickL(STK_L, STK_CTR); //Move away in case no egg
  asis_delay_ms(250);
  asis_stickL(STK_CTR, STK_D);
  asis_delay_ms(250);
  asis_stickL(STK_R, STK_CTR);
  asis_delay_ms(250);
  asis_stick_center();
  //Put Egg
  asis_click(BTN_A);
  asis_delay_s(2);
  for (int i = 0; i < egg; i++)
  {
    asis_dpad_click(DPAD_D);
    asis_delay_ms(250);
  }
  asis_click(BTN_A);
  asis_delay_s(3);
  asis_click(BTN_B);
  asis_delay_s(3);
  asis_click(BTN_B);
  asis_delay_s(1);
}
void hatch_cycle(int cycle)
{
  //Go Right
  da_print_str(0, 1, "Hatching...     ");
  asis_stickL(STK_R, STK_CTR);
  asis_delay_s(3);

  da_print_str(0, 2, "Cycle: ");
  da_print_str(11, 2, "/");
  da_print_u16r(16, 2, cycle, 4, ' ');
  for (int i = 0; i < cycle; i++)
  {

    da_print_u16r(11, 2, i, 4, ' ');

    asis_stickL(STK_R, STK_CTR);
    asis_delay_ms(300);
    asis_stickL(STK_CTR, STK_D);
    asis_delay_ms(300);
    asis_stickL(STK_L, STK_CTR);
    asis_delay_ms(300);
    asis_stickL(STK_CTR, STK_U);
    asis_delay_ms(300);
  }
  asis_stick_center();
  da_clear_line(2);
}
void hatch_animation(void)
{

  //Press A to hatch
  asis_delay_s(1);

  da_print_str(0, 1, "Hatching!!!     ");
  for (int i = 0; i < 20; i++)
  {
    asis_click(BTN_A); //in case of picking up item
    asis_delay_s(1);
  }

  asis_click(BTN_A);
  da_print_str(0, 1, "Hatched         ");
  asis_delay_s(7);
}
void print_egg(uint8_t x, uint8_t y, int stat)
{
  da_print_str(x - 1, y, "[");
  da_print_str(x + 2, y, "]");
  switch (stat)
  {
  case 0:
    da_print_str(x, y, "??");
    break;
  case 1:
    da_print_str(x, y, "()");
    break;
  case 2:
    da_print_str(x, y, "!!");
    break;
  case 3:
    da_print_str(x, y, ". ");
    break;
  }
}
void print_hatch_status(int *status, int current)
{
  da_print_str(0, 6, " [FB]");
  da_print_str(5, 6, " ");
  da_print_str(10, 6, " ");
  da_print_str(15, 6, " ");
  da_print_str(0, 7, " ");
  da_print_str(5, 7, " ");
  da_print_str(10, 7, " ");
  da_print_str(15, 7, " ");
  print_egg(7, 6, status[0]);
  print_egg(12, 6, status[1]);
  print_egg(2, 7, status[2]);
  print_egg(7, 7, status[3]);
  print_egg(12, 7, status[4]);
  int cx, cy;
  if (current == 0)
  {
    return;
  }
  if (current < 3)
  {
    cy = 6;
  }
  else
  {
    cy = 7;
  }
  if (current == 3)
  {
    cx = 0;
  }
  else if (current == 1 || current == 4)
  {
    cx = 5;
  }
  else
  {
    cx = 10;
  }
  da_print_str(cx, cy, ">");
  da_print_str(cx + 5, cy, "<");
}

int check_exit(void)
{
  if (ha_is_button_pressed(HA_PIN_BTN_OK))
  {
    return 1;
  }
  return 0;
}

void print_period(int period)
{
  da_print_u8r(16, 0, (uint8_t)period, 2, ' ');
}
void hatch(int* cycles, int cycles_len, int division,int rep_index, uint32_t count)
{
  da_print_str(0, 0, "Egg Hatcher P=");
  da_print_str(0, 3, "Hold \nO To Exit");

  da_print_str(0, 4, "Count ");
  da_print_str(0, 5, "Remain");
  int cycles_index = 0;
  int current_hatching = 0;
  int taking = 1;
  int status[5];
  for (int i = 0; i < 5; i++)
  {
    status[i] = 0; //unknown, 1=egg, 2=hatching, 3=hatched
  }
  for (int i = 0; i < count; i++)
  {
    da_print_u32r(16, 4, i, 10, ' ');
    da_print_u32r(16, 5, count - i, 10, ' ');
    print_hatch_status(status, 0);
    if (check_exit())
      return;
    flyToBreeder();
    if (check_exit())
      return;
    takeEgg(taking);
    status[taking - 1] = 1;
    taking++;
    if (taking > division)
      taking = 1;
    print_hatch_status(status, 0);
    if (check_exit())
      return;
    flyToBreeder();
    if (check_exit())
      return;
    if (i >= division - 1)
    {
      current_hatching++;
      if (current_hatching > division)
        current_hatching = 1;
    }
    print_hatch_status(status, current_hatching);
    hatch_cycle(cycles[cycles_index]);
    cycles_index++;
    if(cycles_index>=cycles_len){
      cycles_index=rep_index;
    }
    //if (fraction != 0 && ((i % fraction) == (fraction - 1)))
      
    //else
     // hatch_cycle(cycle);

    if (check_exit())
      return;
    if (i >= division - 1)
    {
      status[current_hatching - 1] = 2;
      print_hatch_status(status, current_hatching);
      if (check_exit())
        return;
      hatch_animation();
      status[current_hatching - 1] = 3;
      print_hatch_status(status, 0);
    }
  }
  da_print_str(0, 1, "Finished.       ");
  while (!check_exit())
  {
    asis_delay_s(1);
  }
}
int cycles_p5_to_p15[1]={14};
void swsh_hatch_period_5(uint32_t count)
{
  print_period(5);
  hatch(cycles_p5_to_p15, 1, 1,0, count);
}
void swsh_hatch_period_10(uint32_t count)
{
  print_period(10);
  hatch(cycles_p5_to_p15, 1, 2,0, count);
}
void swsh_hatch_period_15(uint32_t count)
{
  print_period(15);
  hatch(cycles_p5_to_p15, 1, 3,0, count);
}
int cycles_p20[11]={12,12,12,12,15,15,15,12,12,14,14};
void swsh_hatch_period_20(uint32_t count)
{
  print_period(20);
  hatch(cycles_p20, 11, 4,7, count);
}
void swsh_hatch_period_25(uint32_t count)
{
  print_period(25);
  //hatch(100, 5, 0, count);
}
void swsh_hatch_period_30(uint32_t count)
{
  print_period(30);
  //hatch(100, 5, 0, count);
}
void swsh_hatch_period_35(uint32_t count)
{
  print_period(35);
  //hatch(100, 5, 0, count);
}
void swsh_hatch_period_40(uint32_t count)
{
  print_period(40);
  //hatch(100, 5, 0, count);
}
