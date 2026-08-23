FUNCTION FUN_005baed0 @ 0x005baed0  size=72
CALLERS (1): FUN_005fe1e0@0x005fe1e0
CALLEES (1): FUN_005bac60@0x005bac60
----------------------------------------------------------------

undefined4 FUN_005baed0(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_005bac60(0);
  return *(undefined4 *)(iVar1 + (param_1 & 0xffff) * 0x1e4 + 0x18);
}



================================================================