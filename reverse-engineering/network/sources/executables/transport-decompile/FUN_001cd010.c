
undefined4 FUN_001cd010(ulong param_1,int param_2,undefined8 param_3,undefined1 param_4)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 uVar3;
  undefined1 auStack_100 [256];
  
  if ((param_2 == -1) && (param_2 = DAT_0024c7f8, DAT_0024c7f8 == -1)) {
    uVar3 = 0;
  }
  else {
    lVar2 = FUN_001cc170(param_2,param_1,1,0);
    if (lVar2 == 0) {
      uVar3 = 0;
    }
    else {
      FUN_00109728(auStack_100,0x24c9c8,(int)lVar2 + 0xf);
      FUN_00109ab0(auStack_100,0x24c9d8);
      uVar1 = uRam0036b9b8;
      lVar2 = FUN_001cb360(auStack_100,uRam0036b9b8,1,0);
      uVar3 = 0;
      if (0 < lVar2) {
        lVar2 = 0;
        if ((0x11ff < param_2) && (param_2 < 0x1400)) {
          lVar2 = 1;
        }
        if ((0x13ff < param_2) && (param_2 < 0x1800)) {
          lVar2 = 2;
        }
        uVar3 = 0;
        if ((lVar2 != 0) && (lVar2 = FUN_001cd500(lVar2,param_1 & 0xffff), uVar3 = 0, lVar2 != 0)) {
          FUN_001a1c30(param_3,uVar1,param_4,(int)lVar2 + 2);
          uVar3 = 1;
        }
      }
    }
  }
  return uVar3;
}

