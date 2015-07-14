#ifndef _GPIO_MD_H
#define _GPIO_MD_H


#if defined(__ANDROID_MODEM__)

typedef enum{
  GPIO_MD_PIN_BEGIN =0X00000FFF,
#if defined(__AST_TL1_TDD__)
  GPIO_AST_HIF_CS,  //  start 0x00001000
  GPIO_AST_HIF_CS_ID,
  GPIO_AST_Reset,
  GPIO_AST_CLK_32K,
  GPIO_AST_CLK_32K_CLKM,
  GPIO_AST_Wakeup,
  GPIO_AST_INT,
  GPIO_AST_WAKEUP_INT,
  GPIO_AST_AFC_Switch,  // set gpio mode
  GPIO_RF_CONTROL1,    //set gpio  mode 
#endif
#if defined(__SIM_DRV_SWITCH_MT6306__)
  GPIO_SIM_SWITCH_CLK,
GPIO_SIM_SWITCH_DAT,
#endif
  GPIO_MD_NUMBER  // this should present end 
} GPIO_PIN_DEFINE_ENUM;



extern const char GPIO_PIN_DEFINE_STRING[][30];

extern const char GPIO_PIN_DEFINE_LENGTH [];

#endif //#ifdef __ANDROID_MODEM__
#endif
