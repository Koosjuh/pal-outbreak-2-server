FUNCTION FUN_005cd5d0 @ 0x005cd5d0  size=120
CALLERS (0): 
CALLEES (1): FUN_005dfee0@0x005dfee0
----------------------------------------------------------------

void FUN_005cd5d0(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((uVar1 < 500 && (*(int *)(iRam00701068 + uVar1 * 4 + 0x5ffc0) != 0))) {
    FUN_005dfee0();
    uVar1 = uVar1 + 1 & 0xffff;
  }
  *(undefined1 *)(iRam00701070 + 2) = 3;
  return;
}



================================================================