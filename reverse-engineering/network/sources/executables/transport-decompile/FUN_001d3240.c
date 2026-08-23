
void FUN_001d3240(void)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 auStack_80 [128];
  
  uVar1 = uRam003435d4;
  if (cRam00343577 == '\0') {
    FUN_00109728(auStack_80,0x24d1d0,0x24d1e0,uRam0034357a);
    lVar2 = FUN_001cb360(auStack_80,uVar1,1,0);
    if (lVar2 < 1) {
      func_0x00707340();
    }
    else {
      func_0x007073f0();
    }
  }
  else {
    FUN_00109728(auStack_80,0x24d1f8,uRam0034357a);
    lVar2 = FUN_001a0df0(auStack_80,uVar1);
    if (lVar2 == 0) {
      func_0x00707340();
    }
    else {
      func_0x007073f0();
    }
  }
  return;
}

