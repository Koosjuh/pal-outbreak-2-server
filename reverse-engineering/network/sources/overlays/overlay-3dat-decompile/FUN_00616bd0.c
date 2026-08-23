FUNCTION FUN_00616bd0 @ 0x00616bd0  size=112
CALLERS (1): FUN_005aec70@0x005aec70
CALLEES (4): FUN_00637180@0x00637180, FUN_005b9110@0x005b9110, FUN_005b1d10@0x005b1d10, FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_00616bd0(undefined8 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)param_1;
  *puVar1 = 5;
  puVar1[1] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  FUN_005aec20();
  puVar1[0x443] = 2;
  FUN_005b1d10(param_1);
  FUN_005b9110(0x4c);
  FUN_00637180();
  func_0x00106b60(puVar1 + 0x1f5c,0,0xec0);
  return;
}



================================================================