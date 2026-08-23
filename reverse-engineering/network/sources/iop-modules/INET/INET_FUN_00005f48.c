FUNCTION FUN_00005f48 @ 0x00005f48 size=236
CALLERS (1): FUN_00010418@0x00010418
CALLEES (2): FUN_00005c7c@0x00005c7c, FUN_0000a9c0@0x0000a9c0

undefined4 FUN_00005f48(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_20 [2];
  
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x48) & 0x20) == 0) {
      return 0xfffffe00;
    }
    iVar1 = FUN_00005c7c();
    if (iVar1 != 0) {
      if (param_4 != 4) {
        return 0xfffffe00;
      }
      if (param_2 == 0x10f) {
        FUN_0000a9c0(param_3,local_20,4);
        if (-1 < local_20[0]) {
          *(int *)(iVar1 + 0x78) = local_20[0];
          return 0;
        }
      }
      else {
        if (param_2 != 0x110) {
          return 0xfffffe00;
        }
        FUN_0000a9c0(param_3,local_20,4);
        if (-1 < local_20[0]) {
          *(int *)(iVar1 + 0x7c) = local_20[0];
          return 0;
        }
      }
    }
  }
  return 0xfffffe00;
}


================================================================