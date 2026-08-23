FUNCTION FUN_005bdc30 @ 0x005bdc30  size=52
CALLERS (1): FUN_005b3590@0x005b3590
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005bdc30(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = 0x802;
  puVar3 = (undefined1 *)0x6cc668;
  do {
    iVar2 = iVar2 + -1;
    uVar1 = puVar3[1];
    *param_1 = *puVar3;
    puVar3 = puVar3 + 2;
    param_1[1] = uVar1;
    param_1 = param_1 + 2;
  } while (0 < iVar2);
  return 0;
}



================================================================