#include <program_hook.h>
#include <programs.h>
//Add your program text
//2 Lines for each program
//Use null character if program doesn't need input parameter
/* Program Text
|Name----------||DescriptionLn1||DescriptionLn2||DescriptionLn3|
|Config Line 1 ||Config Line 2 ||Config Line 3 |------|InitVal |*/
const char ph_program_chars[PH_ENTRY_SIZE * PH_PROGRAM_COUNT + 1] PROGMEM = "\
Mini Control    Use the ASIS+ asa controller    with 4 buttons  \
\0                                                               \
\
Mem Storage     Open Compendium,Go to non searchActivate Program\
Delay Before Last A (0-297)                           0000000033\
\
SWSH Watt Farm  1. Time Sync Off2. Drop WP                      \
Enter how many  days to farm.   One day=2000W         0000000120\
\
SWSH Den Skip   1. Date 1/1/20002. Glitch On    3. Go to PC     \
Enter how many  days to skip.                         0000000000\
\
SWSH Hatch P5   Hatch Eggs with Period = 5                      \
Enter how many  eggs to hatch                         0000000030\
\
SWSH Hatch P10  Hatch Eggs with Period = 10                     \
Enter how many  eggs to hatch                         0000000030\
\
SWSH Hatch P15  Hatch Eggs with Period = 15                     \
Enter how many  eggs to hatch                         0000000030\
\
SWSH Hatch P20  Hatch Eggs with Period = 20                     \
Enter how many  eggs to hatch                         0000000030\
\
SWSH Hatch P25  Hatch Eggs with Period = 25                     \
Enter how many  eggs to hatch                         0000000030\
\
SWSH Hatch P30  Hatch Eggs with Period = 30                     \
Enter how many  eggs to hatch                         0000000030\
\
SWSH Hatch P35  Hatch Eggs with Period = 35                     \
Enter how many  eggs to hatch                         0000000030\
\
SWSH Hatch P40  Hatch Eggs with Period = 40                     \
Enter how many  eggs to hatch                         0000000030\
\
Template        Desc Line 1     Desc Line 2     Desc Line 3     \
\0                                                               \
";
/* Program Text
|Name----------||DescriptionLn1||DescriptionLn2||DescriptionLn3|
|Config Line 1 ||Config Line 2 ||Config Line 3 |------|InitVal |*/

// Add program main function, it should match the order above
prog_main_func_t ph_mains[PH_PROGRAM_COUNT] = {
		mini_control_main,
		mem_storage_main,
		swsh_farm_watt_main,
		swsh_frame_skip_main,
		swsh_hatch_period_5,	//magikarp
		swsh_hatch_period_10, //morpeko
		swsh_hatch_period_15, //coalossal
		swsh_hatch_period_20, //drednaw
		swsh_hatch_period_25, //Falinks
		swsh_hatch_period_30, //Duraludon
		swsh_hatch_period_35, //Eevee
		swsh_hatch_period_40, //Dragapult
};

void ph_get_entry(int i, char *buf)
{
	for (int c = 0; c < PH_ENTRY_SIZE; c++)
	{
		buf[c] = pgm_read_word(&ph_program_chars[i * PH_ENTRY_SIZE + c]);
	}
}

bool ph_launch(int i, uint32_t arg)
{
	if (ph_mains[i] != NULL)
	{
		ph_mains[i](arg);
		return true;
	};
	return false;
}