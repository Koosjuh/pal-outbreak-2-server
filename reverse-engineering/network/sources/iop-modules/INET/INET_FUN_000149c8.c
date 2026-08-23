FUNCTION FUN_000149c8 @ 0x000149c8 size=268
CALLERS (0): 
CALLEES (3): FUN_00013744@0x00013744, FUN_00012ab0@0x00012ab0, FUN_0001442c@0x0001442c

undefined4 FUN_000149c8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 0x12) == 2) {
      *(undefined4 *)(param_1 + 0x28) = 3;
      *(undefined4 *)(param_1 + 0xc0) = 75000;
      iVar1 = *(int *)(param_2 + 4);
      *(int *)(param_1 + 0x70) = iVar1;
      *(int *)(param_1 + 0x74) = iVar1 + *(int *)(param_1 + 0x90);
      uVar2 = FUN_00012ab0();
      *(undefined4 *)(param_1 + 0x58) = uVar2;
      *(undefined4 *)(param_1 + 0x3c) = uVar2;
      *(undefined4 *)(param_1 + 0x38) = uVar2;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0xa082;
      param_4 = FUN_0001442c(param_1,param_2,param_4);
    }
    else {
      FUN_00013744(param_1,param_2);
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_1 + 0x24);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_1 + 0x24);
  }
  return param_4;
}


================================================================