# ----- ASIS+ Program Makefile -----
# Change "template" to directory name
# Change template_main.c to the main C file name

# Add to sources
ASIS+_PROGRAM_SRC     += $(ASIS_PROGRAM_PATH)/template/template_main.c
# Add to paths
ASIS_PROGRAM_LIB_PATH += -I$(ASIS_PROGRAM_PATH)/template/