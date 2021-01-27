#ifndef _PROGRAM_HOOK_H_
#define _PROGRAM_HOOK_H_

#include <LUFA/Platform/Platform.h>

#define PH_PROGRAM_COUNT 13 //Change to number of programs
#define PH_ENTRY_SIZE 128
typedef void (*prog_main_func_t)(uint32_t);
void ph_get_entry(int i, char *buf);
bool ph_launch(int i, uint32_t arg);

#endif