FUNCTION FUN_005baf70 @ 0x005baf70  size=72
CALLERS (1): FUN_005fe300@0x005fe300
CALLEES (1): FUN_005bac60@0x005bac60
----------------------------------------------------------------

int FUN_005baf70(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_005bac60(0);
  return iVar1 + (param_1 & 0xffff) * 0x1e4 + 4;
}



================================================================