FUNCTION FUN_00011dcc @ 0x00011dcc size=100
CALLERS (1): FUN_00012248@0x00012248
CALLEES (1): FUN_00014efc@0x00014efc

int FUN_00011dcc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_20 = 0x2000000;
  local_1c = 0;
  local_14 = param_5;
  local_18 = param_3;
  local_10 = param_4;
  iVar1 = FUN_00014efc(&local_20);
  if (0 < iVar1) {
    (&DAT_000288b0)[param_1] = iVar1;
    iVar1 = 0;
  }
  return iVar1;
}


================================================================