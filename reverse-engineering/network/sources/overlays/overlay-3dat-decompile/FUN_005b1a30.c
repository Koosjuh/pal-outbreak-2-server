FUNCTION FUN_005b1a30 @ 0x005b1a30  size=220
CALLERS (1): FUN_005b1a00@0x005b1a00
CALLEES (10): FUN_005b20c0@0x005b20c0, FUN_00603d30@0x00603d30, FUN_00603d50@0x00603d50, FUN_00618b60@0x00618b60, FUN_00627760@0x00627760, FUN_005b2260@0x005b2260, FUN_005f6970@0x005f6970, FUN_00603d70@0x00603d70, FUN_005b1fa0@0x005b1fa0, FUN_00617a00@0x00617a00
----------------------------------------------------------------

void FUN_005b1a30(int param_1)

{
  *(undefined1 *)(param_1 + 0x42c) = 0;
  switch(*(undefined1 *)(param_1 + 0x42d)) {
  case 1:
    FUN_00617a00();
    break;
  case 2:
    FUN_00603d30();
    FUN_00618b60();
    return;
  case 3:
    FUN_00627760();
    break;
  case 5:
  case 10:
    *(undefined1 *)(param_1 + 0x42c) = 1;
    FUN_005b1fa0();
    break;
  case 6:
    *(undefined1 *)(param_1 + 0x42c) = 1;
    FUN_005b2260();
    break;
  case 8:
    FUN_00603d70();
    break;
  case 9:
    FUN_00603d50();
    break;
  case 0xb:
    FUN_005f6970(2);
    break;
  case 0xc:
    *(undefined1 *)(param_1 + 0x42c) = 1;
    FUN_005b20c0();
  }
  return;
}



================================================================