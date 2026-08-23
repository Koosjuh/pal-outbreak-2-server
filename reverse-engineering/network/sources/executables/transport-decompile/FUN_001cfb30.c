
void FUN_001cfb30(byte param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 auStack_100 [256];
  
  FUN_001cbc20(0x2a00);
  FUN_001a7b70(0x15,2);
  FUN_001a7b70(1,0x800);
  FUN_001a7b70(0x12,0x8000);
  FUN_001a7b70(0xc,0);
  FUN_001a7b70(0x66,1);
  FUN_001a7b70(0x62,1);
  FUN_001a7b70(0,0x20);
  FUN_001a7b70(2,0);
  uRam004052a8 = FUN_001ab460(0x240,8);
  uRam004052b8 = 0;
  if (cRam00343577 == '\0') {
    FUN_001cce80((uint)param_1 << 0x10,0xffffffffffffffff,0x404aa0,2);
  }
  else {
    FUN_00109728(auStack_100,0x24cb80,param_1);
    FUN_001a1750(auStack_100,0x404aa0,0x2a00,0x10002);
  }
  uVar1 = uRam003435bc;
  FUN_00109728(auStack_100,0x24cb90,0x24cba0,param_1);
  lVar2 = FUN_001cb360(auStack_100,uVar1,1,0);
  if (0 < lVar2) {
    FUN_001d24c0(uVar1);
  }
  return;
}

