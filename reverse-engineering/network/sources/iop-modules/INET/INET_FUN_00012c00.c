FUNCTION FUN_00012c00 @ 0x00012c00 size=96
CALLERS (4): FUN_000161ec@0x000161ec, FUN_00016d00@0x00016d00, FUN_0001380c@0x0001380c, FUN_00012c60@0x00012c60
CALLEES (1): FUN_00009eec@0x00009eec

void FUN_00012c00(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  uVar1 = FUN_00009eec(*(undefined4 *)(param_1 + 0x84));
  *(undefined4 *)(param_1 + 0x88) = uVar1;
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  uVar1 = FUN_00009eec(*(undefined4 *)(param_1 + 0x98));
  *(undefined4 *)(param_1 + 0x9c) = uVar1;
  *(undefined4 *)(param_1 + 0x98) = uVar1;
  uVar1 = FUN_00009eec(*(undefined4 *)(param_1 + 0xa4));
  *(undefined4 *)(param_1 + 0xa8) = uVar1;
  *(undefined4 *)(param_1 + 0xa4) = uVar1;
  return;
}


================================================================