
uint FUN_001ca590(int param_1)

{
  int iVar1;
  undefined4 uStack_4;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (-1 < *(int *)(param_1 + 0x1c)) {
    FUN_001ee650();
    FUN_001ee680(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  uStack_4 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 3)),
                            *(undefined1 *)(iVar1 + 4));
  *(undefined4 *)(param_1 + 0xd8) = 4;
  return uStack_4;
}

