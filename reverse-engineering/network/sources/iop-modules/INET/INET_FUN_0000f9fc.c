FUNCTION FUN_0000f9fc @ 0x0000f9fc size=324
CALLERS (0): 
CALLEES (2): FUN_0000d3d4@0x0000d3d4, FUN_0000d41c@0x0000d41c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000f9fc(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = -0x200;
  if (((param_2 != 0) && (-1 < param_3)) && (iVar2 = -0x1f8, DAT_0001b9e0 < DAT_0001b9d4)) {
    iVar2 = FUN_0000d3d4();
    if (iVar2 == 0) {
      piVar1 = (int *)0x0;
      if (((((uint)param_1 & 3) == 0) && (ram0x0001b2e0 <= param_1)) &&
         ((param_1 < DAT_0001b2e4 && (piVar1 = (int *)*param_1, *piVar1 != 0x496e6574)))) {
        piVar1 = (int *)0x0;
      }
      iVar2 = -0x200;
      if (piVar1 != (int *)0x0) {
        if (piVar1[4] == 0) {
          iVar2 = -0x201;
        }
        else {
          iVar2 = (*(code *)piVar1[4])(param_1,param_2,param_3,param_4,param_5);
        }
      }
      FUN_0000d41c();
    }
  }
  return iVar2;
}


================================================================