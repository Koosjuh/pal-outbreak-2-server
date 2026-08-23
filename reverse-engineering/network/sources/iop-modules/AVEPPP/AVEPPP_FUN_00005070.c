FUNCTION FUN_00005070 @ 0x00005070 size=168
CALLERS (3): FUN_0000fd50@0x0000fd50, FUN_0000fde0@0x0000fde0, FUN_0000fe20@0x0000fe20
CALLEES (6): FUN_0001073c@0x0001073c, FUN_00005118@0x00005118, FUN_000061d8@0x000061d8, FUN_00006260@0x00006260, FUN_00005f04@0x00005f04, FUN_00010764@0x00010764

int FUN_00005070(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  
  if (param_1 == 1) {
    sVar1 = FUN_00005f04();
  }
  else if (param_1 == 0) {
    sVar1 = FUN_00005118(param_2);
  }
  else {
    if (param_1 == 2) {
      FUN_0001073c();
      sVar1 = FUN_000061d8(param_3);
    }
    else {
      if (param_1 != 3) {
        sVar1 = -99;
        goto LAB_00005104;
      }
      FUN_0001073c();
      sVar1 = FUN_00006260(param_3);
    }
    FUN_00010764();
  }
LAB_00005104:
  return (int)sVar1;
}


================================================================