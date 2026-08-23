FUNCTION FUN_000001a8 @ 0x000001a8 size=764
CALLERS (0): 
CALLEES (4): FUN_00000a40@0x00000a40, FUN_000008dc@0x000008dc, FUN_00000a38@0x00000a38, FUN_0000099c@0x0000099c

int * FUN_000001a8(int param_1,int *param_2)

{
  int iVar1;
  int local_18;
  int local_14;
  undefined4 local_10 [2];
  
  if (param_1 == 0) {
    local_18 = 0;
    FUN_00000a40(DAT_00000b60);
    for (local_14 = 0; local_14 < 0x21; local_14 = local_14 + 1) {
      if (*(int *)(local_14 * 0x10 + 0xbc8) != -1) {
        iVar1 = FUN_000008dc(local_14,local_10);
        if (iVar1 == 0) {
          *(undefined4 *)(local_14 * 0x10 + 0xbd4) = local_10[0];
          local_18 = local_18 + 1;
        }
        else {
          *(undefined4 *)(local_14 * 0x10 + 0xbc8) = 0xffffffff;
          *(undefined4 *)(local_14 * 0x10 + 0xbcc) = 0xffffffff;
          *(undefined4 *)(local_14 * 0x10 + 0xbd0) = 0xffffffff;
          *(undefined4 *)(local_14 * 0x10 + 0xbd4) = 0xffffffff;
        }
      }
    }
    FUN_00000a38(DAT_00000b60);
    *param_2 = local_18;
  }
  else if (param_1 == 1) {
    iVar1 = *param_2;
    if ((-1 < iVar1) && (iVar1 < 0x21)) {
      FUN_00000a40(DAT_00000b60);
      *param_2 = *(int *)(iVar1 * 0x10 + 0xbc8);
      param_2[1] = *(int *)(iVar1 * 0x10 + 0xbcc);
      param_2[2] = *(int *)(iVar1 * 0x10 + 0xbd0);
      param_2[3] = *(int *)(iVar1 * 0x10 + 0xbd4);
      FUN_00000a38(DAT_00000b60);
    }
  }
  else {
    FUN_0000099c(0xa74,param_1);
  }
  return param_2;
}


================================================================