FUNCTION FUN_005f6aa0 @ 0x005f6aa0  size=84
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (2): FUN_005f6d20@0x005f6d20, FUN_005f6b00@0x005f6b00
----------------------------------------------------------------

void FUN_005f6aa0(int param_1)

{
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
  case 1:
  case 2:
    FUN_005f6b00();
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    FUN_005f6d20();
  }
  return;
}



================================================================