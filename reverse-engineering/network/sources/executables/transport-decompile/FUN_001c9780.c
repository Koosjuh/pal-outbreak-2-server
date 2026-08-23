
undefined4 FUN_001c9780(int param_1)

{
  undefined4 uVar1;
  
  bRam0035ccb2 = bRam0035ccb2 + 1;
  if (bRam0035ccb2 < 3) {
    if (-1 < *(int *)(param_1 + 0x1c)) {
      FUN_001ee650();
      FUN_001ee680(param_1 + 0x1c);
    }
    *(undefined1 *)(param_1 + 0xc) = 0;
    uVar1 = 1;
    *(undefined1 *)(param_1 + 0xd) = 0;
    *(undefined1 *)(param_1 + 0xe) = 0;
    *(undefined1 *)(param_1 + 0xf) = 0;
    *(undefined2 *)(param_1 + 0x10) = 0;
    *(undefined2 *)(param_1 + 0x12) = 0;
    *(undefined2 *)(param_1 + 0x14) = 0;
    *(undefined2 *)(param_1 + 0x16) = 0;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

