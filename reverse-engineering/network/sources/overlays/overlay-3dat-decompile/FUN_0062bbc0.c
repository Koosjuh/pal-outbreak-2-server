FUNCTION FUN_0062bbc0 @ 0x0062bbc0  size=392
CALLERS (1): FUN_0062ba70@0x0062ba70
CALLEES (4): FUN_0062cf10@0x0062cf10, FUN_005b14b0@0x005b14b0, FUN_005b09b0@0x005b09b0, FUN_0062bd50@0x0062bd50
----------------------------------------------------------------

undefined4 FUN_0062bbc0(undefined8 param_1,char *param_2)

{
  short sVar1;
  long lVar2;
  
  if (param_2[1] == '\x01') {
    sVar1 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar1 + -1;
    if ((short)(sVar1 + -1) < 1) {
      if (*(short *)(param_2 + 10) == 3) {
        *param_2 = *param_2 + '\x01';
        param_2[1] = '\0';
        param_2[2] = '\0';
      }
      else {
        *param_2 = '\x03';
        param_2[1] = '\0';
        param_2[2] = '\0';
        FUN_0062cf10();
        func_0x00109eb8(0x7154a1,(int)param_1 +
                                 *(short *)(param_2 + 10) * 0x24 + (int)*(short *)(param_2 + 10) +
                                 0x1045);
        func_0x00109eb8(0x7154b1,(int)param_1 +
                                 *(short *)(param_2 + 10) * 0x24 + (int)*(short *)(param_2 + 10) +
                                 0x1055);
      }
    }
  }
  else {
    if (param_2[1] != '\0') {
      return 0;
    }
    FUN_005b09b0(param_2 + 10,3,2);
    lVar2 = FUN_005b14b0(0x10);
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x200);
      if (lVar2 != 0) {
        func_0x001b0140(2);
        return 1;
      }
    }
    else if ((*(short *)(param_2 + 10) == 3) && (lVar2 = FUN_0062bd50(param_1), lVar2 == 0)) {
      func_0x001b0140(5);
    }
    else {
      param_2[1] = param_2[1] + '\x01';
      param_2[2] = '\0';
      param_2[0x14] = '\x01';
      param_2[4] = '\b';
      param_2[5] = '\0';
      func_0x001b0140();
    }
  }
  return 0;
}



================================================================