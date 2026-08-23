FUNCTION FUN_00012e34 @ 0x00012e34 size=460
CALLERS (1): FUN_0000e1a8@0x0000e1a8
CALLEES (3): FUN_00014dd4@0x00014dd4, FUN_00014e24@0x00014e24, FUN_00014ddc@0x00014ddc

void FUN_00012e34(undefined4 param_1,undefined *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_18 [2];
  
  if ((DAT_00016178 & 0x80) != 0) {
    FUN_00014e24("ave-tcp: AT_InetFreePkt called. flg %d\n",param_3);
  }
  FUN_00014dd4(local_18);
  iVar5 = 0;
  if (param_3 == 1) {
    iVar4 = 0;
    iVar2 = 0;
    do {
      sVar1 = (short)iVar4;
      iVar4 = iVar4 + 1;
      if (param_2 == &DAT_00028d70 + (iVar2 >> 0x10) * 0x634) {
        (&DAT_00028cf0)[iVar2 >> 0x10] = 0;
        iVar5 = 1;
        break;
      }
      iVar2 = iVar4 * 0x10000;
      sVar1 = (short)iVar4;
    } while (iVar4 * 0x10000 >> 0x10 < 0x20);
    if ((iVar5 == 0) && ((DAT_00016178 & 0x80) != 0)) {
      FUN_00014e24("ave-tcp: AT_InetFreePkt miss match\n");
    }
  }
  else {
    iVar4 = 0;
    iVar2 = 0;
    do {
      sVar1 = (short)iVar4;
      iVar3 = (iVar2 >> 0x10) * 0x634;
      if ((&DAT_00028d88 + iVar3 <= param_2) && (param_2 <= &DAT_000293a4 + iVar3)) {
        (&DAT_00028cf0)[iVar2 >> 0x10] = 0;
        iVar5 = 1;
        break;
      }
      iVar4 = iVar4 + 1;
      sVar1 = (short)iVar4;
      iVar2 = iVar4 * 0x10000;
    } while (iVar4 * 0x10000 >> 0x10 < 0x20);
  }
  FUN_00014ddc(local_18[0]);
  if ((DAT_00016178 & 0x80) != 0) {
    FUN_00014e24("ave-tcp: AT_InetFreePkt chkflg %d index %d\n",iVar5,(int)sVar1);
  }
  return;
}


================================================================