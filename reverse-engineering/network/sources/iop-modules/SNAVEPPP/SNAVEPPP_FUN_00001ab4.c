FUNCTION FUN_00001ab4 @ 0x00001ab4 size=80
CALLERS (1): FUN_00000ac0@0x00000ac0
CALLEES (0): 

void FUN_00001ab4(int param_1,undefined4 *param_2,uint param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined1 *)(param_1 + uVar2);
      *puVar1 = *(undefined1 *)param_2;
      puVar1[1] = (char)((uint)*param_2 >> 8);
      uVar2 = uVar2 + 4;
      puVar1[2] = (char)*(undefined2 *)((int)param_2 + 2);
      puVar1[3] = *(undefined1 *)((int)param_2 + 3);
      param_2 = param_2 + 1;
    } while (uVar2 < param_3);
  }
  return;
}


================================================================