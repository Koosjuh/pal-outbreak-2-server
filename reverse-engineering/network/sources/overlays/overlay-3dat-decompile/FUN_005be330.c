FUNCTION FUN_005be330 @ 0x005be330  size=748
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (9): FUN_005c4e60@0x005c4e60, FUN_005c7d40@0x005c7d40, FUN_005bce20@0x005bce20, FUN_005c6150@0x005c6150, FUN_005c7e30@0x005c7e30, FUN_005be270@0x005be270, FUN_005bf1e0@0x005bf1e0, FUN_005c4f00@0x005c4f00, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

undefined4 FUN_005be330(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  
  if (iRam006ca950 == 0) {
    uVar1 = 0;
  }
  else {
    sRam006cbcc4 = sRam006cbcc4 + 1;
    uRam006cbc74 = param_1;
    lVar3 = FUN_005c7d40();
    if (lVar3 == 0) {
      if (cRam006ff2ac != '\0') {
        FUN_005bce20(0);
      }
      lVar3 = FUN_005bf1e0(0);
      if (((lVar3 != 0) && (sRam00700682 != 0)) &&
         (sRam00700682 = sRam00700682 + -1, sRam00700682 == 0)) {
        sRam00700682 = 0;
        FUN_005c4e60();
      }
      if (((cRam006ff2b1 != '\0') && (cRam006ff2b0 != '\0')) &&
         ((-1 < iRam006febec &&
          ((iRam006febec = iRam006febec + -1, iRam006febec < 0 && (cRam006ff2b1 != '\x03')))))) {
        iRam006febec = 0;
        lVar3 = FUN_005c4f00();
        if (lVar3 == 0) {
          cRam006ff2b1 = '\x03';
          uVar2 = FUN_005bf1e0(2);
          if (*(ushort *)((uVar2 & 0xffff) * 0x144 + 0x6cfa2c) < 2) {
            FUN_005c7e30(7);
            FUN_005bdf90(0xb,0);
          }
          else {
            FUN_005bdf90(1,0);
          }
        }
        else if (cRam007006a6 != '\0') {
          uVar2 = FUN_005bf1e0(2);
          if (*(ushort *)((uVar2 & 0xffff) * 0x144 + 0x6cfa2c) < (ushort)bRam007006a4) {
            iRam006febec = iRam006febf0;
          }
          else {
            cRam006ff2b1 = '\x03';
            FUN_005bdf90(1,0);
          }
        }
      }
      if ((((cRam006ff2b1 != '\0') && (cRam006ff2b0 == '\0')) && (-1 < iRam006febf4)) &&
         (iRam006febf4 = iRam006febf4 + -1, iRam006febf4 < 0)) {
        if (cRam006ff2b2 == '\x01') {
          cRam006ff2b2 = '\x02';
          iRam006febf4 = 0x708;
          FUN_005c6150(uRam006febe8);
        }
        else if (cRam006ff2b2 == '\x02') {
          cRam006ff2b2 = '\0';
          FUN_005c7e30(0xc);
          FUN_005bdf90(0xb,0);
        }
        else if (cRam006ff2b2 == '\x03') {
          cRam006ff2b2 = '\x01';
          iRam006febf4 = 0x708;
        }
      }
      FUN_005be270();
      uVar1 = 1;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



================================================================