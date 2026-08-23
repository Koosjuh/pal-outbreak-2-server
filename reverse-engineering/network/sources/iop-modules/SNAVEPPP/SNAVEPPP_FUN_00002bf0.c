FUNCTION FUN_00002bf0 @ 0x00002bf0 size=352
CALLERS (1): FUN_00010898@0x00010898
CALLEES (4): FUN_00010b64@0x00010b64, FUN_00010c38@0x00010c38, FUN_0000fde0@0x0000fde0, FUN_00002d98@0x00002d98

undefined4 FUN_00002bf0(short *param_1)

{
  short sVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  undefined1 auStack_40 [8];
  short local_38;
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","PP_finish");
    FUN_00010c38("called (arg=0x%x).\n",param_1);
  }
  if ((DAT_00012efc & 1) != 0) {
    FUN_00010c38("PP_finish: ppDriverContextP->pp_handle %d\n",*(undefined4 *)(DAT_000132d4 + 0x58))
    ;
  }
  if ((-1 < *(int *)(DAT_000132d4 + 0x58)) &&
     (sVar1 = FUN_0000fde0((int)*(short *)(DAT_000132d4 + 0x58)), sVar1 != 0)) {
    return 0xffffffff;
  }
  if ((param_1 == (short *)0x0) || (iVar4 = 0, *param_1 == 0)) {
    uVar2 = 0;
    if ((DAT_00012efc & 1) != 0) {
      pcVar3 = "PP_finish: non blocking  return 0\n";
LAB_00002d20:
      FUN_00010c38(pcVar3);
      uVar2 = 0;
    }
  }
  else {
    do {
      FUN_00010b64(200);
      FUN_00002d98(auStack_40);
      iVar4 = iVar4 + 200;
      if (local_38 == 0) {
        if ((DAT_00012efc & 1) == 0) {
          return 0;
        }
        pcVar3 = "PP_finish: phase == AvepppConnectUnused return 0\n";
        goto LAB_00002d20;
      }
      uVar2 = 0xffffffff;
    } while (iVar4 < 300000);
  }
  return uVar2;
}


================================================================