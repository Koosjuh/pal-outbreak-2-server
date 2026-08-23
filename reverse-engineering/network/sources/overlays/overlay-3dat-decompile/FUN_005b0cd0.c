FUNCTION FUN_005b0cd0 @ 0x005b0cd0  size=560
CALLERS (3): FUN_006293f0@0x006293f0, FUN_006296a0@0x006296a0, FUN_00628210@0x00628210
CALLEES (2): FUN_005b16c0@0x005b16c0, FUN_005b14b0@0x005b14b0
----------------------------------------------------------------

undefined4 FUN_005b0cd0(byte *param_1,byte param_2,byte param_3)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  short *psVar5;
  char cVar6;
  
  if (param_3 == 0 || param_3 == 2) {
    uVar4 = 0x10001;
    uVar3 = 0x20002;
    cVar2 = 'R';
    cVar6 = 'Q';
    psVar5 = (short *)0x6ca070;
  }
  else {
    uVar4 = 0x40004;
    uVar3 = 0x80008;
    cVar2 = 'P';
    cVar6 = 'O';
    psVar5 = (short *)0x6ca072;
  }
  lVar1 = FUN_005b14b0(uVar4);
  if ((lVar1 == 0) && (cRam006c462a != cVar2)) {
    lVar1 = FUN_005b14b0(uVar3);
    if ((lVar1 == 0) && (cRam006c462a != cVar6)) {
      if (*psVar5 != 0) {
        *psVar5 = *psVar5 + -1;
        return 0;
      }
      lVar1 = FUN_005b16c0(uVar4);
      if ((lVar1 != 0) || (cRam006c4628 == cVar2)) {
        *psVar5 = 10;
        goto LAB_005b0e80;
      }
      lVar1 = FUN_005b16c0(uVar3);
      if ((lVar1 == 0) && (cRam006c4628 != cVar6)) {
        return 0;
      }
      *psVar5 = 10;
    }
    else {
      *psVar5 = 0x14;
    }
    if (param_3 < 2) {
      if ((long)(char)*param_1 == (ulong)param_2) {
        *param_1 = 0;
      }
      else {
        *param_1 = *param_1 + 1;
      }
    }
    else {
      if ((long)(char)*param_1 == (ulong)param_2) {
        return 0;
      }
      *param_1 = *param_1 + 1;
    }
    func_0x001b0140(0);
  }
  else {
    *psVar5 = 0x14;
LAB_005b0e80:
    if (param_3 < 2) {
      if (*param_1 == 0) {
        *param_1 = param_2;
      }
      else {
        *param_1 = *param_1 - 1;
      }
    }
    else {
      if (*param_1 == 0) {
        return 0;
      }
      *param_1 = *param_1 - 1;
    }
    func_0x001b0140(0);
  }
  return 1;
}



================================================================