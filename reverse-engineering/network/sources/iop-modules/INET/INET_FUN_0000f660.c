FUNCTION FUN_0000f660 @ 0x0000f660 size=232
CALLERS (0): 
CALLEES (2): FUN_0000d3d4@0x0000d3d4, FUN_0000d41c@0x0000d41c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000f660(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0000d3d4();
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
    if ((((((uint)param_1 & 3) == 0) && (ram0x0001b2e0 <= param_1)) && (param_1 < DAT_0001b2e4)) &&
       (piVar2 = (int *)*param_1, *piVar2 != 0x496e6574)) {
      piVar2 = (int *)0x0;
    }
    iVar1 = -0x200;
    if (piVar2 != (int *)0x0) {
      if ((code *)piVar2[2] == FUN_00000000) {
        iVar1 = -0x201;
      }
      else {
        iVar1 = (*(code *)piVar2[2])(param_1,param_2);
      }
    }
    FUN_0000d41c();
  }
  return iVar1;
}


================================================================