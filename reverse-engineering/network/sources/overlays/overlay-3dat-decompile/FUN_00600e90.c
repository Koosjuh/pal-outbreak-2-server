FUNCTION FUN_00600e90 @ 0x00600e90  size=184
CALLERS (0): 
CALLEES (1): FUN_005c0860@0x005c0860
----------------------------------------------------------------

void FUN_00600e90(undefined4 *param_1)

{
  uint uVar1;
  undefined1 uStack_10;
  
  if (cRam006c4b90 != '\x06') {
    uStack_10 = (char)*param_1;
    uVar1 = (uint)bRam006c4600;
    if (uStack_10 == '\0') {
      FUN_005c0860(bRam006c4600,(uVar1 - 1) * 0x15c + 0x6c0774);
      uRam006c4b96 = (ushort)*(byte *)(uVar1 * 0x15c + 0x6c0618);
    }
    else {
      *(undefined4 *)(uVar1 * 0x15c + 0x6c0618) = 0;
    }
  }
  return;
}



================================================================