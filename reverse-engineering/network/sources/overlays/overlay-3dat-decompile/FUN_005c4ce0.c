FUNCTION FUN_005c4ce0 @ 0x005c4ce0  size=52
CALLERS (1): FUN_005b5fb0@0x005b5fb0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c4ce0(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = 0x188;
  puVar3 = (undefined1 *)0x6fc2d8;
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