FUNCTION FUN_00015f04 @ 0x00015f04 size=412
CALLERS (0): 
CALLEES (6): FUN_0000e4e8@0x0000e4e8, FUN_00013b50@0x00013b50, FUN_0000d658@0x0000d658, FUN_00013264@0x00013264, FUN_00006ea8@0x00006ea8, FUN_00012ab0@0x00012ab0

int FUN_00015f04(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
  if (*(int *)(param_1 + 0x28) == 0) {
    if ((*(uint *)(param_1 + 0x2c) & 0x800000) != 0) {
      return -0x1f5;
    }
  }
  else if (*(int *)(param_1 + 0x28) != 1) {
    return -0x1fb;
  }
  local_res4[0] = param_2;
  if ((*(uint *)(param_1 + 0x2c) & 1) == 0) {
    iVar2 = FUN_0000e4e8(*(undefined4 *)(param_1 + 0x10));
    *(int *)(param_1 + 0xc) = iVar2;
    if (iVar2 == 0) {
      return -0x202;
    }
    iVar2 = FUN_00006ea8(iVar2,*(undefined4 *)(param_1 + 0x10));
    if (iVar2 != 0) {
      return -0x1fa;
    }
    uVar1 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x70);
    }
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    uVar1 = FUN_00012ab0();
    *(undefined4 *)(param_1 + 0x58) = uVar1;
    *(undefined4 *)(param_1 + 0x3c) = uVar1;
    *(undefined4 *)(param_1 + 0x38) = uVar1;
    *(undefined4 *)(param_1 + 0x28) = 2;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffff7f | 0x2002;
    FUN_00013b50(param_1);
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x28) = 1;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  iVar2 = 0;
  do {
    if ((*(int *)(param_1 + 0x28) == 4) || (*(int *)(param_1 + 0x28) == 7)) break;
    iVar2 = FUN_0000d658(param_1 + 0xcc,local_res4);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = *(int *)(param_1 + 0x30);
  } while (iVar2 == 0);
  if ((*(int *)(param_1 + 0x28) == 3) && (*(int *)(param_1 + 0x30) == -0x1f5)) {
    FUN_00013264(param_1,4,*(undefined4 *)(param_1 + 0x3c),0,0);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return iVar2;
}


================================================================