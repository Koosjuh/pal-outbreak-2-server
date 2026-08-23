FUNCTION FUN_0062c970 @ 0x0062c970  size=124
CALLERS (1): FUN_0062c350@0x0062c350
CALLEES (3): FUN_005f8b50@0x005f8b50, FUN_005f7570@0x005f7570, FUN_005f4b70@0x005f4b70
----------------------------------------------------------------

void FUN_0062c970(int param_1,int param_2)

{
  *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
  if (*(short *)(param_2 + 4) < 1) {
    FUN_005f4b70();
    if (*(ushort *)(param_1 + 0x10ba) < 2) {
      if (*(ushort *)(param_1 + 0x10ba) == 0) {
        FUN_005f7570();
      }
      else {
        FUN_005f8b50(*(undefined2 *)(param_1 + 0x10bc));
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x10ba) = 0;
      FUN_005f7570();
    }
  }
  return;
}



================================================================