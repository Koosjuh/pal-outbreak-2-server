FUNCTION FUN_0060c9e0 @ 0x0060c9e0  size=160
CALLERS (2): FUN_0060cb40@0x0060cb40, FUN_0060dea0@0x0060dea0
CALLEES (1): FUN_0060ca90@0x0060ca90
----------------------------------------------------------------

long FUN_0060c9e0(long param_1,long param_2)

{
  long lVar1;
  
  if (((cRam0070d11e == '\b') && (param_2 != 0x20)) && (param_2 != 0x40)) {
    lVar1 = param_1;
    if (((param_1 != 0x80) && (param_1 != 0x100)) &&
       ((param_1 != 0x200 && ((lVar1 = 0x80, 0x7f < param_1 && (lVar1 = 0x200, param_1 < 0x100))))))
    {
      lVar1 = 0x100;
    }
  }
  else {
    lVar1 = FUN_0060ca90();
  }
  return lVar1;
}



================================================================