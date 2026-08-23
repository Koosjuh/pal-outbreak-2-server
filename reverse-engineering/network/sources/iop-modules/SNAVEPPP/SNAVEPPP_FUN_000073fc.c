FUNCTION FUN_000073fc @ 0x000073fc size=432
CALLERS (1): FUN_00001e44@0x00001e44
CALLEES (7): FUN_0001073c@0x0001073c, FUN_000053b4@0x000053b4, FUN_00010c38@0x00010c38, FUN_000107dc@0x000107dc, FUN_00010764@0x00010764, FUN_0000548c@0x0000548c, FUN_00010108@0x00010108

undefined4 FUN_000073fc(char *param_1,undefined2 param_2)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  char *pcVar5;
  
  cVar2 = *param_1;
  pcVar5 = *(char **)(param_1 + 0xc);
  param_1[8] = '\0';
  param_1[9] = '\0';
  while( true ) {
    if (cVar2 == '\x05') {
      param_1[8] = '\0';
      param_1[9] = '\0';
      return 0;
    }
    iVar4 = FUN_000053b4();
    if (((iVar4 != 0) || (*(short *)(param_1 + 8) != 0)) || (*pcVar5 == '\x04')) break;
    sVar3 = FUN_0000548c(param_2);
    if (sVar3 != 0) {
      if (DAT_00012efc != 0) {
        FUN_00010c38("ave-ppp %s:","PP_chap_monitor");
        FUN_00010c38("PPP-CHAP auth was changed.\n",0);
        return 0xffffffee;
      }
      return 0xffffffee;
    }
    FUN_00010764();
    FUN_000107dc();
    FUN_00010108();
    FUN_0001073c();
    cVar2 = *param_1;
  }
  bVar1 = DAT_00012ec8 == 0;
  param_1[8] = '\0';
  param_1[9] = '\0';
  if (bVar1) {
    DAT_00012edc = 5;
    if (DAT_00012efc == 0) {
      DAT_00012ecc = 8;
      DAT_00012edc = 5;
      return 0xffffffff;
    }
    FUN_00010c38("ave-ppp %s:","PP_chap_monitor");
    pcVar5 = "ERROR: PPP-CHAP negotiation failure.\n";
  }
  else {
    DAT_00012edc = 6;
    if (DAT_00012efc == 0) {
      DAT_00012ecc = 8;
      DAT_00012edc = 6;
      return 0xffffffff;
    }
    FUN_00010c38("ave-ppp %s:","PP_chap_monitor");
    pcVar5 = "ERROR: PPP-CHAP authentication failure.\n";
  }
  FUN_00010c38(pcVar5,0);
  DAT_00012ecc = 8;
  return 0xffffffff;
}


================================================================