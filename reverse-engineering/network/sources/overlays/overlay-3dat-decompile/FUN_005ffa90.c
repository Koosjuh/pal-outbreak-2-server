FUNCTION FUN_005ffa90 @ 0x005ffa90  size=144
CALLERS (1): FUN_005ff9f0@0x005ff9f0
CALLEES (3): FUN_005c2120@0x005c2120, FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0
----------------------------------------------------------------

void FUN_005ffa90(int param_1)

{
  if (*(char *)(param_1 + 0xf) == '\x01') {
    FUN_005b6900();
  }
  else if (*(char *)(param_1 + 0xf) == '\0') {
    *(undefined1 *)(param_1 + 0xf) = 1;
    func_0x00106b60(iRam003435d4 + 0xc942c,0,0x20c0);
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x21;
    FUN_005c2120(0x6014c0);
  }
  return;
}



================================================================