FUNCTION FUN_00617910 @ 0x00617910  size=112
CALLERS (1): FUN_006177d0@0x006177d0
CALLEES (2): FUN_005af300@0x005af300, FUN_005b14b0@0x005b14b0
----------------------------------------------------------------

void FUN_00617910(int param_1)

{
  short sVar1;
  long lVar2;
  
  sVar1 = *(short *)(param_1 + 0x16);
  *(short *)(param_1 + 0x16) = sVar1 + 1;
  if ((299 < sVar1) ||
     ((0x4b < *(short *)(param_1 + 0x16) && (lVar2 = FUN_005b14b0(0x210), lVar2 != 0)))) {
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
    *(undefined2 *)(param_1 + 0x16) = 10;
    FUN_005af300(0);
  }
  return;
}



================================================================