FUNCTION FUN_006134b0 @ 0x006134b0  size=120
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (2): FUN_006146e0@0x006146e0, FUN_0060f880@0x0060f880
----------------------------------------------------------------

void FUN_006134b0(void)

{
  undefined8 uVar1;
  short extraout_a1_lo;
  char cVar2;
  
  cVar2 = '\0';
  do {
    uVar1 = FUN_0060f880((int)*(char *)(iRam0070d1c0 + 0x1c) + (int)cVar2);
    FUN_006146e0(0x65,extraout_a1_lo * 0x1c + 0xc4,uVar1);
    cVar2 = cVar2 + '\x01';
  } while (cVar2 < '\x03');
  return;
}



================================================================