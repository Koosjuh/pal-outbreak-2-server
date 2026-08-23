FUNCTION FUN_00000fa0 @ 0x00000fa0 size=200
CALLERS (1): FUN_00000730@0x00000730
CALLEES (1): FUN_00008138@0x00008138

undefined4 FUN_00000fa0(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 == 4) {
    if (param_2 == 0) {
      DAT_00009740 = 0;
      uVar1 = 0;
    }
    else if (param_3 < 0xff) {
      FUN_00008138(&DAT_00009740,param_2,param_3);
      (&DAT_00009740)[param_3] = 0;
      uVar1 = 0;
    }
  }
  else if (param_1 == 5) {
    if (param_2 == 0) {
      DAT_00009840 = 0;
      uVar1 = 0;
    }
    else if (param_3 < 0xff) {
      FUN_00008138(&DAT_00009840,param_2,param_3);
      (&DAT_00009840)[param_3] = 0;
      uVar1 = 0;
    }
  }
  return uVar1;
}


================================================================