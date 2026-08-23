FUNCTION FUN_00007d78 @ 0x00007d78 size=200
CALLERS (4): FUN_0000678c@0x0000678c, FUN_0000632c@0x0000632c, FUN_00006b50@0x00006b50, FUN_00005f6c@0x00005f6c
CALLEES (1): FUN_0000810c@0x0000810c

void FUN_00007d78(undefined4 param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (0x7ff < param_3) {
    param_3 = 0x7ff;
  }
  FUN_0000810c(&DAT_000096a8,param_1);
  iVar2 = 0;
  iVar1 = 0;
  if (0 < param_3) {
    do {
      iVar1 = iVar1 + 1;
      FUN_0000810c("%02x ",*param_2);
      if (iVar1 == 0x10) {
        iVar1 = 0;
        FUN_0000810c(&DAT_000096b4);
      }
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 1;
    } while (iVar2 < param_3);
  }
  if (iVar1 != 0) {
    FUN_0000810c(&DAT_000096b4);
  }
  return;
}


================================================================