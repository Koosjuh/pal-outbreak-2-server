FUNCTION FUN_005d67d0 @ 0x005d67d0  size=56
CALLERS (4): FUN_005d6920@0x005d6920, FUN_005d8840@0x005d8840, FUN_005d71a0@0x005d71a0, FUN_005d70b0@0x005d70b0
CALLEES (0): 
----------------------------------------------------------------

undefined4 * FUN_005d67d0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)*param_1;
  puVar2 = param_2;
  while (puVar1 != param_2) {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = param_1;
    param_1 = puVar1;
  }
  return puVar2;
}



================================================================