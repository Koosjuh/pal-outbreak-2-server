FUNCTION FUN_00006b10 @ 0x00006b10 size=192
CALLERS (1): FUN_00008a8c@0x00008a8c
CALLEES (2): FUN_0000b0ac@0x0000b0ac, FUN_00006630@0x00006630

void FUN_00006b10(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 8) == -0x1fffffff) {
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x14) = 2;
  }
  else {
    uVar2 = 0x16;
    if (*(int *)(*(int *)(param_1 + 0x1a0) + 0x14) == 1) {
      uVar2 = 0x12;
    }
    FUN_00006630(param_1,uVar2,param_2);
    uVar1 = FUN_0000b0ac();
    *(undefined4 *)(param_2 + 0x14) = 1;
    DAT_0001b6f8 = 1;
    *(uint *)(param_2 + 0x18) = (uVar1 & 0x7fffffff) % 100 + 1;
  }
  return;
}


================================================================