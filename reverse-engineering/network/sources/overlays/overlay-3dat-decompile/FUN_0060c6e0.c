FUNCTION FUN_0060c6e0 @ 0x0060c6e0  size=768
CALLERS (1): FUN_0060d1d0@0x0060d1d0
CALLEES (6): FUN_0060ae40@0x0060ae40, FUN_0060c2d0@0x0060c2d0, FUN_0060c5a0@0x0060c5a0, FUN_0060c330@0x0060c330, FUN_0060c690@0x0060c690, FUN_0060c250@0x0060c250
----------------------------------------------------------------

void FUN_0060c6e0(undefined8 param_1)

{
  long lVar1;
  
  if (cRam0070d1ac == '\0') {
    FUN_0060c5a0();
  }
  pcRam0070d138 = pcRam0070d188;
  iRam0070d13c = iRam0070d180;
  do {
    if (uRam0070d12c == 0) {
      while (uRam0070d194 == 0) {
        FUN_0060c2d0(0x70d100,4);
        FUN_0060c2d0();
        uRam0070d194 = (uint)pbRam0070d108[3] +
                       (uint)pbRam0070d108[2] * 0x100 +
                       (uint)*pbRam0070d108 * 0x1000000 + (uint)pbRam0070d108[1] * 0x10000;
        FUN_0060c2d0();
        lVar1 = func_0x00106910(pbRam0070d108,0x693540,4);
        if (lVar1 != 0) {
          lVar1 = func_0x00106910(pbRam0070d108,0x693548,4);
          if (lVar1 == 0) goto LAB_0060c8cc;
          FUN_0060c2d0(0x70d100,uRam0070d194);
          uRam0070d194 = 0;
        }
        if (cRam0070d10c != '\0') goto LAB_0060c8cc;
      }
      uRam0070d12c = uRam0070d174;
      uRam0070d128 = uRam0070d170;
      if (uRam0070d194 < uRam0070d174) {
        uRam0070d12c = uRam0070d194;
      }
      FUN_0060c250(0x70d100,uRam0070d170,uRam0070d12c);
      if (cRam0070d10c != '\0') break;
      uRam0070d194 = uRam0070d194 - uRam0070d12c;
    }
    lVar1 = FUN_0060ae40(0x70d128,1);
    if (lVar1 == 1) break;
    if (lVar1 < 0) {
      cRam0070d10c = (char)lVar1;
      return;
    }
  } while (iRam0070d13c != 0);
LAB_0060c8cc:
  uRam0070d1a0 = uRam0070d119;
  iRam0070d198 = iRam0070d17c;
  uRam0070d1a2 = uRam0070d11d;
  uRam0070d1a1 = uRam0070d118;
  bRam0070d1a3 = bRam0070d11e;
  uRam0070d19c = iRam0070d17c * (uint)bRam0070d11e + 7 >> 3;
  if (*pcRam0070d188 != '\0') {
    FUN_0060c330(0x70d198,pcRam0070d188 + 1,iRam0070d18c + 1,*pcRam0070d188);
  }
  func_0x001069a8(iRam0070d18c,pcRam0070d188,iRam0070d120 + 1);
  func_0x001069a8(param_1,pcRam0070d188 + 1,iRam0070d110 * (uint)bRam0070d1a3 + 7 >> 3);
  FUN_0060c690();
  return;
}



================================================================