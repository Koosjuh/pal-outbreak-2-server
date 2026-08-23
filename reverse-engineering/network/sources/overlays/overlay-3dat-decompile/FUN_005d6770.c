FUNCTION FUN_005d6770 @ 0x005d6770  size=96
CALLERS (1): FUN_005d6920@0x005d6920
CALLEES (1): FUN_005dedc0@0x005dedc0
----------------------------------------------------------------

undefined4 * FUN_005d6770(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = param_1;
  puVar3 = (undefined4 *)0x0;
  do {
    puVar2 = puVar3;
    puVar3 = puVar1;
    puVar1 = (undefined4 *)*puVar3;
  } while ((undefined4 *)*puVar3 != (undefined4 *)0x0);
  *puVar3 = *param_1;
  *param_1 = puVar3;
  *puVar2 = 0;
  FUN_005dedc0(puVar3 + 1);
  puVar3[0x41] = 1;
  return puVar3;
}



================================================================