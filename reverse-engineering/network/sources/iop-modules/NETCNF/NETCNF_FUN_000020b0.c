FUNCTION FUN_000020b0 @ 0x000020b0 size=68
CALLERS (8): FUN_00003f98@0x00003f98, FUN_00002280@0x00002280, FUN_00003988@0x00003988, FUN_00003060@0x00003060, FUN_000023e0@0x000023e0, FUN_000032bc@0x000032bc, FUN_000036ac@0x000036ac, FUN_000027e4@0x000027e4
CALLEES (1): FUN_00001198@0x00001198

int FUN_000020b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = -9;
  }
  else {
    iVar1 = FUN_00001198();
    iVar2 = iVar1;
    if ((iVar1 < 0) && (iVar2 = 0, iVar1 != -3)) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}


================================================================