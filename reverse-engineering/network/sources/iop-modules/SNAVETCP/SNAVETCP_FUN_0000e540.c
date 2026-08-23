FUNCTION FUN_0000e540 @ 0x0000e540 size=68
CALLERS (2): FUN_0000223c@0x0000223c, FUN_00000874@0x00000874
CALLEES (0): 

undefined4 FUN_0000e540(short param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if ((-1 < iVar1) && (iVar1 <= DAT_000168e0)) {
    return (&DAT_00016190)[iVar1];
  }
  return 0;
}


================================================================