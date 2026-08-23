FUNCTION FUN_0001380c @ 0x0001380c size=836
CALLERS (2): FUN_00015a28@0x00015a28, FUN_00013fd4@0x00013fd4
CALLEES (5): FUN_00016d00@0x00016d00, FUN_00017540@0x00017540, FUN_00012eb0@0x00012eb0, FUN_00012c00@0x00012c00, FUN_00013264@0x00013264

void FUN_0001380c(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  
  iVar1 = *(int *)(param_1 + 0x68) + 1;
  *(int *)(param_1 + 0x68) = iVar1;
  if (0xb < iVar1) {
    FUN_00012c00();
    FUN_00013264(param_1,4,*(undefined4 *)(param_1 + 0x3c),0,0);
    *(undefined4 *)(param_1 + 0x34) = 0xfffffe0c;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x4000000;
    FUN_00016d00(param_1,0xfffffe02);
    return;
  }
  iVar5 = *(int *)(param_1 + 0x5c) << 1;
  iVar1 = 64000;
  if (iVar5 < 64000) {
    iVar1 = iVar5;
  }
  *(int *)(param_1 + 0x5c) = iVar1;
  if (*(int *)(param_1 + 0x68) == 1) {
    iVar1 = *(int *)(param_1 + 0x4c);
    if (*(int *)(param_1 + 0x40) < *(int *)(param_1 + 0x4c)) {
      iVar1 = *(int *)(param_1 + 0x40);
    }
    *(int *)(param_1 + 0x50) = iVar1;
  }
  else if ((2 < *(int *)(param_1 + 0x68)) && (*(int *)(param_1 + 0xdc) != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0xdc) + 0x18) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x54) << 1;
  iVar5 = *(int *)(param_1 + 0x50) >> 1;
  if (iVar1 <= iVar5) {
    iVar1 = iVar5;
  }
  iVar5 = *(int *)(param_1 + 0xdc);
  *(int *)(param_1 + 0x50) = iVar1;
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x54);
  if (iVar5 == 0) {
    uVar6 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x84);
    }
    iVar5 = FUN_00012eb0(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),0,uVar6);
    *(int *)(param_1 + 0xdc) = iVar5;
    if (iVar5 == 0) {
      if (*(int *)(param_1 + 0xc) == 0) {
        uVar2 = 0xffffffd8;
      }
      else {
        uVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x84) - 0x28;
      }
      goto LAB_000139b0;
    }
  }
  uVar2 = 0x218;
  if (*(int *)(iVar5 + 0x18) != 0) {
    uVar2 = *(int *)(iVar5 + 0x18) - 0x28;
  }
LAB_000139b0:
  if ((int)uVar2 < 1) {
    uVar2 = 0x5b4;
  }
  iVar1 = *(int *)(param_1 + 0x38);
  while( true ) {
    uVar8 = 0;
    iVar7 = 0;
    iVar5 = *(int *)(param_1 + 0x3c) - iVar1;
    if ((((*(uint *)(param_1 + 0x2c) & 4) != 0) && (0 < iVar5)) &&
       (iVar1 == *(int *)(param_1 + 0x58))) {
      uVar8 = 2;
      iVar7 = 1;
    }
    if ((((*(uint *)(param_1 + 0x2c) & 0x20) != 0) && (0 < iVar5)) &&
       (iVar1 + iVar5 == *(int *)(param_1 + 0x3c))) {
      uVar8 = uVar8 | 1;
      iVar7 = iVar7 + 1;
    }
    uVar3 = *(uint *)(param_1 + 0x54);
    if (iVar5 - iVar7 < (int)*(uint *)(param_1 + 0x54)) {
      uVar3 = iVar5 - iVar7;
    }
    uVar4 = uVar2;
    if ((int)uVar3 < (int)uVar2) {
      uVar4 = uVar3;
    }
    iVar5 = *(int *)(param_1 + 0x4c);
    if (*(int *)(param_1 + 0x40) < *(int *)(param_1 + 0x4c)) {
      iVar5 = *(int *)(param_1 + 0x40);
    }
    uVar3 = iVar5 - ((iVar1 - *(int *)(param_1 + 0x38)) - iVar7);
    if (uVar4 < uVar3) {
      uVar3 = uVar4;
    }
    iVar5 = uVar3 + iVar7;
    if ((int)uVar3 < 0) {
      uVar3 = 0;
      iVar5 = iVar7;
    }
    if (iVar5 < 1) break;
    if ((*(uint *)(param_1 + 0x2c) & 0x80) != 0) {
      uVar8 = uVar8 | 0x10;
    }
    uVar6 = FUN_00017540();
    *(undefined4 *)(param_1 + 0xac) = uVar6;
    *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x5c);
    DAT_0001b9e8 = DAT_0001b9e8 + 1;
    iVar5 = FUN_00013264(param_1,uVar8,iVar1,*(undefined4 *)(param_1 + 0x70),uVar3);
    if (iVar5 < 0) {
      return;
    }
    iVar1 = iVar1 + iVar5 + iVar7;
  }
  return;
}


================================================================