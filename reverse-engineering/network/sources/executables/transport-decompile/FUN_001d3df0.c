
void FUN_001d3df0(void)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 auStack_100 [256];
  
  uVar1 = uRam003435bc;
  if (cRam00343577 == '\0') {
    FUN_00109728(auStack_100,0x24d4c0,0x24d4e0,uRam0034357a,uRam0034357a,uRam0034357c,uRam0034357e);
    lVar2 = FUN_001cb360(auStack_100,uVar1,1,0);
    if (0 < lVar2) {
      func_0x00729890(uVar1,lVar2);
    }
    FUN_00109728(auStack_100,0x24d500,0x24d520,uRam0034357a,uRam0034357a,uRam0034357c,uRam0034357e);
    lVar2 = FUN_001cb360(auStack_100,uVar1,1,0);
    if (0 < lVar2) {
      func_0x00729d90(uVar1,lVar2);
    }
  }
  else {
    FUN_00109728(auStack_100,0x24d540,uRam0034357a,uRam0034357c,uRam0034357e);
    lVar2 = FUN_001a0df0(auStack_100,uVar1);
    if (lVar2 != 0) {
      func_0x00729890(uVar1,lVar2);
    }
    FUN_00109728(auStack_100,0x24d560,uRam0034357a,uRam0034357c,uRam0034357e);
    lVar2 = FUN_001a0df0(auStack_100,uVar1);
    if (lVar2 != 0) {
      func_0x00729d90(uVar1,lVar2);
    }
  }
  func_0x0072b2f0();
  return;
}

