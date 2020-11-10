#include "../../../../../inc/MarlinConfigPre.h"
#if ENABLED(BTT_UI_SPI)

#include "../TSC_Menu.h"
#include "../../../../../feature/powerloss.h"


void menuCallBackPowerFailed(void)
{
  uint16_t key_num = KEY_GetValue(2, doubleBtnRect);
  switch(key_num)
  {
    case KEY_POPUP_CONFIRM:
     #ifdef POWER_LOSS_RECOVERY
      storeCmd("M1000");
      //recovery.resume();
      infoMenu.cur--;
      #endif
      break;
    
    case KEY_POPUP_CANCEL:
    
      #ifdef POWER_LOSS_RECOVERY
      card.removeJobRecoveryFile();
      infoMenu.cur--;
      #endif

      break;        
  }
  if(!IS_SD_INSERTED())
  {
    infoMenu.cur--;
  }
}

void menuPowerFailed()
{
  //GUI_Clear(BK_COLOR);
  #ifdef POWER_LOSS_RECOVERY
  popupDrawPage(bottomDoubleBtn, textSelect(LABEL_POWER_FAILED), (uint8_t *)recovery.info.sd_filename, textSelect(LABEL_CONFIRM), textSelect(LABEL_CANNEL));
    
  menuSetFrontCallBack(menuCallBackPowerFailed);
  #endif
  
}

#endif

