FUNCTION FUN_00000730 @ 0x00000730 size=288
CALLERS (0): 
CALLEES (6): FUN_00001950@0x00001950, FUN_00000fa0@0x00000fa0, FUN_0000557c@0x0000557c, FUN_000051d0@0x000051d0, FUN_00002b04@0x00002b04, FUN_00000f84@0x00000f84

undefined4 FUN_00000730(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  switch(param_1) {
  case 1:
    if (param_3 == 4) {
      DAT_00009704 = *param_2;
      FUN_00001950();
      uVar1 = 0;
    }
    break;
  case 2:
    if (param_3 == 4) {
      DAT_00009700 = *param_2;
      FUN_00002b04();
      FUN_0000557c(DAT_00009700);
      uVar1 = 0;
    }
    break;
  case 3:
    if (param_3 == 4) {
      if (*param_2 == 0) {
        uVar1 = 0;
      }
      else {
        if (*param_2 != 1) {
          return 0xffffffff;
        }
        uVar1 = 1;
      }
      FUN_00000f84(uVar1);
      uVar1 = 0;
    }
    break;
  case 4:
  case 5:
    uVar1 = FUN_00000fa0();
    break;
  case 9:
    if (param_3 == 4) {
      uVar1 = FUN_000051d0(DAT_0000970c,*param_2);
    }
  }
  return uVar1;
}


================================================================