FUNCTION FUN_005d6840 @ 0x005d6840  size=152
CALLERS (1): FUN_005d68e0@0x005d68e0
CALLEES (0): 
----------------------------------------------------------------

undefined4 * FUN_005d6840(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = param_1;
  do {
    puVar2 = puVar1;
    puVar1 = (undefined4 *)*puVar2;
  } while (puVar1 != (undefined4 *)0x0);
  puVar1 = (undefined4 *)*param_1;
  *param_1 = *puVar1;
  *puVar2 = puVar1;
  *puVar1 = 0;
  func_0x00106b60(puVar1 + 1,0,0x100);
  puVar1[0x41] = 0;
  func_0x00106b60(puVar1 + 0x42,0,2);
  if (param_2 == puVar1) {
    param_2 = (undefined4 *)*param_1;
  }
  return param_2;
}



================================================================