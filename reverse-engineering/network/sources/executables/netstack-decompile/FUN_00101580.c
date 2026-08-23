
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00101580(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  
  if (0 < ram0x00207490) {
    FUN_00114ac8(0x24eab8);
  }
  FUN_00100590();
  iVar2 = PollSema(DAT_002074b0);
  if (DAT_002074b0 == iVar2) {
    FUN_00115300(0);
    iVar2 = 0;
    if (DAT_002074c8 < 0) {
      while( true ) {
        while (lVar4 = FUN_00115a98(0x25bc50,0xffffffff8000059c,0), lVar4 < 0) {
          if (0 < ram0x00207490) {
            FUN_00114ac8(0x24ea80);
          }
          iVar5 = 0x100000;
          do {
            iVar5 = iVar5 + -1;
          } while (iVar5 != -1);
        }
        bVar1 = 0x10 < iVar2;
        if (iRam0025bc74 != 0) break;
        iVar2 = iVar2 + 1;
        if (bVar1) {
          SignalSema(DAT_002074b0);
          uVar3 = FUN_00101388(param_1);
          return uVar3;
        }
        iVar5 = 0x100000;
        do {
          iVar5 = iVar5 + -1;
        } while (iVar5 != -1);
      }
      DAT_002074c8 = 0;
    }
    uRam0025bc90 = (undefined4)param_1;
    FUN_00115250(0x25bc90,4);
    lVar4 = FUN_00115c68(0x25bc50,0,0,0x25bc90,4,0x208f00,4,0);
    if (-1 < lVar4) {
      if (0 < ram0x00207490) {
        FUN_00114ac8(0x24eaa0);
      }
      uVar3 = DAT_20208f00;
      SignalSema(DAT_002074b0);
      return uVar3;
    }
    SignalSema(DAT_002074b0);
  }
  uVar3 = 6;
  if (param_1 == 8) {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}
