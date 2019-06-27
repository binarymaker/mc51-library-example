#include "mc51-library.h"

void main()
{
  while(1)
  {
    GPIO_WritePin(GPIO_PORT_1, GPIO_PIN_0, GPIO_PIN_RESET);
  }
}