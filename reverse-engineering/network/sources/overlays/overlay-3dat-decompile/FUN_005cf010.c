FUNCTION FUN_005cf010 @ 0x005cf010  size=296
CALLERS (0): 
CALLEES (5): FUN_005d5f40@0x005d5f40, FUN_005d5ed0@0x005d5ed0, FUN_005d5c20@0x005d5c20, FUN_0061e730@0x0061e730, FUN_005d5b60@0x005d5b60
----------------------------------------------------------------

void FUN_005cf010(void)

{
  FUN_005d5f40(2);
  if (((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x10) != 0) ||
     (*(char *)(iRam00715da8 + 0x49c) == '(')) {
    if (*(char *)(iRam00701078 + 2) == '\x02') {
      FUN_005d5ed0(0);
    }
    else if (*(char *)(iRam00701078 + 2) == '\x01') {
      func_0x001069a8(0x870f10,uRam00701088,0x1d0);
      if (*(char *)(iRam00701070 + 0x2e) != '\b') {
        FUN_0061e730(0xb);
        uRam00701e18 = 1;
        FUN_005d5b60(0);
        return;
      }
      FUN_005d5c20();
      return;
    }
  }
  if (((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x200) != 0) ||
     (*(char *)(iRam00715da8 + 0x49c) == ')')) {
    FUN_005d5ed0(0);
  }
  return;
}



================================================================