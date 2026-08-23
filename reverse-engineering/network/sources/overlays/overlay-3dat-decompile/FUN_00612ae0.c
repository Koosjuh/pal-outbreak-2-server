FUNCTION FUN_00612ae0 @ 0x00612ae0  size=132
CALLERS (1): FUN_00614b90@0x00614b90
CALLEES (1): FUN_00614c80@0x00614c80
----------------------------------------------------------------

void FUN_00612ae0(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)(iRam0070d1c0 + 0x4b);
  if (bVar1 < 6) {
    switch(bVar1) {
    case 0:
      break;
    default:
      FUN_00614c80((char)bVar1 + -1,0,0);
      return;
    case 4:
      FUN_00614c80(2,0,0);
      break;
    case 5:
      FUN_00614c80(3,0,0);
    }
  }
  return;
}



================================================================