FUNCTION FUN_0000fce0 @ 0x0000fce0 size=252
CALLERS (0): 
CALLEES (3): FUN_0000d3d4@0x0000d3d4, FUN_0000d214@0x0000d214, FUN_0000d41c@0x0000d41c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000fce0(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0000d3d4();
  if (iVar1 == 0) {
    if (param_2 == 0x52534c56) {
      iVar1 = FUN_0000d214(param_1);
    }
    else {
      piVar2 = (int *)0x0;
      if ((((((uint)param_1 & 3) == 0) && (ram0x0001b2e0 <= param_1)) && (param_1 < DAT_0001b2e4))
         && (piVar2 = (int *)*param_1, *piVar2 != 0x496e6574)) {
        piVar2 = (int *)0x0;
      }
      iVar1 = -0x200;
      if (piVar2 != (int *)0x0) {
        iVar1 = -0x201;
        if ((code *)piVar2[5] != FUN_00000000) {
          iVar1 = (*(code *)piVar2[5])(param_1);
        }
      }
    }
    FUN_0000d41c();
  }
  return iVar1;
}


================================================================