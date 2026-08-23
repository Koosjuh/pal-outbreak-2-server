FUNCTION FUN_00003fd0 @ 0x00003fd0 size=140
CALLERS (1): FUN_00011980@0x00011980
CALLEES (2): FUN_0000e738@0x0000e738, FUN_0000e944@0x0000e944

undefined4 FUN_00003fd0(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  sVar1 = FUN_0000e738();
  iVar3 = (int)sVar1;
  uVar2 = 0xffffffff;
  if (iVar3 != -1) {
    iVar4 = 0;
    if (0 < iVar3) {
      do {
        sVar1 = FUN_0000e944((int)(short)iVar4);
        iVar4 = iVar4 + 1;
        if (sVar1 != 0) {
          return 0xffffffff;
        }
      } while (iVar4 * 0x10000 >> 0x10 < iVar3);
    }
    uVar2 = 0;
  }
  return uVar2;
}


================================================================