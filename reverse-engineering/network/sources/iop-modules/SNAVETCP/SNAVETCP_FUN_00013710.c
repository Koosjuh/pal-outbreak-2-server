FUNCTION FUN_00013710 @ 0x00013710 size=140
CALLERS (1): FUN_00014238@0x00014238
CALLEES (0): 

int FUN_00013710(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < (int)((uint)DAT_00016fb0 << 0x10)) {
    iVar1 = 0;
    do {
      if (*(int *)((int)&DAT_00016fa0 + iVar1) == 0) break;
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (iVar2 < (short)DAT_00016fb0);
  }
  if (iVar2 != (short)DAT_00016fb0) {
    (&DAT_00016fa0)[iVar2] = param_1;
    return iVar2;
  }
  return -1;
}


================================================================