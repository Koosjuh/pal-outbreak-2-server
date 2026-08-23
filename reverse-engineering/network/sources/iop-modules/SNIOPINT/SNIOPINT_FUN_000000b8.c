FUNCTION FUN_000000b8 @ 0x000000b8 size=136
CALLERS (0): 
CALLEES (2): FUN_00003818@0x00003818, FUN_00003810@0x00003810

void FUN_000000b8(undefined2 param_1,ushort param_2)

{
  FUN_00003818(DAT_00009464);
  if (param_2 < 3) {
    *(undefined2 *)(&DAT_00009434 + (short)param_2 * 0x14) = param_1;
    (&DAT_00009432)[(short)param_2 * 10] = 1;
  }
  FUN_00003810(DAT_00009464);
  return;
}


================================================================