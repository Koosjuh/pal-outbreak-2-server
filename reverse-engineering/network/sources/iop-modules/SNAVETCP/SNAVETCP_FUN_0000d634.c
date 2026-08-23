FUNCTION FUN_0000d634 @ 0x0000d634 size=208
CALLERS (1): FUN_000100d4@0x000100d4
CALLEES (2): FUN_0000d42c@0x0000d42c, FUN_0000e08c@0x0000e08c

int FUN_0000d634(short param_1,byte param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 3) {
    iVar3 = (int)param_1;
    sVar1 = FUN_0000e08c(iVar3);
    if (sVar1 == 0) {
      iVar2 = DAT_00016180 + iVar3 * 0x17c;
      if (param_2 == 0) {
        *(byte *)(iVar2 + 0x13e) = *(byte *)(iVar2 + 0x13e) | 4;
        return 0;
      }
      if (param_2 == 2) {
        *(byte *)(iVar2 + 0x13e) = *(byte *)(iVar2 + 0x13e) | 0xc;
      }
      if (param_2 == 1) {
        *(byte *)(iVar2 + 0x13e) = *(byte *)(iVar2 + 0x13e) | 8;
      }
      sVar1 = FUN_0000d42c(iVar3);
      return (int)sVar1;
    }
  }
  return -4;
}


================================================================