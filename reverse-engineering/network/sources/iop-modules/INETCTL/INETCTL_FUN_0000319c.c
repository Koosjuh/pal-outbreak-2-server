FUNCTION FUN_0000319c @ 0x0000319c size=108
CALLERS (0): 
CALLEES (2): FUN_00000148@0x00000148, FUN_00000104@0x00000104

undefined4 FUN_0000319c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  FUN_00000104();
  param_1[1] = DAT_000046fc;
  puVar1 = param_1;
  if (DAT_000046fc != (undefined4 *)0x0) {
    *DAT_000046fc = param_1;
    puVar1 = DAT_000046f8;
  }
  DAT_000046f8 = puVar1;
  DAT_000046fc = param_1;
  *param_1 = 0;
  param_1[3] = &_gp_1;
  FUN_00000148();
  return 0;
}


================================================================