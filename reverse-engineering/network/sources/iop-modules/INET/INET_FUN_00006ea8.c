FUNCTION FUN_00006ea8 @ 0x00006ea8 size=248
CALLERS (11): FUN_0000709c@0x0000709c, FUN_0000dcf8@0x0000dcf8, FUN_00001108@0x00001108, FUN_00007e28@0x00007e28, FUN_00015f04@0x00015f04, FUN_00006478@0x00006478, FUN_00000344@0x00000344, FUN_00015430@0x00015430, FUN_00017f30@0x00017f30, FUN_0000029c@0x0000029c, FUN_00016368@0x00016368
CALLEES (0): 

undefined4 FUN_00006ea8(int param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_2 != 0xffffffff) && (param_2 != 0)) {
    if ((param_1 == 0) ||
       ((uVar1 = *(uint *)(param_1 + 0x70), uVar1 == 0 || ((*(uint *)(param_1 + 0x48) & 4) == 0))))
    {
      return 0;
    }
    if (param_2 == *(uint *)(param_1 + 0x78)) {
      return 1;
    }
    if (param_2 == (uVar1 & *(uint *)(param_1 + 0x74))) {
      return 1;
    }
    if ((int)uVar1 < 0) {
      if ((uVar1 & 0xc0000000) == 0x80000000) {
        param_2 = param_2 & 0xffff;
        if (param_2 == 0xffff) {
          return 1;
        }
      }
      else {
        param_2 = param_2 & 0xff;
        if ((uVar1 & 0xe0000000) != 0xc0000000) {
          return 0;
        }
        if (param_2 == 0xff) {
          return 1;
        }
      }
    }
    else {
      param_2 = param_2 & 0xffffff;
      if (param_2 == 0xffffff) {
        return 1;
      }
    }
    if (param_2 != 0) {
      return 0;
    }
  }
  return 1;
}


================================================================