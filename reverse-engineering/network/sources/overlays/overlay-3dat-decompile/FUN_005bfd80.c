FUNCTION FUN_005bfd80 @ 0x005bfd80  size=72
CALLERS (3): FUN_0062d810@0x0062d810, FUN_005ad530@0x005ad530, FUN_005f8220@0x005f8220
CALLEES (2): FUN_005bf180@0x005bf180, FUN_005bf0e0@0x005bf0e0
----------------------------------------------------------------

undefined8 FUN_005bfd80(undefined8 param_1)

{
  code *pcVar1;
  undefined1 auStack_10 [16];
  
  uRam006ff2b1 = 0;
  FUN_005bf0e0(1,param_1);
  pcVar1 = (code *)FUN_005bf180(1);
  auStack_10[0] = 0;
  (*pcVar1)(auStack_10,auStack_10);
  return 0;
}



================================================================