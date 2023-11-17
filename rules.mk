# Enabled features.

SEND_STRING_ENABLE = yes
CAPS_WORD_ENABLE = yes

# Add defines for optional features.

ifeq ($(strip $(FK_TOP_OUTER_KEY)), yes)
  OPT_DEFS += -DFK_TOP_OUTER
endif

ifeq ($(strip $(FK_OUTER_KEYS)), 1)
  OPT_DEFS += -DFK_MDL_OUTER
endif

ifeq ($(strip $(FK_OUTER_KEYS)), 2)
  OPT_DEFS += -DFK_MDL_OUTER -DFK_BTM_OUTER
endif

ifeq ($(strip $(FK_THUMB_KEYS)), 1)
  OPT_DEFS += -DFK_THUMB_INNER
endif

ifeq ($(strip $(FK_THUMB_KEYS)), 2)
  OPT_DEFS += -DFK_THUMB_INNER -DFK_THUMB_OUTER
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
