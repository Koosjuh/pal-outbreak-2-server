FUNCTION FUN_00001b5c @ 0x00001b5c size=48
CALLERS (1): FUN_000009cc@0x000009cc
CALLEES (0): 

void FUN_00001b5c(undefined1 *param_1,int param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = param_1;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined1 *)(param_2 + uVar3);
      uVar3 = uVar3 + 1;
      *puVar2 = *puVar1;
      puVar2 = param_1 + uVar3;
    } while (uVar3 < param_3);
  }
  return;
}


================================================================