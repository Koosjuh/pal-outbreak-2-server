FUNCTION FUN_000067e4 @ 0x000067e4 size=96
CALLERS (4): FUN_00006844@0x00006844, FUN_00006a8c@0x00006a8c, FUN_00006560@0x00006560, FUN_00006978@0x00006978
CALLEES (0): 

undefined4 FUN_000067e4(undefined *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar2 = iVar2 + 1;
    if (&DAT_00016590 + (iVar1 >> 0x10) * 0x1c == param_1) {
      (&DAT_000165a8)[(iVar1 >> 0x10) * 0xe] = 0;
      return 0;
    }
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 4);
  return 0xffffffff;
}


================================================================