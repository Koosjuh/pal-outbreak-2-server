FUNCTION FUN_00013b50 @ 0x00013b50 size=1064
CALLERS (7): FUN_00015430@0x00015430, FUN_000160a0@0x000160a0, FUN_00016368@0x00016368, FUN_00016f74@0x00016f74, FUN_00014330@0x00014330, FUN_000169bc@0x000169bc, FUN_00015f04@0x00015f04
CALLEES (5): FUN_000130cc@0x000130cc, FUN_00017540@0x00017540, FUN_00012eb0@0x00012eb0, FUN_00013264@0x00013264, FUN_00009f70@0x00009f70

void FUN_00013b50(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint local_28 [2];
  
  if (*(int *)(param_1 + 0x28) == 0) {
    return;
  }
  if ((*(uint *)(param_1 + 0x2c) & 0xf000) == 0x8000) {
    uVar2 = *(uint *)(param_1 + 0x90) - *(int *)(param_1 + 0x94);
    if ((int)uVar2 < 1) {
      uVar2 = 0;
    }
    if ((uVar2 << 2 < *(uint *)(param_1 + 0x90)) || (uVar2 < *(uint *)(param_1 + 0x78))) {
      uVar2 = 0;
    }
    uVar3 = *(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x70);
    if ((int)uVar3 <= (int)uVar2) {
      uVar3 = uVar2;
    }
    if ((*(int *)(param_1 + 0x70) + uVar3) - *(int *)(param_1 + 0x74) <
        (uint)(*(int *)(param_1 + 0x90) >> 1)) {
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffff7fff;
    }
  }
  if ((*(uint *)(param_1 + 0x2c) & 0xf000) == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0xdc);
  if (iVar4 == 0) {
    uVar8 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      uVar8 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x84);
    }
    iVar4 = FUN_00012eb0(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),0,uVar8);
    *(int *)(param_1 + 0xdc) = iVar4;
    if (iVar4 == 0) {
      if (*(int *)(param_1 + 0xc) == 0) {
        iVar5 = -0x28;
      }
      else {
        iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 0x84) + -0x28;
      }
      goto LAB_00013cbc;
    }
  }
  iVar5 = 0x218;
  if (*(int *)(iVar4 + 0x18) != 0) {
    iVar5 = *(int *)(iVar4 + 0x18) + -0x28;
  }
LAB_00013cbc:
  if (iVar5 < 1) {
    iVar5 = 0x5b4;
  }
  do {
    uVar2 = 0;
    iVar10 = *(int *)(param_1 + 0x3c);
    iVar4 = iVar5;
    if (*(int *)(param_1 + 0x54) < iVar5) {
      iVar4 = *(int *)(param_1 + 0x54);
    }
    iVar7 = iVar4;
    if (*(int *)(param_1 + 0x80) < iVar4) {
      iVar7 = *(int *)(param_1 + 0x80);
    }
    iVar6 = iVar7;
    if (iVar7 < 1) {
      if (0 < *(int *)(param_1 + 0x68)) {
        return;
      }
    }
    else {
      FUN_00009f70(param_1 + 0x84,iVar10 - *(int *)(param_1 + 0x38),0,1,local_28);
      if ((local_28[0] & 0x20) == 0) {
        if (0 < *(int *)(param_1 + 0x68)) {
          return;
        }
        iVar6 = *(int *)(param_1 + 0x4c);
        if (*(int *)(param_1 + 0x40) < *(int *)(param_1 + 0x4c)) {
          iVar6 = *(int *)(param_1 + 0x40);
        }
        iVar6 = iVar6 - (*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38));
        if (iVar7 < iVar6) {
          iVar6 = iVar7;
        }
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        if ((((0 < iVar6) && (iVar6 < iVar4)) && (0 < *(int *)(param_1 + 0x8c))) &&
           ((*(uint *)(param_1 + 0x2c) & 0x40000) == 0)) {
LAB_00013ef8:
          if (((0 < *(int *)(param_1 + 0x80)) &&
              (*(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x2000,
              *(int *)(param_1 + 0x40) == 0)) && (*(int *)(param_1 + 0xb0) < 1)) {
            *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x5c);
            *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0x5c);
          }
          if (0 < *(int *)(param_1 + 0x40)) {
            *(undefined4 *)(param_1 + 0xb4) = 0;
          }
          return;
        }
      }
    }
    uVar3 = *(uint *)(param_1 + 0x2c);
    bVar1 = (uVar3 & 2) != 0;
    if (bVar1) {
      uVar2 = 2;
      *(uint *)(param_1 + 0x2c) = uVar3 | 4;
      uVar3 = *(uint *)(param_1 + 0x2c);
    }
    uVar9 = (uint)bVar1;
    if ((uVar3 & 0x10) != 0) {
      uVar2 = uVar2 | 1;
      *(uint *)(param_1 + 0x2c) = uVar3 | 0x20;
      uVar9 = uVar9 + 1;
    }
    uVar3 = *(uint *)(param_1 + 0x2c);
    *(uint *)(param_1 + 0x2c) = uVar3 & 0xffffffed;
    if ((uVar3 & 0x80) != 0) {
      uVar2 = uVar2 | 0x10;
    }
    if ((int)(iVar6 + uVar9) < 1) {
      if (((uVar3 & 0x9000) == 0) || ((uVar3 & 0xf000) == 0x2000)) goto LAB_00013ef8;
    }
    else {
      *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) - iVar6;
      *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + iVar6;
      *(uint *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + iVar6 + uVar9;
      if (*(int *)(param_1 + 0xb0) < 1) {
        uVar8 = FUN_00017540();
        *(undefined4 *)(param_1 + 0xac) = uVar8;
        *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x5c);
      }
    }
    if (*(int *)(param_1 + 0x28) == 10) {
      FUN_000130cc(param_1);
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffff0fff;
    iVar4 = FUN_00013264(param_1,uVar2,iVar10,*(undefined4 *)(param_1 + 0x70),iVar6);
    if (iVar4 < 0) goto LAB_00013ef8;
  } while( true );
}


================================================================