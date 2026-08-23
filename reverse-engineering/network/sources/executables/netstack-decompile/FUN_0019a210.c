
undefined4 FUN_0019a210(void)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_00199f70();
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = FUN_0019a350(lVar2,0x50000,0);
    if (lVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)((int)lVar2 + 4);
    }
  }
  return uVar1;
}

