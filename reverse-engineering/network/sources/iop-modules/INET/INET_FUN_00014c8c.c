FUNCTION FUN_00014c8c @ 0x00014c8c size=364
CALLERS (0): 
CALLEES (5): FUN_0001493c@0x0001493c, FUN_00012bc0@0x00012bc0, FUN_00016d00@0x00016d00, FUN_00013fd4@0x00013fd4, FUN_0001442c@0x0001442c

undefined4 FUN_00014c8c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 2) == 0) {
      iVar2 = FUN_00013fd4(param_1,param_2);
      if (-1 < iVar2) {
        *(uint *)(param_1 + 0x40) = (uint)*(ushort *)(param_2 + 0xe);
        *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_2 + 4);
        uVar1 = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_1 + 0x28) = 4;
        *(undefined4 *)(param_1 + 0xc0) = 0;
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x100000;
        *(undefined4 *)(param_1 + 0x48) = uVar1;
        param_4 = FUN_0001442c(param_1,param_2,param_4);
        if ((*(uint *)(param_1 + 0x2c) & 0x100) != 0) {
          *(undefined4 *)(param_1 + 0x28) = 7;
        }
      }
    }
    else {
      param_4 = FUN_0001493c(param_1,param_2,param_3,param_4);
    }
  }
  else if ((*(uint *)(param_1 + 0x2c) & 1) == 0) {
    *(undefined4 *)(param_1 + 0x34) = 0xfffffe01;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x4000000;
    FUN_00016d00();
  }
  else {
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xa0001;
    *(undefined4 *)(param_1 + 0x28) = 1;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_1 + 0x24);
    FUN_00012bc0();
  }
  return param_4;
}


================================================================