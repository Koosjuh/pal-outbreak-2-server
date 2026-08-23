FUNCTION FUN_005bb060 @ 0x005bb060  size=72
CALLERS (2): FUN_005affb0@0x005affb0, FUN_005ba5b0@0x005ba5b0
CALLEES (1): FUN_005bac60@0x005bac60
----------------------------------------------------------------

int FUN_005bb060(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_005bac60(0);
  return iVar1 + (param_1 & 0xffff) * 0x1e4 + 0x34;
}



================================================================