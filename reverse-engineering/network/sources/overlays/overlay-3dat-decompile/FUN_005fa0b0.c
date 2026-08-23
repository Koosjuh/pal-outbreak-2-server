FUNCTION FUN_005fa0b0 @ 0x005fa0b0  size=220
CALLERS (1): FUN_005f8e20@0x005f8e20
CALLEES (7): FUN_005faa60@0x005faa60, FUN_005fa190@0x005fa190, FUN_005fb010@0x005fb010, FUN_005fa490@0x005fa490, FUN_005fada0@0x005fada0, FUN_005fb060@0x005fb060, FUN_005f8d00@0x005f8d00
----------------------------------------------------------------

void FUN_005fa0b0(int param_1)

{
  switch(*(undefined1 *)(param_1 + 0xf)) {
  case 0:
    FUN_005fa190();
    break;
  case 1:
    FUN_005fa490();
    break;
  case 2:
    FUN_005faa60();
    break;
  case 3:
    FUN_005fada0();
    break;
  case 4:
    *(undefined1 *)(param_1 + 0x97c) = 4;
    FUN_005f8d00(0x89);
    break;
  case 5:
    FUN_005fb010();
    break;
  case 6:
    FUN_005fb060();
    break;
  case 7:
    *(undefined1 *)(param_1 + 0x97c) = 4;
    FUN_005f8d00(0xb8);
    break;
  case 8:
    *(undefined1 *)(param_1 + 0x97c) = 4;
    FUN_005f8d00(0xb9);
  }
  return;
}



================================================================