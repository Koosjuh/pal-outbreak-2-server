FUNCTION FUN_005bdd60 @ 0x005bdd60  size=48
CALLERS (1): FUN_005b6950@0x005b6950
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bdd60(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0x27;
  puVar2 = (undefined4 *)0x6cc064;
  do {
    iVar1 = iVar1 + -1;
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  } while (0 < iVar1);
  return;
}



================================================================