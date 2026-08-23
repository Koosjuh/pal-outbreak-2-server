FUNCTION FUN_000160a0 @ 0x000160a0 size=332
CALLERS (2): FUN_00016f74@0x00016f74, FUN_000161ec@0x000161ec
CALLEES (4): FUN_00013b50@0x00013b50, FUN_0000d658@0x0000d658, FUN_0000d8cc@0x0000d8cc, FUN_000100c4@0x000100c4

int FUN_000160a0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (*(undefined4 *)(param_1 + 0x30) = 0, *(int *)(param_1 + 0x28) == 0)) {
    iVar1 = -0x1fc;
  }
  else {
    *(undefined4 *)(param_1 + 0xc0) = 0;
    switch(*(undefined4 *)(param_1 + 0x28)) {
    case 1:
    case 2:
      *(undefined4 *)(param_1 + 0x30) = 0xfffffe03;
      *(undefined4 *)(param_1 + 0x28) = 0;
      FUN_0000d8cc(param_1 + 0xcc);
      FUN_000100c4();
      break;
    case 3:
    case 4:
    case 7:
      if (*(int *)(param_1 + 0x30) != 0) {
        return *(int *)(param_1 + 0x30);
      }
      do {
        if (*(int *)(param_1 + 0x84) == 0) break;
        iVar1 = FUN_0000d658(param_1 + 0xcc,param_2);
        if (iVar1 < 0) {
          return iVar1;
        }
      } while (*(int *)(param_1 + 0x30) == 0);
      if (*(int *)(param_1 + 0x30) != 0) {
        return *(int *)(param_1 + 0x30);
      }
      if (*(int *)(param_1 + 0x84) == 0) {
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x2010;
        uVar2 = 5;
        if (*(int *)(param_1 + 0x28) == 7) {
          uVar2 = 9;
        }
        *(undefined4 *)(param_1 + 0x28) = uVar2;
        FUN_00013b50(param_1);
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x400000;
      }
      break;
    default:
      return -0x1fd;
    }
    iVar1 = *(int *)(param_1 + 0x30);
  }
  return iVar1;
}


================================================================