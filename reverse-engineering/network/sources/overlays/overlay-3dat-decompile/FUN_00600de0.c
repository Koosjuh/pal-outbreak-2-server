FUNCTION FUN_00600de0 @ 0x00600de0  size=176
CALLERS (0): 
CALLEES (1): FUN_005c0d30@0x005c0d30
----------------------------------------------------------------

void FUN_00600de0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 uStack_10;
  
  uVar3 = *param_1;
  if (cRam006c4b90 != '\x06') {
    func_0x00106b60(0x6c79ac,0,0xec0);
    uStack_10 = (char)uVar3;
    uVar2 = 0;
    if (uStack_10 == '\0') {
      iVar1 = 0;
      do {
        iVar1 = (iVar1 * 4 + uVar2 * -5) * 0x10;
        FUN_005c0d30(uVar2 & 0xffff,iVar1 + 0x6c7c2c,iVar1 + 0x6c7c3c,iVar1 + 0x6c7c50);
        uVar2 = uVar2 + 1;
        iVar1 = uVar2 * 0x10;
      } while ((int)uVar2 < 4);
    }
  }
  return;
}



================================================================