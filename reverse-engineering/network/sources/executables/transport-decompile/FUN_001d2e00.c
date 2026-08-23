
void FUN_001d2e00(int param_1)

{
  char cVar1;
  undefined1 auStack_80 [128];
  
  if (*(char *)(param_1 + 0xc8c) != -1) {
    cVar1 = func_0x0061dca0(*(char *)(param_1 + 0xc8c));
    if (cVar1 != -1) {
      func_0x0072c7a0(*(undefined1 *)(param_1 + 3),cVar1);
      FUN_00109728(auStack_80,0x24d120,cVar1);
      FUN_001d31b0(auStack_80,*(byte *)(param_1 + 3) + 8);
    }
  }
  return;
}

