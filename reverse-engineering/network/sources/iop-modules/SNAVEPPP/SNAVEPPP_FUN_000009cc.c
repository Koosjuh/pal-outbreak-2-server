FUNCTION FUN_000009cc @ 0x000009cc size=244
CALLERS (4): FUN_00006aec@0x00006aec, FUN_00001bb4@0x00001bb4, FUN_000067bc@0x000067bc, FUN_00000ac0@0x00000ac0
CALLEES (2): FUN_00000b60@0x00000b60, FUN_00001b5c@0x00001b5c

void FUN_000009cc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + 0x10) >> 3 & 0x3f;
  uVar1 = *(uint *)(param_1 + 0x10) + param_3 * 8;
  *(uint *)(param_1 + 0x10) = uVar1;
  if (uVar1 < param_3 * 8) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar1 = -uVar2 + 0x40;
  if (param_3 < uVar1) {
    uVar3 = 0;
  }
  else {
    FUN_00001b5c(param_1 + uVar2 + 0x18,param_2,uVar1);
    FUN_00000b60(param_1,param_1 + 0x18);
    uVar2 = -uVar2;
    while (uVar3 = uVar1, uVar2 + 0x7f < param_3) {
      FUN_00000b60(param_1,param_2 + uVar3);
      uVar1 = uVar3 + 0x40;
      uVar2 = uVar3;
    }
    uVar2 = 0;
  }
  FUN_00001b5c(param_1 + uVar2 + 0x18,param_2 + uVar3,param_3 - uVar3);
  return;
}


================================================================