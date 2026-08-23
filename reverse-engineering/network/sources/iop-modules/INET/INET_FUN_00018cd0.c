FUNCTION FUN_00018cd0 @ 0x00018cd0 size=188
CALLERS (2): FUN_0000cb4c@0x0000cb4c, FUN_0000f40c@0x0000f40c
CALLEES (2): FUN_00018c60@0x00018c60, FUN_00017f30@0x00017f30

int FUN_00018cd0(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0xffffffff) {
    param_2 = FUN_00018c60();
    param_2 = param_2 & 0xffff;
  }
  else if (0xfffe < param_2 - 1) {
    return -0x1f9;
  }
  if (param_4 < 0x10000) {
    iVar1 = FUN_00017f30(0,0,param_2 & 0xffff,param_3,param_4 & 0xffff);
    iVar2 = -0x1f8;
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 0xc) == 0) {
        *(undefined4 *)(iVar1 + 0xc) = 1;
        iVar2 = iVar1;
      }
      else {
        iVar2 = -0x1fb;
      }
    }
  }
  else {
    iVar2 = -0x1fa;
  }
  return iVar2;
}


================================================================