#include "mc51-library.h"
#include "charlcd.h"

CHARLCD_t display;

uint8_t i;

void
main()
{
  display.regSelect_pin.port = GPIO_PORT_1;
  display.regSelect_pin.pin = GPIO_PIN_0;
  
  display.enable_pin.port = GPIO_PORT_1;
  display.enable_pin.pin = GPIO_PIN_1;
  
  for (i = 0; i < 4; i++)
  {
    display.data_pin[i].port = GPIO_PORT_1;
    display.data_pin[i].pin = GPIO_PIN_2 << i;
  }
  
  CHARLCD_init(&display, 2, 16);
  
  CHARLCD_SetCursor(&display, 0, 1);
  CHARLCD_PrintString(&display, "MC-51 library");

  CHARLCD_SetCursor(&display, 1, 0);
  CHARLCD_PrintString(&display, "CharLCD Example");
  _delay_ms(1000);
  
  
  while(1);
  
  while(1)
  {
    CHARLCD_SetCursor(&display, 0, 0);
    CHARLCD_PrintString(&display, " Display ON/OFF ");
    _delay_ms(500);
    for (i = 0; i < 3; i++)
    {
      CHARLCD_Display(&display, DISABLE);
      _delay_ms(500);
      CHARLCD_Display(&display, ENABLE);
      _delay_ms(500);
    }
    
    CHARLCD_SetCursor(&display, 0, 0);
    CHARLCD_PrintString(&display, " Cursor ON/OFF  ");
    _delay_ms(500);
    CHARLCD_SetCursor(&display, 0, 15);
    for (i = 0; i < 3; i++)
    {
      CHARLCD_Cursor(&display, ENABLE);
      _delay_ms(1000);
      CHARLCD_Cursor(&display, DISABLE);
      _delay_ms(1000);
    }

    CHARLCD_SetCursor(&display, 0, 0);
    CHARLCD_PrintString(&display, " Cursor Blink  ");
    _delay_ms(500);
    CHARLCD_SetCursor(&display, 0, 15);
    CHARLCD_Cursor(&display, ENABLE);
    CHARLCD_CursorBlink(&display, ENABLE);
    _delay_ms(5000);
    CHARLCD_CursorBlink(&display, DISABLE);
      
    
  }
}