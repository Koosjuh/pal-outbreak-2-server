FUNCTION FUN_005bae30 @ 0x005bae30  size=72
CALLERS (1): FUN_0062c9f0@0x0062c9f0
CALLEES (1): FUN_005bac60@0x005bac60
----------------------------------------------------------------

undefined1 FUN_005bae30(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_005bac60(0);
  return *(undefined1 *)(iVar1 + (param_1 & 0xffff) * 0x1e4);
}



================================================================