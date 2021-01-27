# ----- ASIS+ Program Makefile -----

# Add to sources
ASIS+_PROGRAM_SRC     += $(ASIS_PROGRAM_PATH)/pokemon-hatch/pokemon_swsh_hatch.c 
# Add to paths
ASIS_PROGRAM_LIB_PATH += -I$(ASIS_PROGRAM_PATH)/pokemon-hatch/