
void FUN_001d8e20(uint *param_1)

{
  uint uVar1;
  int iStack_1c;
  uint *puStack_14;
  
  FUN_001d8048(param_1);
  uVar1 = *param_1;
  if (uVar1 < 0xe0) {
    for (iStack_1c = 0; puStack_14 = param_1 + 1, iStack_1c < (int)uVar1; iStack_1c = iStack_1c + 1)
    {
      FUN_001d8048(puStack_14);
      param_1 = puStack_14;
    }
  }
  return;
}

