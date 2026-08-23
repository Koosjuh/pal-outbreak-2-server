FUNCTION FUN_005bb010 @ 0x005bb010  size=72
CALLERS (2): FUN_005ad350@0x005ad350, FUN_0062c9f0@0x0062c9f0
CALLEES (1): FUN_005bac60@0x005bac60
----------------------------------------------------------------

undefined1 FUN_005bb010(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_005bac60(0);
  return *(undefined1 *)(iVar1 + (param_1 & 0xffff) * 0x1e4 + 2);
}



================================================================