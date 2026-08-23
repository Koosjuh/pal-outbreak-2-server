FUNCTION FUN_005bd6e0 @ 0x005bd6e0  size=52
CALLERS (1): FUN_005b25c0@0x005b25c0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005bd6e0(undefined2 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar2 = 9;
  puVar3 = (undefined2 *)0x6cbe20;
  do {
    iVar2 = iVar2 + -1;
    uVar1 = param_1[1];
    *puVar3 = *param_1;
    param_1 = param_1 + 2;
    puVar3[1] = uVar1;
    puVar3 = puVar3 + 2;
  } while (0 < iVar2);
  return 0;
}



================================================================