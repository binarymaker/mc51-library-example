#include "mc51-library.h"
#include "charlcd.h"

CHARLCD_t display;

uint8_t i;

void
main()
{
  
  display.size_type = CHARLCD_TYPE_16X2;
  
  display.regSelect_pin.port = GPIO_PORT_1;
  display.regSelect_pin.pin = GPIO_PIN_0;
  
  display.enable_pin.port = GPIO_PORT_1;
  display.enable_pin.pin = GPIO_PIN_1;
  
  for (i = 0; i < 4; i++)
  {
    display.data_pin[i].port = GPIO_PORT_1;
    display.data_pin[i].pin = GPIO_PIN_2 + i;
  }
  
  CHARLCD_init(&display);
  
  while(1)
  {
    
  }
}