FUNCTION FUN_0000ff60 @ 0x0000ff60 size=356
CALLERS (0): 
CALLEES (4): FUN_0000d3d4@0x0000d3d4, FUN_0000feb4@0x0000feb4, FUN_0000fddc@0x0000fddc, FUN_0000d41c@0x0000d41c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000ff60(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0000d3d4();
  if (iVar1 == 0) {
    if (param_1 == (int *)0x0) {
      if (param_2 == 1) {
        iVar1 = FUN_0000fddc(param_3,param_4);
      }
      else {
        iVar1 = -0x200;
        if (param_2 == 0x11) {
          iVar1 = FUN_0000feb4(param_3,param_4);
        }
      }
    }
    else if ((param_3 == 0) && (param_2 != 0x15)) {
      iVar1 = -0x200;
    }
    else {
      piVar2 = (int *)0x0;
      if ((((((uint)param_1 & 3) == 0) && (ram0x0001b2e0 <= param_1)) && (param_1 < DAT_0001b2e4))
         && (piVar2 = (int *)*param_1, *piVar2 != 0x496e6574)) {
        piVar2 = (int *)0x0;
      }
      iVar1 = -0x200;
      if (piVar2 != (int *)0x0) {
        if ((code *)piVar2[8] == FUN_00000000) {
          iVar1 = -0x201;
        }
        else {
          iVar1 = (*(code *)piVar2[8])(param_1,param_2,param_3,param_4);
        }
      }
    }
    FUN_0000d41c();
  }
  return iVar1;
}


================================================================