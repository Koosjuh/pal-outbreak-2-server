FUNCTION FUN_00600d10 @ 0x00600d10  size=204
CALLERS (1): FUN_005ff9f0@0x005ff9f0
CALLEES (5): FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0, FUN_005c22a0@0x005c22a0, FUN_005acd60@0x005acd60, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_00600d10(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x03') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x02') {
    *(undefined1 *)(param_1 + 0xf) = 3;
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x22;
    FUN_005c22a0(0x601700);
  }
  else if (cVar1 == '\x01') {
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    if (*(short *)(param_1 + 0x16) < 0) {
      FUN_005acd60(0x6c4b90);
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xf) = 1;
    *(undefined2 *)(param_1 + 0x16) = 0x4c;
    FUN_005b9060(0x14,param_1 + 0x5ec);
  }
  return;
}



================================================================