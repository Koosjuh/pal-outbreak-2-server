FUNCTION FUN_00001b8c @ 0x00001b8c size=40
CALLERS (2): FUN_00000b60@0x00000b60, FUN_00000ac0@0x00000ac0
CALLEES (0): 

void FUN_00001b8c(undefined1 *param_1,undefined1 param_2,uint param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = param_1;
  if (param_3 != 0) {
    do {
      *puVar1 = param_2;
      uVar2 = uVar2 + 1;
      puVar1 = param_1 + uVar2;
    } while (uVar2 < param_3);
  }
  return;
}


================================================================