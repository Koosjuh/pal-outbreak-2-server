
void FUN_001d507c(int param_1,int param_2,short param_3)

{
  undefined2 uVar1;
  int iStack_1c;
  short sStack_18;
  
  iStack_1c = param_2;
  sStack_18 = param_3;
  if (param_2 != 0) {
    FUN_001069a8(param_1 + 0x4c,&iStack_1c,4);
    *(undefined4 *)(param_1 + 0xc) = 0;
    **(undefined4 **)(param_1 + 0x58) = 0;
    **(undefined4 **)(param_1 + 0x5c) = 0;
  }
  if (sStack_18 != 0) {
    uVar1 = FUN_001e234c(sStack_18);
    *(undefined2 *)(param_1 + 0x4a) = uVar1;
  }
  *(undefined2 *)(param_1 + 0x48) = 2;
  return;
}

