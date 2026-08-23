FUNCTION FUN_0062ba00 @ 0x0062ba00  size=112
CALLERS (3): FUN_005ff950@0x005ff950, FUN_005f76f0@0x005f76f0, FUN_005f8d40@0x005f8d40
CALLEES (0): 
----------------------------------------------------------------

void FUN_0062ba00(int param_1,int param_2)

{
  *(undefined1 *)(param_1 + 1) = 0;
  if (param_2 == 2) {
    *(undefined1 *)(param_1 + 0xe) = 3;
    *(undefined1 *)(param_1 + 0xf) = 0;
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x11) = 0;
    *(undefined1 *)(param_1 + 0x907) = 0;
    *(undefined1 *)(param_1 + 0x908) = *(undefined1 *)(param_1 + 0x44c);
    *(undefined1 *)(param_1 + 0x909) = 0;
  }
  else if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0xe) = 0;
    *(undefined1 *)(param_1 + 0xf) = 6;
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x11) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0xe) = 0;
    *(undefined1 *)(param_1 + 0xf) = 0;
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x11) = 0;
  }
  return;
}



================================================================