FUNCTION FUN_006313a0 @ 0x006313a0  size=252
CALLERS (1): FUN_006314a0@0x006314a0
CALLEES (5): FUN_00637540@0x00637540, FUN_00635ab0@0x00635ab0, FUN_00630c50@0x00630c50, FUN_006322c0@0x006322c0, FUN_00637260@0x00637260
----------------------------------------------------------------

void FUN_006313a0(void)

{
  long lVar1;
  uint extraout_a0_lo;
  uint uVar2;
  
  if ((*(char *)(iRam00715da8 + 0x2f) == '\0') && (lVar1 = FUN_00630c50(), lVar1 == 0)) {
    *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) | 1;
    lVar1 = FUN_00637260(5,iRam00715da8 + 0x1f,iRam00715da8 + 0x1e);
    if (lVar1 == 0) {
      uVar2 = (((extraout_a0_lo & 0xff) - 0x3a & 0xff) * 5 & 0xff) + 1;
      *(char *)(iRam00715da8 + 0x24) = (char)(uVar2 % 0x14);
      *(char *)(iRam00715da8 + 0x25) = (char)(uVar2 / 0x14);
      FUN_00637540();
      FUN_00635ab0();
      FUN_006322c0();
    }
    else {
      *(undefined4 *)(iRam00715da8 + 0x248) = 5;
    }
  }
  else {
    *(undefined4 *)(iRam00715da8 + 0x248) = 5;
  }
  return;
}



================================================================