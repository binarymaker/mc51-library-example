#include "mc51-library.h"

void
main()
{
  GPIO_PinMode(GPIO_PORT_1, GPIO_PIN_0, GPIO_MODE_OUTPUT);
  
  while(1)
  {
    GPIO_TogglePin(GPIO_PORT_1, GPIO_PIN_0);
    _delay_ms(100);
  }
}