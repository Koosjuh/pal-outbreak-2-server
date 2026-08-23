FUNCTION FUN_00009388 @ 0x00009388 size=328
CALLERS (1): FUN_00009768@0x00009768
CALLEES (1): FUN_00009e28@0x00009e28

void FUN_00009388(uint param_1)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  
  if (param_1 == 10) {
    FUN_00009e28(&DAT_0001b7dc);
    return;
  }
  if ((int)param_1 < 0xb) {
    if (param_1 == 8) {
      FUN_00009e28(&DAT_0001b7d4);
      return;
    }
    if (8 < (int)param_1) {
      FUN_00009e28(&DAT_0001b7d8);
      return;
    }
    if (param_1 == 0) {
      FUN_00009e28(&DAT_0001b7d0);
      return;
    }
    bVar1 = (param_1 & 0xff) < 0x20;
  }
  else {
    if (param_1 == 0x1b) {
      FUN_00009e28(&DAT_0001b7e4);
      return;
    }
    if ((int)param_1 < 0x1c) {
      if (param_1 == 0xd) {
        FUN_00009e28(&DAT_0001b7e0);
        return;
      }
      bVar1 = (param_1 & 0xff) < 0x20;
    }
    else {
      if (param_1 == 0x7f) {
        FUN_00009e28(&DAT_0001b7e8);
        return;
      }
      bVar1 = (param_1 & 0xff) < 0x20;
    }
  }
  uVar3 = param_1 & 0xff;
  if (bVar1) {
    pcVar2 = &DAT_0001b7ec;
    uVar3 = param_1 + 0x40;
  }
  else if (uVar3 < 0x7f) {
    pcVar2 = &DAT_0001b7f8;
    uVar3 = param_1;
  }
  else {
    pcVar2 = s__x_02x_0001b7f0;
  }
  FUN_00009e28(pcVar2,uVar3);
  return;
}


================================================================