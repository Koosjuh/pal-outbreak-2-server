
undefined4 FUN_00199f10(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar2 = FUN_0019a2f0();
  lVar3 = FUN_0019a300(uVar2,2);
  if (lVar3 == 0) {
    lVar3 = FUN_0019a350(uVar2,2,0);
    if (lVar3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)((int)lVar3 + 4);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

