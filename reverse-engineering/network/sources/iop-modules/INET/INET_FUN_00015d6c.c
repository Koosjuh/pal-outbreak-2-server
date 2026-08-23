FUNCTION FUN_00015d6c @ 0x00015d6c size=304
CALLERS (1): FUN_0000f40c@0x0000f40c
CALLEES (3): FUN_00015cfc@0x00015cfc, FUN_00012ce8@0x00012ce8, FUN_00012ac8@0x00012ac8

int FUN_00015d6c(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  
  if (param_2 == 0xffffffff) {
    param_2 = FUN_00015cfc();
    param_2 = param_2 & 0xffff;
  }
  else if (0xfffe < param_2 - 1) {
    return -0x1f9;
  }
  if (param_1 == 0) {
    if (param_3 == 0) {
      return -0x1fa;
    }
    if ((int)param_4 < 1) {
      return -0x1fa;
    }
    bVar1 = 0xffff < (int)param_4;
  }
  else {
    bVar1 = 0xffff < param_4;
  }
  if (bVar1) {
    return -0x1fa;
  }
  if (param_1 == 0) {
    iVar2 = FUN_00012ce8(0,param_2 & 0xffff,param_3,param_4 & 0xffff);
  }
  else {
    iVar2 = FUN_00012ac8(0,0,param_2 & 0xffff,param_3,param_4 & 0xffff);
  }
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x28) == 0) {
      if (param_1 != 0) {
        *(short *)(iVar2 + 0x1c) = (short)param_2;
        *(int *)(iVar2 + 0x20) = param_3;
        *(short *)(iVar2 + 0x24) = (short)param_4;
        *(uint *)(iVar2 + 0x2c) = *(uint *)(iVar2 + 0x2c) | 1;
      }
      *(uint *)(iVar2 + 0x2c) = *(uint *)(iVar2 + 0x2c) | 0x20000;
      return iVar2;
    }
    return -0x1fb;
  }
  return -0x1f8;
}


================================================================