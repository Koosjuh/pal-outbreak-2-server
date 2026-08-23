FUNCTION FUN_005c0920 @ 0x005c0920  size=52
CALLERS (3): FUN_005b5d20@0x005b5d20, FUN_005b5ac0@0x005b5ac0, FUN_005b6570@0x005b6570
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c0920(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = 0x8a;
  puVar3 = (undefined1 *)0x6cd672;
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