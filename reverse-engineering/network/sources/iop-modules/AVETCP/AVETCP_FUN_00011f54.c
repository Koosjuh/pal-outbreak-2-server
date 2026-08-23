FUNCTION FUN_00011f54 @ 0x00011f54 size=88
CALLERS (1): FUN_00012248@0x00012248
CALLEES (1): FUN_00014f90@0x00014f90

int FUN_00011f54(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = param_3;
  local_c = param_4;
  iVar1 = FUN_00014f90(&local_18);
  if (0 < iVar1) {
    *(int *)(&DAT_000288f0 + param_1 * 4) = iVar1;
    iVar1 = 0;
  }
  return iVar1;
}


================================================================