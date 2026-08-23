FUNCTION FUN_00013670 @ 0x00013670 size=160
CALLERS (1): FUN_000137cc@0x000137cc
CALLEES (0): 

undefined4 FUN_00013670(short param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < (int)((uint)DAT_00016fb0 << 0x10)) {
    iVar1 = 0;
    do {
      if ((*(int *)((int)&DAT_00016fa0 + iVar1) != 0) &&
         (*(short *)(*(int *)((int)&DAT_00016fa0 + iVar1) + 2) == param_1)) break;
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (iVar2 < (short)DAT_00016fb0);
  }
  if (iVar2 != (short)DAT_00016fb0) {
    return (&DAT_00016fa0)[iVar2];
  }
  return 0;
}


================================================================