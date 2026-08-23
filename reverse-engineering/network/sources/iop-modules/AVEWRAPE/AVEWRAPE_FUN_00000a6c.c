FUNCTION FUN_00000a6c @ 0x00000a6c size=172
CALLERS (0): 
CALLEES (2): FUN_000029bc@0x000029bc, FUN_000029c4@0x000029c4

undefined4 FUN_00000a6c(short param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 1;
    if ((short)param_2[4] < 0x381) {
      FUN_000029c4(DAT_00004db0);
      DAT_00004a26 = *param_2;
      DAT_00004a28 = param_2[4];
      DAT_00004a2c = *(undefined4 *)(param_2 + 6);
      *(undefined **)(param_2 + 10) = &DAT_00004a30;
      uVar1 = 0;
    }
  }
  else {
    DAT_00004a24 = DAT_00004a24 + 1;
    FUN_000029bc(DAT_00004db0);
    uVar1 = 0;
  }
  return uVar1;
}


================================================================