ifeq ($(strip $(CORNER_RESET_ENABLE)), yes)
    OPT_DEFS += -DCORNER_RESET_ENABLE
endif

ifeq ($(strip $(RHS_THUMB_MEDIAL)), yes)
    OPT_DEFS += -DRHS_THUMB_MEDIAL
endif

SRC += rgoulter.c
