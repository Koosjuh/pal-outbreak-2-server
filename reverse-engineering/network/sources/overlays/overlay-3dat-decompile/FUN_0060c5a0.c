FUNCTION FUN_0060c5a0 @ 0x0060c5a0  size=228
CALLERS (1): FUN_0060c6e0@0x0060c6e0
CALLEES (1): FUN_0060c230@0x0060c230
----------------------------------------------------------------

void FUN_0060c5a0(void)

{
  uRam0070d12c = 0;
  uRam0070d178 = uRam0070d114;
  iRam0070d17c = iRam0070d110;
  iRam0070d180 = iRam0070d120 + 1;
  iRam0070d184 = FUN_0060c230(((int)(bRam0070d11e + 7) >> 3) +
                              ((iRam0070d110 + 7U & 0xfffffff8) * (uint)bRam0070d11e + 7 >> 3) +
                              0x41);
  iRam0070d188 = iRam0070d184 + 0x20;
  uRam0070d18c = FUN_0060c230(iRam0070d120 + 1);
  func_0x00106b60(uRam0070d18c,0,iRam0070d120 + 1);
  uRam0070d1ac = 1;
  return;
}



================================================================