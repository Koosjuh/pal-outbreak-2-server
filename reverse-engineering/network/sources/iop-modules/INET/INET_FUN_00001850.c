FUNCTION FUN_00001850 @ 0x00001850 size=356
CALLERS (2): FUN_00002dbc@0x00002dbc, FUN_000019b4@0x000019b4
CALLEES (1): FUN_00011d90@0x00011d90

void FUN_00001850(byte param_1)

{
  char *pcVar1;
  uint uVar2;
  
  if (param_1 == 0xc) {
    FUN_00011d90(&DAT_0001b490);
  }
  else {
    if ((char)param_1 < '\r') {
      if (param_1 == 9) {
        FUN_00011d90(&DAT_0001b484);
        return;
      }
      if ((char)param_1 < '\n') {
        if (param_1 == 8) {
          FUN_00011d90(&DAT_0001b48c);
          return;
        }
      }
      else if (param_1 == 10) {
        FUN_00011d90(&DAT_0001b480);
        return;
      }
    }
    else {
      if (param_1 == 0x22) {
        FUN_00011d90(&DAT_0001b478);
        return;
      }
      if ((char)param_1 < '#') {
        if (param_1 == 0xd) {
          FUN_00011d90(&DAT_0001b488);
          return;
        }
      }
      else if (param_1 == 0x5c) {
        FUN_00011d90(&DAT_0001b47c);
        return;
      }
    }
    uVar2 = (uint)(char)param_1;
    if ((((uVar2 & 0xe0) == 0) || (uVar2 == 0x7f)) || ((uVar2 & 0x80) != 0)) {
      pcVar1 = s__x_02x_0001b494;
      uVar2 = (uint)param_1;
    }
    else {
      pcVar1 = &DAT_0001b474;
    }
    FUN_00011d90(pcVar1,uVar2);
  }
  return;
}


================================================================