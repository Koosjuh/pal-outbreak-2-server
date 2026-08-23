FUNCTION FUN_0000626c @ 0x0000626c size=128
CALLERS (1): FUN_00006740@0x00006740
CALLEES (2): FUN_00004150@0x00004150, FUN_00005f2c@0x00005f2c

undefined4 FUN_0000626c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00004150(param_1,0x2c,2);
  *(int *)(param_1 + 0x18) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 3;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x14) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x20) = 0xffffffff;
    uVar2 = FUN_00005f2c(param_1,*(undefined4 *)(param_1 + 4),FUN_0000574c,0);
  }
  return uVar2;
}


================================================================