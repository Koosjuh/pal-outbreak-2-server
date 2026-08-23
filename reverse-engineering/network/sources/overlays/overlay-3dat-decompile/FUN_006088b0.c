FUNCTION FUN_006088b0 @ 0x006088b0  size=512
CALLERS (1): FUN_005ac8a0@0x005ac8a0
CALLEES (11): FUN_005ac380@0x005ac380, FUN_005de2a0@0x005de2a0, FUN_00606c80@0x00606c80, thunk_EXT_FUN_001b3720@0x005af360, FUN_00606ac0@0x00606ac0, FUN_005c80a0@0x005c80a0, FUN_00618b60@0x00618b60, FUN_005ac6f0@0x005ac6f0, FUN_005c8810@0x005c8810, FUN_00606a70@0x00606a70, FUN_005cd710@0x005cd710
----------------------------------------------------------------

void FUN_006088b0(void)

{
  long lVar1;
  
  if (cRam0070cd98 != '\x04') {
    if (cRam0070cd98 == '\x03') {
      cRam0070cd98 = 4;
      FUN_005ac380();
      func_0x001d4170(0);
      FUN_005ac6f0();
      return;
    }
    if (cRam0070cd98 == '\x02') {
      lVar1 = FUN_005c8810();
      if (lVar1 == -100) {
        FUN_005ac380();
        cRam0070cd98 = 1;
        return;
      }
      if (lVar1 == -1) {
        FUN_005ac380();
        uRam003c8a80 = 0;
        uRam0070cd80 = 0x85;
        FUN_00606ac0();
        return;
      }
      if (lVar1 == 2) {
        return;
      }
      if (lVar1 != 1) {
        return;
      }
      lVar1 = FUN_005cd710();
      if (lVar1 != 0) {
        FUN_005ac380();
        uRam003c8a80 = 0;
        cRam0070cd98 = 4;
        return;
      }
      uRam003c8a80 = 1;
      cRam0070cd98 = cRam0070cd98 + '\x01';
      return;
    }
    if (cRam0070cd98 == '\x01') {
      cRam0070cd98 = 2;
      func_0x00112b20(0);
      func_0x00106b60(0x701e20,0,0x100);
      FUN_005de2a0(iRam003435bc + 0x2ff000);
      uRam003c8a80 = 0;
      uRam00701f20 = 0;
      func_0x00109eb8(0x701e20,0x64a110);
      FUN_005c80a0(0);
      return;
    }
    if (cRam0070cd98 == '\0') {
      cRam0070cd98 = 1;
      FUN_00618b60();
      thunk_EXT_FUN_001b3720();
      uRam006c4fd7 = 0;
      return;
    }
  }
  lVar1 = FUN_00606a70();
  if (lVar1 != 0) {
    FUN_00606c80();
  }
  return;
}



================================================================