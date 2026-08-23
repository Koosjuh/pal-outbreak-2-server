FUNCTION FUN_005fe730 @ 0x005fe730  size=196
CALLERS (1): FUN_005fe620@0x005fe620
CALLEES (9): FUN_005fed70@0x005fed70, FUN_005fec10@0x005fec10, FUN_005fec30@0x005fec30, FUN_005fe8d0@0x005fe8d0, FUN_005ff760@0x005ff760, FUN_005ff690@0x005ff690, FUN_005fe800@0x005fe800, FUN_005fede0@0x005fede0, FUN_005fed10@0x005fed10
----------------------------------------------------------------

void FUN_005fe730(int param_1)

{
  switch(*(undefined1 *)(param_1 + 0xf)) {
  case 0:
    FUN_005fe800();
    break;
  case 1:
    FUN_005fe8d0();
    break;
  case 2:
    FUN_005fec10();
    break;
  case 3:
    FUN_005fec30();
    break;
  case 4:
    FUN_005fed10();
    break;
  case 5:
    FUN_005fed70();
    break;
  case 6:
    FUN_005fede0();
    break;
  case 7:
    FUN_005ff690();
    break;
  case 8:
    FUN_005ff760();
  }
  return;
}



================================================================