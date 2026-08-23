FUNCTION FUN_00002dbc @ 0x00002dbc size=212
CALLERS (2): FUN_000032fc@0x000032fc, FUN_00002dbc@0x00002dbc
CALLEES (2): FUN_00002dbc@0x00002dbc, FUN_00001850@0x00001850

byte * FUN_00002dbc(int param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = *param_2;
  while( true ) {
    uVar3 = (uint)bVar2;
    param_2 = param_2 + 1;
    if (uVar3 == 0) {
      return param_2;
    }
    if ((uVar3 & 0xc0) == 0xc0) break;
    while (bVar1 = 0 < (int)uVar3, uVar3 = uVar3 - 1, bVar1) {
      bVar2 = *param_2;
      param_2 = param_2 + 1;
      FUN_00001850((int)(char)bVar2);
    }
    if (*param_2 != 0) {
      FUN_00001850(0x2e);
    }
    bVar2 = *param_2;
  }
  FUN_00002dbc(param_1,param_1 + ((uVar3 & 0xffffff3f) << 8 | (uint)*param_2));
  return param_2 + 1;
}


================================================================