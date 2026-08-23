FUNCTION FUN_000161ec @ 0x000161ec size=380
CALLERS (0): 
CALLEES (6): FUN_0000d658@0x0000d658, FUN_000160a0@0x000160a0, FUN_00012c60@0x00012c60, FUN_00016d00@0x00016d00, FUN_00009eec@0x00009eec, FUN_00012c00@0x00012c00

int FUN_000161ec(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res4 [3];
  
  iVar1 = -0x1fd;
  if ((*(uint *)(param_1 + 0x2c) & 0x2000000) == 0) {
    local_res4[0] = param_2;
    iVar1 = FUN_000160a0(param_1,local_res4);
    if ((-1 < iVar1) || (iVar1 == -0x1fd)) {
      *(undefined4 *)(param_1 + 0x94) = 0;
      uVar2 = FUN_00009eec(*(undefined4 *)(param_1 + 0x98));
      *(undefined4 *)(param_1 + 0x9c) = uVar2;
      *(undefined4 *)(param_1 + 0x98) = uVar2;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x200000;
      if ((*(int *)(param_1 + 0x30) == 0) && (*(int *)(param_1 + 0x28) != 10)) {
        while (*(int *)(param_1 + 0x28) != 0) {
          iVar1 = FUN_0000d658(param_1 + 0xcc,local_res4);
          if (iVar1 < 0) goto LAB_000162d0;
          if ((*(int *)(param_1 + 0x30) != 0) || (*(int *)(param_1 + 0x28) == 10)) break;
        }
      }
      iVar1 = *(int *)(param_1 + 0x30);
    }
LAB_000162d0:
    if (iVar1 == -500) {
      if ((*(uint *)(param_1 + 0x2c) & 0x1000000) != 0) {
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x2000000;
        return -500;
      }
      FUN_00016d00(param_1,0xfffffe0b);
    }
    else if (iVar1 == -0x1f5) {
      return -0x1f5;
    }
    if (param_1 != 0) {
      if (*(int *)(param_1 + 0x28) == 0) {
        FUN_00012c60(param_1);
      }
      else {
        FUN_00012c00(param_1);
      }
    }
  }
  return iVar1;
}


================================================================