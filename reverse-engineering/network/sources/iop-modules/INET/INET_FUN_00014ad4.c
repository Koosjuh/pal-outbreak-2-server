FUNCTION FUN_00014ad4 @ 0x00014ad4 size=440
CALLERS (0): 
CALLEES (4): FUN_00013744@0x00013744, FUN_00012bc0@0x00012bc0, FUN_00013fd4@0x00013fd4, FUN_0001442c@0x0001442c

undefined4 FUN_00014ad4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_2 + 4);
  iVar3 = *(int *)(param_2 + 8);
  if (((*(byte *)(param_2 + 0xd) & 0x10) == 0) ||
     ((0 < iVar3 - *(int *)(param_1 + 0x58) && (-1 < *(int *)(param_1 + 0x3c) - iVar3)))) {
    if ((*(byte *)(param_2 + 0xd) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0xfffffe02;
      FUN_00012bc0(param_1);
      *(undefined4 *)(param_1 + 0x34) = 0xfffffe02;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x4000000;
    }
    if ((*(byte *)(param_2 + 0xd) & 2) != 0) {
      *(int *)(param_1 + 0x70) = iVar2;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x80;
      *(int *)(param_1 + 0x74) = iVar2 + *(int *)(param_1 + 0x90);
      FUN_00013fd4(param_1,param_2,param_3);
      param_4 = FUN_0001442c(param_1,param_2,param_4);
      if ((*(uint *)(param_1 + 0x2c) & 8) == 0) {
        *(undefined4 *)(param_1 + 0x28) = 3;
        *(undefined4 *)(param_1 + 0xc0) = 75000;
      }
      else {
        uVar1 = *(ushort *)(param_2 + 0xe);
        *(undefined4 *)(param_1 + 0x28) = 4;
        uVar4 = *(uint *)(param_1 + 0x2c);
        *(int *)(param_1 + 0x44) = iVar2;
        *(int *)(param_1 + 0x48) = iVar3;
        *(uint *)(param_1 + 0x40) = (uint)uVar1;
        *(uint *)(param_1 + 0x2c) = uVar4 | 0x100000;
        if ((uVar4 & 0x100) != 0) {
          *(undefined4 *)(param_1 + 0x28) = 7;
        }
      }
    }
  }
  else {
    FUN_00013744(param_1,param_2,param_3);
  }
  return param_4;
}


================================================================