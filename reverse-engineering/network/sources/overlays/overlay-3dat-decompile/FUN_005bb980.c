FUNCTION FUN_005bb980 @ 0x005bb980  size=156
CALLERS (0): 
CALLEES (3): FUN_005c7d00@0x005c7d00, FUN_005bf1e0@0x005bf1e0, FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005bb980(void)

{
  uint uVar1;
  short *psVar2;
  int iVar3;
  
  FUN_005c7d00();
  uVar1 = FUN_005bf1e0(0);
  iVar3 = (uVar1 & 0xffff) - 1;
  psVar2 = (short *)(iVar3 * 0x144 + 0x6ce5de);
  if (0 < *psVar2) {
    *psVar2 = *psVar2 + -1;
  }
  sRam006d2158 = (short)iVar3 + 1;
  sRam006d215a = *psVar2;
  uRam006cbc7e = 0x10;
  uRam006cbc84 = 0;
  FUN_005bdfe0(0xf);
  return;
}



================================================================