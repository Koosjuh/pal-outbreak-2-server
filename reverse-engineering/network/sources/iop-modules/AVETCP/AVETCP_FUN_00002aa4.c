FUNCTION FUN_00002aa4 @ 0x00002aa4 size=68
CALLERS (4): FUN_000025a4@0x000025a4, FUN_00002a0c@0x00002a0c, FUN_00002728@0x00002728, FUN_00002914@0x00002914
CALLEES (1): FUN_00003220@0x00003220

undefined4 FUN_00002aa4(int param_1)

{
  int iVar1;
  
  iVar1 = (param_1 << 0x10) >> 0xb;
  FUN_00003220(&DAT_000187b0 + iVar1);
  (&DAT_000187b0)[iVar1] = 0;
  return 0;
}


================================================================