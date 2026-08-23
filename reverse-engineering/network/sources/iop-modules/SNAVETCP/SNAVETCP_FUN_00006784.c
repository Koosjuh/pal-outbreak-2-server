FUNCTION FUN_00006784 @ 0x00006784 size=96
CALLERS (4): FUN_00006844@0x00006844, FUN_00006a8c@0x00006a8c, FUN_000060c0@0x000060c0, FUN_00006978@0x00006978
CALLEES (0): 

undefined4 FUN_00006784(undefined *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar2 = iVar2 + 1;
    if (&DAT_00016600 + (iVar1 >> 0x10) * 0x14 == param_1) {
      (&DAT_00016610)[(iVar1 >> 0x10) * 10] = 0;
      return 0;
    }
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 0x20);
  return 0xffffffff;
}


================================================================