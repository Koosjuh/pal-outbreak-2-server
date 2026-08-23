FUNCTION FUN_0000fb40 @ 0x0000fb40 size=416
CALLERS (0): 
CALLEES (4): FUN_0000d3d4@0x0000d3d4, FUN_0000e180@0x0000e180, FUN_0000a9c0@0x0000a9c0, FUN_0000d41c@0x0000d41c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000fb40(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                uint param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 local_30 [2];
  
  if (param_2 == 0) {
    return -0x200;
  }
  if (param_3 < 0) {
    return -0x200;
  }
  if (DAT_0001b9d4 <= DAT_0001b9e0) {
    return -0x1f8;
  }
  iVar1 = FUN_0000d3d4();
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((((((uint)param_1 & 3) != 0) || (param_1 < ram0x0001b2e0)) || (DAT_0001b2e4 <= param_1)) ||
     (piVar2 = (int *)*param_1, *piVar2 != 0x496e6574)) {
    piVar2 = (int *)0x0;
  }
  if (piVar2 != (int *)0x0) {
    if (piVar2[7] == 0) {
      iVar1 = -0x201;
      goto LAB_0000fca4;
    }
    iVar1 = FUN_0000e180(param_5);
    if (iVar1 == 0) {
      if (0xffff < param_6) {
        return -0x1fa;
      }
      FUN_0000a9c0(param_5 + 4,local_30,4);
      iVar1 = (*(code *)piVar2[7])(param_1,param_2,param_3,param_4,local_30[0],param_6,param_7);
      goto LAB_0000fca4;
    }
  }
  iVar1 = -0x200;
LAB_0000fca4:
  FUN_0000d41c();
  return iVar1;
}


================================================================