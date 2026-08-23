
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00100e88(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  
  FUN_00100590();
  iVar1 = PollSema(DAT_002074ac);
  if (DAT_002074ac == iVar1) {
    DAT_00207498 = (undefined4)param_1;
    ReferThreadStatus(uRam0025ba18,0x25ba20);
    lVar2 = FUN_00100e18(1);
    if (lVar2 == 0) {
      FUN_00115300(0);
      if (-1 < DAT_002074cc) {
        return 1;
      }
      while( true ) {
        while (lVar2 = FUN_00115a98(0x209000,0xffffffff80000593,0), lVar2 < 0) {
          if (0 < ram0x00207490) {
            FUN_00114ac8(0x24ea20);
          }
          iVar1 = 0x100000;
          do {
            iVar1 = iVar1 + -1;
          } while (iVar1 != -1);
        }
        if (DAT_00209024 != 0) break;
        iVar1 = 0x100000;
        do {
          iVar1 = iVar1 + -1;
        } while (iVar1 != -1);
      }
      DAT_002074cc = 0;
      return 1;
    }
    SignalSema(DAT_002074ac);
  }
  else if (0 < ram0x00207490) {
    FUN_00114ac8(0x24e9f8,param_1,DAT_00207498);
    return 0;
  }
  return 0;
}
