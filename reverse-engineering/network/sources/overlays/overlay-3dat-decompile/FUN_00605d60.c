FUNCTION FUN_00605d60 @ 0x00605d60  size=544
CALLERS (1): FUN_00606780@0x00606780
CALLEES (1): FUN_00605d00@0x00605d00
----------------------------------------------------------------

uint FUN_00605d60(undefined8 param_1,undefined8 param_2,int param_3,uint param_4)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = func_0x001ee430(param_1,0x35a714);
  if (lVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0xffffffff;
    if (sRam0035a714 == 4) {
      if ((cRam0070cdf0 == '\0') && (0xb < uRam0035a71a)) {
        lVar1 = func_0x001ee560(param_1,param_2,0xc);
        if (lVar1 != 0xc) {
          return 0xffffffff;
        }
        uRam0035a71a = uRam0035a71a - 0xc;
        cRam0070cdf0 = '\x01';
        uRam0070cdd8 = 0;
        uRam0070cde0 = (uint)(ushort)((ushort)*(byte *)((int)param_2 + 4) * 0x100 +
                                     (ushort)*(byte *)((int)param_2 + 5));
      }
      uVar2 = 0;
      if (cRam0070cdf0 != '\0') {
        uVar2 = uRam0070cde0 - uRam0070cdd8;
        if (uVar2 == 0) {
          FUN_00605d00();
          uVar2 = 1;
        }
        else {
          if ((int)(uint)uRam0035a71a < (int)uVar2) {
            uVar2 = (uint)uRam0035a71a;
          }
          if (param_4 - uRam0070cdd8 < uVar2) {
            uVar2 = param_4 - uRam0070cdd8;
          }
          if (0 < (int)uVar2) {
            lVar1 = func_0x001ee560(param_1,param_3 + uRam0070cdd8,(short)uVar2);
            if (lVar1 < 0) {
              return 0xffffffff;
            }
            uRam0070cdd8 = uRam0070cdd8 + (int)lVar1;
            if (uRam0070cde0 == uRam0070cdd8) {
              FUN_00605d00();
              return 1;
            }
            if (uRam0070cdd8 == param_4) {
              bRam0070cde8 = bRam0070cde8 + 1;
              uRam0070cdd8 = 0;
              uRam0070cde0 = uRam0070cde0 - param_4;
              return (uint)bRam0070cde8;
            }
          }
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}



================================================================