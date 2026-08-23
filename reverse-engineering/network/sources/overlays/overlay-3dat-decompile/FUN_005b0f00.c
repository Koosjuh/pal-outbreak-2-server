FUNCTION FUN_005b0f00 @ 0x005b0f00  size=648
CALLERS (1): FUN_00629200@0x00629200
CALLEES (2): FUN_005b16c0@0x005b16c0, FUN_005b14b0@0x005b14b0
----------------------------------------------------------------

undefined4 FUN_005b0f00(byte *param_1,byte param_2,byte param_3)

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
    psVar5 = (short *)0x6ca078;
  }
  else {
    uVar4 = 0x40004;
    uVar3 = 0x80008;
    cVar2 = 'P';
    cVar6 = 'O';
    psVar5 = (short *)0x6ca07a;
  }
  lVar1 = FUN_005b14b0(uVar4);
  if (((lVar1 == 0) && (cRam006c462a != cVar2)) &&
     ((cRam006c462a != '+' || ((bRam006c462b & 0x22) == 0)))) {
    lVar1 = FUN_005b14b0(uVar3);
    if (((lVar1 == 0) && (cRam006c462a != cVar6)) && (cRam006c462a != '+')) {
      if (*psVar5 != 0) {
        *psVar5 = *psVar5 + -1;
        return 0;
      }
      lVar1 = FUN_005b16c0(uVar4);
      if (((lVar1 != 0) || (cRam006c4628 == cVar2)) ||
         ((cRam006c4628 == '+' && ((bRam006c462b & 0x22) != 0)))) {
        *psVar5 = 10;
        goto LAB_005b1108;
      }
      lVar1 = FUN_005b16c0(uVar3);
      if (((lVar1 == 0) && (cRam006c4628 != cVar6)) && (cRam006c4628 != '+')) {
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
LAB_005b1108:
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