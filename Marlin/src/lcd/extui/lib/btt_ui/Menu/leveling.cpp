#include "../../../../../inc/MarlinConfigPre.h"
#if ENABLED(BTT_UI_SPI)
#include "../TSC_Menu.h"


#ifdef AUTO_BED_LEVELING_BILINEAR

#include "../../../../../feature/bltouch.h"

const MENUITEMS autoLevelingItems = {
// title
LABEL_ABL,
// icon                        label
 {{ICON_LEVELING,              LABEL_ABL},
  {ICON_BLTOUCH_DEPLOY,        LABEL_BLTOUCH_DEPLOY},
  {ICON_BLTOUCH_STOW,          LABEL_BLTOUCH_STOW},
  {ICON_BLTOUCH_TEST,          LABEL_BLTOUCH_TEST},
  {ICON_PROBE_OFFSET,          LABEL_PROBE_OFFSET},
  {ICON_BABYSTEP,              LABEL_BABYSTEP},
  {ICON_EM_STOP,               LABEL_EMERGENCYSTOP},
  {ICON_BACK,                  LABEL_BACK},}
};

void menuCallBackAutoBedLeveling(void)
{
  KEY_VALUES key_num = menuKeyGetValue();
  switch(key_num)
  {
    case KEY_ICON_0:
      storeCmd("G28");
      storeCmd("G29");
      storeCmd("M500");
      break;
    case KEY_ICON_1:
      storeCmd("M280 P0 S10\n");
      break;
    case KEY_ICON_2:
      storeCmd("M280 P0 S90\n");
      break;
    case KEY_ICON_3:
      storeCmd("M280 P0 S120\n");
      break;
    case KEY_ICON_4:
      infoMenu.menu[++infoMenu.cur] = menuProbeOffset;
      break;
    case KEY_ICON_5:
      infoMenu.menu[++infoMenu.cur] = menuBabyStep;
      break;
    case KEY_ICON_6:
      flashFirmware(1);
      break;
    case KEY_ICON_7:
      infoMenu.cur--; break;
    default:break;
  }
}

void menuAutoLeveling()
{
  menuDrawPage(&autoLevelingItems);
  menuSetFrontCallBack(menuCallBackAutoBedLeveling);
}

#else

#endif
#endif
