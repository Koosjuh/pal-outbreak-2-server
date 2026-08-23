FUNCTION FUN_005ca380 @ 0x005ca380  size=152
CALLERS (0): 
CALLEES (5): FUN_005dedf0@0x005dedf0, FUN_005cce30@0x005cce30, FUN_005d5a40@0x005d5a40, FUN_005d74a0@0x005d74a0, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005ca380(void)

{
  FUN_005ca6a0();
  if (*(char *)(iRam00701070 + 0x2e) == '\n') {
    FUN_005dedf0(iRam00701068 + 0x4f97c,iRam00701070 + 0x3b);
    FUN_005d74a0(iRam00701068 + 0x4f97c);
    uRam00700fe8 = 1;
    FUN_005d5a40();
  }
  else if (*(char *)(iRam00701070 + 0x2e) == '\b') {
    FUN_005cce30();
  }
  return;
}



================================================================