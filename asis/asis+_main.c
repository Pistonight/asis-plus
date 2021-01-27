/*
 * Main ASIS+ file
 */

#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>
#include <asis+.h>
#include <program_hook.h>
#include <asis+_main.h>
int current_program = 0;
uint32_t current_config = 0;
void (*continuation)(void) = NULL;
void asis_main_setup(void)
{
	//MUST setup in this order
	ha_setup();
	asis_setup();
	da_setup();
}
void asis_welcome_screen(void)
{
	asis_click(BTN_A);
	da_print_str(0, 0, "+==============+");
	da_print_str(0, 1, "|  A.S.I.S.+.  |");
	da_print_str(0, 2, "+==============+");
	da_print_str(0, 3, "Press any button");
	da_print_str(0, 4, "\nU UP            ");
	da_print_str(0, 5, "\nD DOWN          ");
	da_print_str(0, 6, "\nL LEFT          ");
	da_print_str(0, 7, "\nR RIGHT \nO OK     ");
	while (1)
	{
		if (ha_is_button_pressed(HA_PIN_BTN_LEFT))
		{
			break;
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_RIGHT))
		{
			break;
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_UP))
		{
			break;
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_DOWN))
		{
			break;
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_OK))
		{
			break;
		}
		_delay_ms(100);
	}
	continuation = asis_program_chooser_screen;
}
void asis_program_chooser_screen(void)
{
	if (PH_PROGRAM_COUNT == 0)
	{
		da_print_str(0, 0, "ASIS+           ");
		da_print_str(0, 1, "No Program.");
		while (1)
			;
	}
	while (1)
	{
		char entry[PH_ENTRY_SIZE];
		ph_get_entry(current_program, entry);
		da_print_str(0, 0, "ASIS+  ");
		da_print_u8r(10, 0, current_program + 1, 4, ' ');
		da_print_u8r(16, 0, PH_PROGRAM_COUNT, 4, ' ');
		da_print_str(10, 0, " / ");
		da_print_str(0, 1, "Choose Program: ");

		da_print_str(0, 2, entry);
		da_print_str(0, 3, "\nL\nR -/+1 \nU\nD -/+10");
		da_print_str(0, 4, entry + 16);
		da_print_str(0, 5, entry + 32);
		da_print_str(0, 6, entry + 48);
		da_print_str(0, 7, "           \nO OK ");
		if (ha_is_button_pressed(HA_PIN_BTN_LEFT))
		{
			current_program--;
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_RIGHT))
		{
			current_program++;
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_UP))
		{
			current_program += 10;
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_DOWN))
		{
			current_program -= 10;
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_OK))
		{
			continuation = asis_program_config_screen;
			break;
		}
		current_program = (current_program + PH_PROGRAM_COUNT) % PH_PROGRAM_COUNT;
		_delay_ms(100);
	}
}

void asis_program_config_screen(void)
{
	char entry[PH_ENTRY_SIZE];
	ph_get_entry(current_program, entry);
	if (entry[64] == '\0')
	{
		continuation = asis_program_confirm_screen;
		return;
	}
	da_print_str(0, 0, entry + 64);
	da_print_str(0, 1, entry + 80);
	da_print_str(0, 2, entry + 96);
	da_print_str_len(0, 3, entry + 112, 6);

	da_clear_line(4);
	da_clear_line(5);
	da_print_str(0, 6, "\nL\nR change digit ");
	da_print_str(0, 7, "\nD\nU -/+     \nO OK ");
	char number[10];
	for (int i = 0; i < 10; i++)
	{
		number[i] = entry[i + 118];
		if (number[i] < '0' || number[i] > '9')
		{
			number[i] = '0';
		}
	}
	da_print_str_len(6, 3, "          ", 10);
	int digit = 9;
	char cursor[11] = "         ^";
	while (1)
	{
		current_config = 0;
		for (int i = 0; i < 10; i++)
		{
			current_config *= 10;
			current_config += (number[i] - '0');
		}
		da_print_u32r(13, 4, current_config, 10, '_');
		da_print_str_len(3, 5, cursor, 10);

		if (ha_is_button_pressed(HA_PIN_BTN_LEFT))
		{
			cursor[digit] = ' ';
			if (digit <= 0)
			{
				digit = 9;
			}
			else
			{
				digit--;
			}
			cursor[digit] = '^';
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_RIGHT))
		{
			cursor[digit] = ' ';
			if (digit >= 9)
			{
				digit = 0;
			}
			else
			{
				digit++;
			}
			cursor[digit] = '^';
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_UP))
		{
			if (number[digit] >= '9')
			{
				number[digit] = '0';
			}
			else if (number[digit] >= '3' && digit == 0)
			{
				number[digit] = '0';
			}
			else
			{
				number[digit]++;
			}
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_DOWN))
		{
			if (number[digit] <= '0')
			{
				if (digit == 0)
				{
					number[digit] = '3';
				}
				else
				{
					number[digit] = '9';
				}
			}
			else
			{
				number[digit]--;
			}
		}
		else if (ha_is_button_pressed(HA_PIN_BTN_OK))
		{
			current_config = 0;
			for (int i = 0; i < 10; i++)
			{
				current_config *= 10;
				current_config += (number[i] - '0');
			}
			continuation = asis_program_confirm_screen;
			break;
		}
		_delay_ms(100);
	}
}

void asis_program_confirm_screen(void)
{
	int count_down = 10;
	continuation = start_program;
	char entry[PH_ENTRY_SIZE];
	ph_get_entry(current_program, entry);
	while (count_down > 0)
	{
		da_print_str(0, 0, entry);
		da_clear_line(1);
		da_print_str(0, 2, "cfg=  ");
		da_print_u32r(16, 2, current_config, 10, ' ');
		da_print_str(0, 3, "starting in:  ");
		da_print_u8r(16, 3, count_down, 2, ' ');
		da_clear_line(4);
		da_clear_line(7);
		da_print_str(0, 5, "\nU\nD\nL\nR to cancel  ");
		da_print_str(0, 6, "\nO    to start   ");

		count_down--;
		for (int i = 0; i < 10; i++)
		{
			if (ha_is_button_pressed(HA_PIN_BTN_LEFT) ||
					ha_is_button_pressed(HA_PIN_BTN_RIGHT) ||
					ha_is_button_pressed(HA_PIN_BTN_UP) ||
					ha_is_button_pressed(HA_PIN_BTN_DOWN))
			{
				continuation = asis_program_chooser_screen;
				count_down = 0;
				break;
			}
			else if (ha_is_button_pressed(HA_PIN_BTN_OK))
			{
				count_down = 0;
				break;
			}
			_delay_ms(100);
		}
	}
}

void start_program(void)
{
	da_clear();
	continuation = asis_program_chooser_screen;
	if (!ph_launch(current_program, current_config))
	{
		da_print_str(0, 0, "Launch Failed");
		da_print_str(0, 1, "[OK]");
		while (1)
		{
			if (ha_is_button_pressed(HA_PIN_BTN_OK))
			{
				break;
			}
			_delay_ms(100);
		}
	}
	asis_reset();
}
int main(void)
{
	asis_main_setup();

	continuation = asis_welcome_screen;
	while (continuation != NULL)
	{
		void (*k)(void) = continuation;
		continuation = NULL;
		_delay_ms(100);
		k();
	}
	return 0;
}
