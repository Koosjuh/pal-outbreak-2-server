
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00100838(undefined8 *param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  
  FUN_00100590();
  iVar6 = PollSema(DAT_002074a8);
  if (DAT_002074a8 == iVar6) {
    DAT_0020749c = 1;
    ReferThreadStatus(uRam0025ba18,0x25ba20);
    lVar7 = FUN_00100d78(1);
    if (lVar7 == 0) {
      FUN_00115300(0);
      if (DAT_002074c4 < 0) {
        while( true ) {
          while (lVar7 = FUN_00115a98(0x25bc00,0xffffffff80000597,0), lVar7 < 0) {
            if (0 < ram0x00207490) {
              FUN_00114ac8(0x24e928);
            }
            iVar6 = 0x100000;
            do {
              iVar6 = iVar6 + -1;
            } while (iVar6 != -1);
          }
          iVar6 = 0x100000;
          if (iRam0025bc24 != 0) break;
          do {
            iVar6 = iVar6 + -1;
          } while (iVar6 != -1);
        }
        DAT_002074c4 = 0;
      }
      cRam0025baa4 = *param_2;
      iVar6 = 0;
      if (cRam0025baa4 != '\0') {
        for (iVar6 = 1;
            (iVar6 < 0x100 &&
            (cVar1 = param_2[iVar6], *(char *)(iVar6 + 0x25baa4) = cVar1, cVar1 != '\0'));
            iVar6 = iVar6 + 1) {
        }
      }
      if (iVar6 == 0x100) {
        uRam0025bba3 = 0;
      }
      if (0 < ram0x00207490) {
        FUN_00114ac8(0x24e948,0x25baa4);
      }
      uRam0025bba4 = 0x25ba80;
      uRam0025bba8 = param_3;
      FUN_00115250(0x25ba80,300);
      lVar7 = FUN_00115c68(0x25bc00,0,0,0x25ba80,300,0x25bbc0,4,0);
      uVar4 = DAT_2025ba98;
      uVar3 = DAT_2025ba90;
      uVar2 = DAT_2025ba88;
      if (-1 < lVar7) {
        *param_1 = DAT_2025ba80;
        param_1[1] = uVar2;
        param_1[2] = uVar3;
        param_1[3] = uVar4;
        *(undefined4 *)(param_1 + 4) = DAT_2025baa0;
        if (((0 < ram0x00207490) && (FUN_00114ac8(0x24e960,param_1 + 1), 0 < ram0x00207490)) &&
           (FUN_00114ac8(0x24e970,*(undefined4 *)((int)param_1 + 4)), 0 < ram0x00207490)) {
          FUN_00114ac8(0x24e980,*(undefined4 *)param_1);
        }
        uVar5 = DAT_2025bbc0;
        SignalSema(DAT_002074a8);
        return uVar5;
      }
    }
    SignalSema(DAT_002074a8);
  }
  return 0;
}
