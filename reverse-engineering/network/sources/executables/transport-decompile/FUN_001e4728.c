
undefined4 FUN_001e4728(void)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uStack_60;
  byte bStack_5f;
  byte bStack_5e;
  byte bStack_5d;
  byte bStack_5b;
  byte bStack_5a;
  byte bStack_59;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 auStack_20 [2];
  
  auStack_20[0] = DAT_0025b7c8;
  sVar1 = FUN_00101d08(&uStack_60);
  if (sVar1 == 0) {
    FUN_00114ac8(0x2596a8,0);
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = (uint)(bStack_59 >> 4) * 10 + (bStack_59 & 0xf);
    iStack_4c = (uint)(bStack_5a >> 4) * 10 + (bStack_5a & 0xf);
    iStack_48 = (uint)(bStack_5b >> 4) * 10 + (bStack_5b & 0xf);
    iStack_44 = (uint)(bStack_5d >> 4) * 10 + (bStack_5d & 0xf);
    iStack_40 = (uint)(bStack_5e >> 4) * 10 + (bStack_5e & 0xf);
    iStack_3c = (uint)(bStack_5f >> 4) * 10 + (bStack_5f & 0xf);
    if (uVar3 < 0x46) {
      iStack_50 = uVar3 + 2000;
    }
    else {
      iStack_50 = uVar3 + 0x76c;
    }
    FUN_001e41fc(&uStack_30,0);
    FUN_00114ac8(0x2596c0,iStack_50,iStack_4c,iStack_48,iStack_44,iStack_40,iStack_3c);
    FUN_00114ac8(0x2596f0,uStack_30,uStack_28);
    FUN_00114ac8(0x259708);
    FUN_001e20a0(auStack_20,0);
    sVar1 = FUN_00101d08(&uStack_60);
    if (sVar1 == 0) {
      FUN_00114ac8(0x2596a8,0);
      uVar2 = 0xffffffff;
    }
    else {
      uVar3 = (uint)(bStack_59 >> 4) * 10 + (bStack_59 & 0xf);
      iStack_4c = (uint)(bStack_5a >> 4) * 10 + (bStack_5a & 0xf);
      iStack_48 = (uint)(bStack_5b >> 4) * 10 + (bStack_5b & 0xf);
      iStack_44 = (uint)(bStack_5d >> 4) * 10 + (bStack_5d & 0xf);
      iStack_40 = (uint)(bStack_5e >> 4) * 10 + (bStack_5e & 0xf);
      iStack_3c = (uint)(bStack_5f >> 4) * 10 + (bStack_5f & 0xf);
      if (uVar3 < 0x46) {
        iStack_50 = uVar3 + 2000;
      }
      else {
        iStack_50 = uVar3 + 0x76c;
      }
      FUN_001e41fc(&uStack_30,0);
      FUN_00114ac8(0x2596c0,iStack_50,iStack_4c,iStack_48,iStack_44,iStack_40,iStack_3c);
      FUN_00114ac8(0x2596f0,uStack_30,uStack_28);
      FUN_001e41fc(&uStack_30,0);
      FUN_00114ac8(0x2596f0,uStack_30,uStack_28);
      FUN_00114ac8(0x259718);
      auStack_20[0] = 0x1dcd650000000000;
      FUN_001e20a0(auStack_20,0);
      FUN_001e41fc(&uStack_30,0);
      FUN_00114ac8(0x2596f0,uStack_30,uStack_28);
      uVar2 = 0;
    }
  }
  return uVar2;
}

