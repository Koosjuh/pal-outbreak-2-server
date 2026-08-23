FUNCTION FUN_006178a0 @ 0x006178a0  size=112
CALLERS (1): FUN_006177d0@0x006177d0
CALLEES (5): FUN_005ba7b0@0x005ba7b0, FUN_005af2f0@0x005af2f0, FUN_00618b60@0x00618b60, FUN_005b9060@0x005b9060, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_006178a0(int param_1)

{
  *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
  *(undefined2 *)(param_1 + 0x16) = 0;
  FUN_00618b60();
  FUN_005ba7b0();
  if (*(char *)(param_1 + 0x11) == '\0') {
    FUN_005b8cf0(0x4a);
  }
  else {
    FUN_005b9060(0x14,param_1 + 0x5ec);
  }
  *(undefined2 *)(param_1 + 0x16) = 10;
  FUN_005af2f0(0);
  return;
}



================================================================