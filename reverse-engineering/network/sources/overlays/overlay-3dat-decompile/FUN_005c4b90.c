FUNCTION FUN_005c4b90 @ 0x005c4b90  size=52
CALLERS (1): FUN_005b53f0@0x005b53f0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c4b90(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = 0x94;
  puVar3 = (undefined1 *)0x6fc05a;
  do {
    iVar2 = iVar2 + -1;
    uVar1 = puVar3[1];
    *param_1 = *puVar3;
    puVar3 = puVar3 + 2;
    param_1[1] = uVar1;
    param_1 = param_1 + 2;
  } while (0 < iVar2);
  return;
}



================================================================