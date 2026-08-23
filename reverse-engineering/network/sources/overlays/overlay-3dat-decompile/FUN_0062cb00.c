FUNCTION FUN_0062cb00 @ 0x0062cb00  size=152
CALLERS (1): FUN_0062c750@0x0062c750
CALLEES (3): FUN_005c0e30@0x005c0e30, FUN_005b68e0@0x005b68e0, FUN_00617a00@0x00617a00
----------------------------------------------------------------

void FUN_0062cb00(int param_1)

{
  *(undefined1 *)(param_1 + 0x10b4) = 0;
  *(undefined1 *)(param_1 + 0x9a9) = 0xff;
  if (*(short *)(param_1 + 0x10b8) == 0) {
    FUN_00617a00();
  }
  else {
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x1f;
    if (*(ushort *)(param_1 + 0x10ba) < 2) {
      FUN_005c0e30(*(undefined2 *)(param_1 + 0x10b8),*(ushort *)(param_1 + 0x10ba),0,0x62cba0);
    }
    else {
      FUN_005c0e30(*(undefined2 *)(param_1 + 0x10b8),0,0,0x62cba0);
    }
  }
  return;
}



================================================================