CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
LEADER_ENABLE = yes
WPM_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled_bongocat.c
endif

include layouts/community/split_3x5_3/rgoulter/options.mk
