#include "mc51-library.h"

void main()
{
  
  GPIO_PinMode(GPIO_PORT_1, GPIO_PIN_0 | GPIO_PIN_2, GPIO_MODE_OUTPUT);
  GPIO_PinMode(GPIO_PORT_1, GPIO_PIN_1, GPIO_MODE_INPUT);
  
  while(1)
  {
    if (GPIO_ReadPin(GPIO_PORT_1, GPIO_PIN_1) == GPIO_PIN_RESET)
    {
      GPIO_WritePin(GPIO_PORT_1, GPIO_PIN_0, GPIO_PIN_RESET);
    }
    else
    {
      GPIO_WritePin(GPIO_PORT_1, GPIO_PIN_0, GPIO_PIN_SET);
    }
    
    GPIO_TogglePin(GPIO_PORT_1, GPIO_PIN_2);
  }
}