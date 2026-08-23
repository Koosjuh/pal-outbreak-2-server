FUNCTION FUN_00014380 @ 0x00014380 size=172
CALLERS (1): FUN_0001442c@0x0001442c
CALLEES (2): FUN_00017bf4@0x00017bf4, FUN_00017ad8@0x00017ad8

undefined4 FUN_00014380(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  if ((*(uint *)(param_1 + 0x2c) & 0x1000) == 0) {
    uVar1 = FUN_00017bf4(*(undefined4 *)(param_1 + 200));
    uVar2 = *(uint *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 200) = uVar1;
    if ((uVar2 & 0x800) == 0) {
      iVar3 = *(int *)(param_1 + 0x60) >> 3;
      if (iVar3 < 1) {
        iVar3 = 10;
      }
      if (200 < iVar3) {
        iVar3 = 200;
      }
      *(uint *)(param_1 + 0x2c) = uVar2 | 0x800;
      uVar1 = FUN_00017ad8(FUN_00014330,param_1,iVar3);
      *(undefined4 *)(param_1 + 200) = uVar1;
      uVar1 = 0;
    }
    else {
      *(uint *)(param_1 + 0x2c) = uVar2 & 0xfffff7ff;
      uVar1 = 1;
    }
  }
  return uVar1;
}


================================================================