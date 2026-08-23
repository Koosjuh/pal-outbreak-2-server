
void FUN_001d5688(int param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  long lVar4;
  
  lVar4 = FUN_001ebb90(param_1,0x2000);
  if (lVar4 == 0) {
    *(ushort *)(param_1 + 0x2c) = *(ushort *)(param_1 + 0x2c) | 0x4000;
    *(undefined4 *)(param_1 + 0x38) = param_2;
  }
  else {
    uVar1 = FUN_001e23dc(*(undefined2 *)(param_1 + 0x2c));
    uVar2 = FUN_001e234c(uVar1 | 0x4000);
    *(undefined2 *)(param_1 + 0x2c) = uVar2;
    uVar3 = FUN_001e2304(param_2);
    *(undefined4 *)(param_1 + 0x38) = uVar3;
  }
  return;
}

