FUNCTION FUN_005b24e0 @ 0x005b24e0  size=212
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (10): FUN_005b25c0@0x005b25c0, FUN_005b33f0@0x005b33f0, FUN_005b4a50@0x005b4a50, FUN_005b29b0@0x005b29b0, FUN_005b2bc0@0x005b2bc0, FUN_005b3510@0x005b3510, FUN_005b3070@0x005b3070, FUN_005b3790@0x005b3790, FUN_005b3590@0x005b3590, FUN_005b2e40@0x005b2e40
----------------------------------------------------------------

void FUN_005b24e0(int param_1)

{
  switch(*(undefined1 *)(param_1 + 0xe)) {
  case 0:
    FUN_005b25c0();
    break;
  case 1:
    FUN_005b29b0();
    break;
  case 2:
    FUN_005b2bc0();
    break;
  case 3:
    FUN_005b3070();
    break;
  case 4:
    FUN_005b33f0();
    break;
  case 5:
    FUN_005b3510();
    break;
  case 6:
    FUN_005b3590();
    break;
  case 7:
    FUN_005b3790();
    break;
  case 8:
    FUN_005b2e40();
    break;
  case 9:
    FUN_005b4a50();
  }
  return;
}



================================================================