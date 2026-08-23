
void FUN_001d0040(void)

{
  long lVar1;
  int iVar2;
  undefined1 auStack_20 [32];
  
  FUN_001cbc20(0x2000);
  FUN_001a7b70(0x15,2);
  FUN_001a7b70(1,0);
  FUN_001a7b70(0x12,0);
  FUN_001a7b70(0x62,1);
  FUN_001a7b70(0xc,0);
  FUN_001a7b70(0x66,0);
  FUN_001a7b70(2,0);
  FUN_001a7b70(0x12,0);
  FUN_001a7b70(0,0);
  uRam003f49a8 = FUN_001ab460(0x400,4);
  uRam003f49b8 = 0;
  if (cRam00343577 == '\0') {
    FUN_001cce80(uRam0034357a,0xffffffffffffffff,0x3f41a0,2);
  }
  else {
    FUN_00106b60(auStack_20,0,0x20);
    FUN_00109728(auStack_20,0x24cc50,uRam0034357a);
    FUN_001a1750(auStack_20,0x3f41a0,0x2000,0x10002);
  }
  uRam003ce310 = 0;
  uRam003ce314 = 0;
  uRam003ce308 = 0x3f41a0;
  iVar2 = iRam003435bc + 0x2ff000;
  FUN_00106b60(auStack_20,0,0x20);
  FUN_00109728(auStack_20,0x24cc60,uRam0034357a);
  if (cRam00343577 != '\0') {
    FUN_00109728(auStack_20,0x24cc80,uRam0034357a);
  }
  lVar1 = FUN_001cb360(auStack_20,iVar2,0x10001,0);
  if (lVar1 != 0) {
    FUN_001069a8(0x3ce350,iVar2);
    uRam003ce30c = 0x3ce750;
  }
  return;
}

