# Include the userspace code.

SRC += flexkey.c

# This is a bit of a hack to allow combos to be defined in userspace.

INTROSPECTION_KEYMAP_C = fk_combos.c

# Enabled features.

SEND_STRING_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes

# Add defines for flexkey optional features.

ifeq ($(strip $(FK_TOP_OUTER_KEY)), yes)
  OPT_DEFS += -DFK_TOP_OUTER
endif

ifeq ($(strip $(FK_MIDDLE_OUTER_KEY)), yes)
  OPT_DEFS += -DFK_MDL_OUTER
endif

ifeq ($(strip $(FK_BOTTOM_OUTER_KEY)), yes)
  OPT_DEFS += -DFK_BTM_OUTER
endif

ifeq ($(strip $(FK_INNER_KEYS)), top)
  OPT_DEFS += -DFK_TOP_INNER -DFK_MDL_INNER
endif

ifeq ($(strip $(FK_INNER_KEYS)), bottom)
  OPT_DEFS += -DFK_MDL_INNER -DFK_BTM_INNER
endif

ifeq ($(strip $(FK_INNER_KEYS)), all)
  OPT_DEFS += -DFK_TOP_INNER -DFK_MDL_INNER -DFK_BTM_INNER
endif

ifeq ($(strip $(FK_TWO_THUMBKEYS)), yes)
  OPT_DEFS += -DFK_TWO_THUMBKEYS
endif

ifeq ($(strip $(FK_COMBOS_ON)), yes)
  OPT_DEFS += -DFK_COMBOS_ON
endif

ifeq ($(strip $(FK_SHIFT_BACKSPACE_DEL)), yes)
  OPT_DEFS += -DFK_SHIFT_BACKSPACE_DEL
endif
