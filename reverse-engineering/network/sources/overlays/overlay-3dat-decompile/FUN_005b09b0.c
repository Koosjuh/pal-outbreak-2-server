FUNCTION FUN_005b09b0 @ 0x005b09b0  size=392
CALLERS (22): FUN_0062d730@0x0062d730, FUN_005fec30@0x005fec30, FUN_0062e5b0@0x0062e5b0, FUN_0062a6d0@0x0062a6d0, FUN_005b4860@0x005b4860, FUN_0062cfd0@0x0062cfd0, FUN_00628f70@0x00628f70, FUN_005fede0@0x005fede0, FUN_005b3ed0@0x005b3ed0, FUN_005fa490@0x005fa490, FUN_00604180@0x00604180, FUN_005faa60@0x005faa60, ...
CALLEES (1): FUN_005b14b0@0x005b14b0
----------------------------------------------------------------

undefined4 FUN_005b09b0(byte *param_1,byte param_2,byte param_3)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  char cVar5;
  undefined8 uVar6;
  
  if (param_3 == 0 || param_3 == 2) {
    uVar3 = 0x10001;
    uVar6 = 0x20002;
    cVar5 = 'R';
    cVar4 = 'Q';
  }
  else {
    uVar3 = 0x40004;
    uVar6 = 0x80008;
    cVar5 = 'P';
    cVar4 = 'O';
  }
  lVar2 = FUN_005b14b0(uVar3);
  if ((lVar2 == 0) && (cRam006c462a != cVar5)) {
    lVar2 = FUN_005b14b0(uVar6);
    if ((lVar2 != 0) || (uVar1 = 0, cRam006c462a == cVar4)) {
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
      uVar1 = 1;
    }
  }
  else {
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
    uVar1 = 1;
  }
  return uVar1;
}



================================================================