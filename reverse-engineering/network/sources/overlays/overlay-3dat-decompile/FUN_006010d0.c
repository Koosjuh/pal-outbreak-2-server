FUNCTION FUN_006010d0 @ 0x006010d0  size=156
CALLERS (0): 
CALLEES (2): FUN_005adc80@0x005adc80, FUN_005c0260@0x005c0260
----------------------------------------------------------------

void FUN_006010d0(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uStack_10;
  
  uVar2 = *param_1;
  if (cRam006c4b90 != '\x06') {
    uVar1 = FUN_005adc80(2);
    uStack_10 = (char)uVar2;
    if (uStack_10 == '\0') {
      FUN_005c0260(uVar1 & 0xffff,(uVar1 - 1) * 0x15c + 0x6c0778);
    }
    else {
      *(undefined1 *)((uVar1 - 1) * 0x15c + 0x6c0778) = 0;
    }
  }
  return;
}



================================================================