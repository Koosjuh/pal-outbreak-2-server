FUNCTION FUN_006314a0 @ 0x006314a0  size=192
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (5): FUN_00630c70@0x00630c70, FUN_00630c10@0x00630c10, FUN_00631560@0x00631560, FUN_00631670@0x00631670, FUN_006313a0@0x006313a0
----------------------------------------------------------------

void FUN_006314a0(void)

{
  long lVar1;
  ulong extraout_a0;
  ulong uVar2;
  
  lVar1 = FUN_00630c10();
  if (lVar1 == 0) {
    lVar1 = FUN_00630c70();
    uVar2 = extraout_a0 & 0xff;
    if (lVar1 == 0) {
      if (uVar2 == 0x3d) {
        *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
        FUN_00631670();
      }
      else if (((uVar2 == 0x3c) || (uVar2 == 0x3b)) || (uVar2 == 0x3a)) {
        FUN_00631560();
      }
      else {
        *(undefined4 *)(iRam00715da8 + 0x248) = 5;
      }
    }
    else {
      FUN_006313a0();
    }
  }
  else {
    *(undefined4 *)(iRam00715da8 + 0x248) = 5;
  }
  return;
}



================================================================