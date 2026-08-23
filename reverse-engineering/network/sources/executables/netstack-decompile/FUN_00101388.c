
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00101388(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  if (0 < ram0x00207490) {
    FUN_00114ac8(0x24ea68);
  }
  FUN_00100590();
  iVar1 = PollSema(DAT_002074ac);
  uVar2 = 6;
  if (DAT_002074ac == iVar1) {
    lVar3 = FUN_00100e18(1);
    if (lVar3 == 0) {
      FUN_00115300(0);
      if (DAT_002074c8 < 0) {
        while( true ) {
          while (lVar3 = FUN_00115a98(0x25bc50,0xffffffff8000059a,0), lVar3 < 0) {
            if (0 < ram0x00207490) {
              FUN_00114ac8(0x24ea80);
            }
            iVar1 = 0x100000;
            do {
              iVar1 = iVar1 + -1;
            } while (iVar1 != -1);
          }
          iVar1 = 0x100000;
          if (iRam0025bc74 != 0) break;
          do {
            iVar1 = iVar1 + -1;
          } while (iVar1 != -1);
        }
        DAT_002074c8 = 0;
      }
      uRam0025bc90 = (undefined4)param_1;
      FUN_00115250(0x25bc90,4);
      lVar3 = FUN_00115c68(0x25bc50,0,0,0x25bc90,4,0x208680,4,0);
      if (-1 < lVar3) {
        if (0 < ram0x00207490) {
          FUN_00114ac8(0x24eaa0);
        }
        uVar2 = DAT_20208680;
        SignalSema(DAT_002074ac);
        return uVar2;
      }
    }
    SignalSema(DAT_002074ac);
    uVar2 = 6;
    if (param_1 == 8) {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}
