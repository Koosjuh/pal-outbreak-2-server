FUNCTION FUN_00001b04 @ 0x00001b04 size=88
CALLERS (1): FUN_00000b60@0x00000b60
CALLEES (0): 

void FUN_00001b04(undefined4 *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined4 *)(param_2 + uVar2);
      uVar2 = uVar2 + 4;
      *param_1 = *puVar1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_3);
  }
  return;
}


================================================================