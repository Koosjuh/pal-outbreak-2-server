FUNCTION FUN_000041b0 @ 0x000041b0 size=164
CALLERS (2): FUN_00005828@0x00005828, FUN_00004ec4@0x00004ec4
CALLEES (1): FUN_0000e738@0x0000e738

int FUN_000041b0(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  sVar1 = FUN_0000e738();
  iVar3 = (int)sVar1;
  if ((iVar3 != -1) && (iVar4 = 0, 0 < iVar3)) {
    iVar2 = 0;
    do {
      iVar4 = iVar4 + 1;
      if ((&DAT_00022874)[(iVar2 >> 0x10) * 0xb] == param_1) {
        return iVar2 >> 0x10;
      }
      iVar2 = iVar4 * 0x10000;
    } while (iVar4 * 0x10000 >> 0x10 < iVar3);
  }
  return -1;
}


================================================================