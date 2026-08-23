
void FUN_001d7104(int param_1)

{
  uint uVar1;
  long lVar2;
  
  uVar1 = *(uint *)(param_1 + 0x80);
  if (uVar1 == 2) {
    if (*(int *)(param_1 + 0x7c) + 500U < *(uint *)(param_1 + 0x4fc)) {
      lVar2 = FUN_001eb2d4(*(int *)(param_1 + 0x60) + 8);
      if (lVar2 == 0) {
        FUN_001d6ee0(param_1);
        *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x4fc);
        *(undefined4 *)(param_1 + 0x80) = 3;
      }
      else if ((uint)(*(int *)(param_1 + 0x7c) + *(int *)(param_1 + 0x51c)) <
               *(uint *)(param_1 + 0x4fc)) {
        FUN_001d94b0(param_1);
      }
    }
  }
  else if (uVar1 < 3) {
    if ((uVar1 == 1) &&
       ((uint)(*(int *)(param_1 + 0x7c) + *(int *)(param_1 + 0x51c)) < *(uint *)(param_1 + 0x4fc)))
    {
      FUN_001d94b0(param_1);
    }
  }
  else if ((uVar1 == 3) &&
          ((uint)(*(int *)(param_1 + 0x51c) + *(int *)(param_1 + 0x7c)) < *(uint *)(param_1 + 0x4fc)
          )) {
    FUN_001d94b0(param_1);
  }
  return;
}

