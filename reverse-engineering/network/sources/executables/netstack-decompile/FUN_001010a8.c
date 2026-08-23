
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_001010a8(int param_1)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  
  lVar2 = FUN_00100e18(1);
  uVar3 = 0;
  if (lVar2 == 0) {
    FUN_00115300(0);
    uRam0025ba18 = GetThreadId();
    DAT_002074a4 = 1;
    DAT_002074d4 = DAT_002074d4 + 1;
    DAT_002074c0 = 0xffffffff;
    DAT_002074c4 = 0xffffffff;
    DAT_002074bc = 0xffffffff;
    DAT_002074cc = 0xffffffff;
    DAT_002074c8 = 0xffffffff;
    DAT_002074b8 = 0;
    DAT_002074d0 = 0xffffffff;
    while( true ) {
      while (lVar2 = FUN_00115a98(0x25bc28,0xffffffff80000592,0), lVar2 < 0) {
        if (0 < ram0x00207490) {
          FUN_00114ac8(0x24ea38,lVar2,DAT_002074d4);
        }
        iVar1 = 0x100000;
        do {
          iVar1 = iVar1 + -1;
        } while (iVar1 != -1);
      }
      if (iRam0025bc4c != 0) break;
      iVar1 = 0x100000;
      do {
        iVar1 = iVar1 + -1;
      } while (iVar1 != -1);
    }
    DAT_002074d0 = 0;
    iRam0025bc80 = param_1;
    FUN_00115250(0x25bc80,4);
    lVar2 = FUN_00115c68(0x25bc28,0,0,0x25bc80,4,0x208680,0x10,0);
    if (lVar2 < 0) {
      DAT_002074a4 = 0;
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
      if (DAT_2020868c != 0xff) {
        if (DAT_2020868c == 0xfe) {
          ram0x00207490 = 1;
        }
        else {
          iVar1 = DAT_20208684 + 0xff;
          if (-1 < DAT_20208684) {
            iVar1 = DAT_20208684;
          }
          if (iVar1 >> 8 < 2) {
            uVar3 = 2;
          }
          else {
            iVar1 = DAT_20208688 + 0xff;
            if (-1 < DAT_20208688) {
              iVar1 = DAT_20208688;
            }
            if (iVar1 >> 8 < 2) {
              uVar3 = 2;
            }
          }
        }
      }
      DAT_002074a4 = 0;
      if (((param_1 < 0) || (param_1 < 2)) || (param_1 != 5)) {
        FUN_00100590();
        FUN_001007c0();
      }
      else {
        if (0 < ram0x00207490) {
          FUN_00114ac8(0x24ea58);
        }
        FUN_00100648();
        DAT_002074a8 = 0xffffffff;
        DAT_002074ac = 0xffffffff;
        DAT_002074a0 = 0xffffffff;
      }
    }
  }
  return uVar3;
}
