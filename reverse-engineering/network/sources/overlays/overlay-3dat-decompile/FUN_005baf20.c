FUNCTION FUN_005baf20 @ 0x005baf20  size=72
CALLERS (1): FUN_005fe300@0x005fe300
CALLEES (1): FUN_005bac60@0x005bac60
----------------------------------------------------------------

undefined1 FUN_005baf20(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_005bac60(0);
  return *(undefined1 *)(iVar1 + (param_1 & 0xffff) * 0x1e4 + 3);
}



================================================================