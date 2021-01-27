##How to use this template to create a new program:

1. Copy it and rename the directory and files:
	- "template" directory should be your program name
	- Rename "template_main.c" and "template_main.h". It is recommended to match the program name, but it's not required.
2. Edit program.mk, following the instructions there
3. Edit template_main.h and template_main.c, follwing the instructions there
4. Go to the programs directory and edit programs.h, add your header file there:
```
#include <template_main.h>
```
5. Edit program_hook.h. Change the number of programs
6. Edit program_hook.c, following the instructions there
7. Open programs.mk. Add the path to your program's program.mk to it
8. Open your main C file and start coding