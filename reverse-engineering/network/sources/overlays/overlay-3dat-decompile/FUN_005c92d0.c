FUNCTION FUN_005c92d0 @ 0x005c92d0  size=136
CALLERS (1): FUN_005c8ed0@0x005c8ed0
CALLEES (1): FUN_005dfee0@0x005dfee0
----------------------------------------------------------------

void FUN_005c92d0(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    if (499 < uVar1) {
      return;
    }
    iVar2 = uVar1 * 4;
    if (*(int *)(iRam00701068 + iVar2 + 0x5ffc0) == 0) break;
    FUN_005dfee0();
    uVar1 = uVar1 + 1 & 0xffff;
    *(undefined4 *)(iRam00701068 + iVar2 + 0x5ffc0) = 0;
  }
  return;
}



================================================================