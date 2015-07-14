#include "gpio_md.h"


#if defined(__ANDROID_MODEM__)

const char GPIO_PIN_DEFINE_STRING[][30]= {
#if defined(__AST_TL1_TDD__)
"GPIO_AST_HIF_CS",
"GPIO_AST_HIF_CS_ID",
"GPIO_AST_Reset",
"GPIO_AST_CLK_32K",
"GPIO_AST_CLK_32K_CLKM",
"GPIO_AST_Wakeup",
"GPIO_AST_INT",
"GPIO_AST_WAKEUP_INT",
"GPIO_AST_AFC_Switch",
"GPIO_RF_CONTROL1"
#endif
#if defined(__SIM_DRV_SWITCH_MT6306__)
"GPIO_SIM_SWITCH_CLK",
"GPIO_SIM_SWITCH_DAT",
#endif
"",
};

const char GPIO_PIN_DEFINE_LENGTH []= {
#if defined(__AST_TL1_TDD__)	
15, // GPIO_AST_HIF_CS,
18, // GPIO_AST_HIF_CS_ID,
14, // GPIO_AST_Reset,
16, // GPIO_AST_CLK_32K,
21, // GPIO_AST_CLK_32K_CLKM,
15, // GPIO_AST_Wakeup,
12, // GPIO_AST_INT,
19, // GPIO_AST_WAKEUP_INT,
19, // GPIO_AST_AFC_Switch,
16, // GPIO_RF_CONTROL1,
#endif
#if defined(__SIM_DRV_SWITCH_MT6306__)
19,
19,
#endif
0,
};

#endif //#ifdef __ANDROID_MODEM__
