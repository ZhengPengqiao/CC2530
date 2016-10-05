#include "SYSPOWER.h"

void sysPowerMode(ENUM_SYSPOWER mode)
{
  if( mode > 0 && mode < 4 )
  {
    SLEEPCMD |= mode;
    PCON = 0x01;
  }
  else
  {
    PCON = 0x00;
  }
}