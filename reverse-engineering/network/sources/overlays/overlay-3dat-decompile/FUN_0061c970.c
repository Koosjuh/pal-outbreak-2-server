FUNCTION FUN_0061c970 @ 0x0061c970  size=120
CALLERS (1): FUN_00619e00@0x00619e00
CALLEES (0): 
----------------------------------------------------------------

undefined1 FUN_0061c970(int param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  for (psVar2 = &DAT_00669b30; (*psVar2 < 0 && (*psVar2 != (short)param_1)); psVar2 = psVar2 + 1) {
    iVar1 = iVar1 + 1;
  }
  if ((&DAT_00669b90)[iVar1] == -1) {
    iVar1 = iVar1 + 1;
  }
  if (param_1 == 0x7f) {
    iVar1 = iVar1 + 1;
  }
  return (&DAT_00669b90)[iVar1];
}



================================================================