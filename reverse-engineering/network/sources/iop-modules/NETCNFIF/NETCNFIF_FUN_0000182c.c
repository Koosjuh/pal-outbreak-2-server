FUNCTION FUN_0000182c @ 0x0000182c size=300
CALLERS (1): FUN_00001a20@0x00001a20
CALLEES (2): FUN_000028f8@0x000028f8, FUN_00002744@0x00002744

int FUN_0000182c(int param_1,int param_2)

{
  int iVar1;
  
  FUN_000028f8(&DAT_00006370,0x60);
  DAT_00006378 = 3;
  DAT_00006374 = *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x154);
  if (DAT_00006374 == (undefined4 *)0x0) {
    *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x150) = &DAT_00006370;
  }
  else {
    *DAT_00006374 = &DAT_00006370;
  }
  DAT_00006370 = 0;
  *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x154) = &DAT_00006370;
  if (param_2 == 0) {
    iVar1 = FUN_00002744(&DAT_0000637c,0);
    if (((-1 < iVar1) && (iVar1 = FUN_00002744(&DAT_00006390,0), -1 < iVar1)) &&
       (iVar1 = FUN_00002744(&DAT_000063a4,0), -1 < iVar1)) {
      DAT_000063b8 = 0;
    }
  }
  else {
    iVar1 = FUN_00002744(&DAT_0000637c,0);
    if (((-1 < iVar1) && (iVar1 = FUN_00002744(&DAT_00006390,param_2), -1 < iVar1)) &&
       (iVar1 = FUN_00002744(&DAT_000063a4,0), -1 < iVar1)) {
      DAT_000063b8 = DAT_000063b8 | 4;
    }
  }
  return iVar1;
}


================================================================