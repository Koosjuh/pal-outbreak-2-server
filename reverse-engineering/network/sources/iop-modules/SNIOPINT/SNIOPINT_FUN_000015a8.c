FUNCTION FUN_000015a8 @ 0x000015a8 size=164
CALLERS (0): 
CALLEES (2): FUN_00003818@0x00003818, FUN_00003810@0x00003810

undefined4 FUN_000015a8(short param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 1;
    if ((short)param_2[4] < 0x801) {
      FUN_00003818(DAT_00009420);
      DAT_00008c12 = *param_2;
      DAT_00008c14 = param_2[4];
      DAT_00008c18 = *(undefined4 *)(param_2 + 6);
      *(undefined **)(param_2 + 10) = &DAT_00008c20;
      uVar1 = 0;
    }
  }
  else {
    DAT_00008c10 = 1;
    FUN_00003810(DAT_00009420);
    uVar1 = 0;
  }
  return uVar1;
}


================================================================