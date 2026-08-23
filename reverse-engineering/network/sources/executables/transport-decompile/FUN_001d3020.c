
void FUN_001d3020(int param_1)

{
  byte bVar1;
  undefined1 auStack_80 [128];
  
  if (*(short *)(param_1 + 0xbc8) == 0) {
    FUN_00109728(auStack_80,0x24d160,*(undefined1 *)(param_1 + 0xbb0));
    bVar1 = *(byte *)(param_1 + 3);
  }
  else {
    if (*(short *)(param_1 + 0xbc8) == 0x5b) {
      FUN_00109728(auStack_80,0x24d170);
    }
    else {
      FUN_00109728(auStack_80,0x24d180,*(undefined1 *)(param_1 + 0xbb0));
    }
    bVar1 = *(byte *)(param_1 + 3);
  }
  FUN_001d31b0(auStack_80,bVar1 + 4);
  return;
}

