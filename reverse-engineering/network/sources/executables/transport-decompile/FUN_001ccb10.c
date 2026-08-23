
undefined4 FUN_001ccb10(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined1 auStack_100 [256];
  
  iVar1 = FUN_0010a6b0(param_1,0x5c);
  FUN_00109eb8(auStack_100,iVar1 + 1);
  FUN_0010bca0(auStack_100);
  lVar3 = FUN_00109d70(auStack_100,0x24c990);
  if (lVar3 == 0) {
    uVar2 = 0x40;
  }
  else {
    lVar3 = FUN_00109d70(auStack_100,0x24c9a0);
    uVar2 = 0x80;
    if (lVar3 != 0) {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

