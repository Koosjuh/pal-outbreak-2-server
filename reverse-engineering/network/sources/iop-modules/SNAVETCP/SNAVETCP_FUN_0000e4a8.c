FUNCTION FUN_0000e4a8 @ 0x0000e4a8 size=136
CALLERS (1): FUN_0000084c@0x0000084c
CALLEES (0): 

undefined4 FUN_0000e4a8(short param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)param_1;
  if (-1 < iVar1) {
    if ((iVar1 <= DAT_000168e0) && (iVar2 = (&DAT_00016190)[iVar1], iVar2 != 0)) {
      if (*(short *)(iVar2 + 2) < 0) {
        return 0xffffffff;
      }
      *(undefined2 *)(iVar2 + 2) = 0xffff;
      (&DAT_00016190)[iVar1] = 0;
      DAT_000168e0 = DAT_000168e0 + -1;
      return 0;
    }
  }
  return 0xffffffff;
}


================================================================