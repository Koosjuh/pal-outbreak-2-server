FUNCTION FUN_005ff760 @ 0x005ff760  size=204
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (4): FUN_005b6900@0x005b6900, FUN_005c0750@0x005c0750, FUN_005b68e0@0x005b68e0, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005ff760(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\x03') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x02') {
    *(undefined1 *)(param_1 + 0x10) = 3;
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x19;
    FUN_005c0750(0x601420);
  }
  else if (cVar1 == '\x01') {
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    if (*(short *)(param_1 + 0x16) < 0) {
      *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x10) = 1;
    *(undefined2 *)(param_1 + 0x16) = 0x4c;
    FUN_005b9060(0x14,param_1 + 0x5ec);
  }
  return;
}



================================================================