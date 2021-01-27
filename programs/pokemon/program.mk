# ----- ASIS+ Program Makefile -----

# Add to sources
ASIS+_PROGRAM_SRC     += $(ASIS_PROGRAM_PATH)/pokemon/day_skips.c \
						$(ASIS_PROGRAM_PATH)/pokemon/farm_watt.c \
						$(ASIS_PROGRAM_PATH)/pokemon/frame_skip.c \
# Add to paths
ASIS_PROGRAM_LIB_PATH += -I$(ASIS_PROGRAM_PATH)/pokemon/