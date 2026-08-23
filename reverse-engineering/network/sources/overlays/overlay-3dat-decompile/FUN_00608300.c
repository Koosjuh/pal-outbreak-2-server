FUNCTION FUN_00608300 @ 0x00608300  size=876
CALLERS (1): FUN_005ac8a0@0x005ac8a0
CALLEES (9): FUN_005ac380@0x005ac380, FUN_005de2a0@0x005de2a0, thunk_EXT_FUN_001b3720@0x005af360, FUN_00606ac0@0x00606ac0, FUN_005c80a0@0x005c80a0, FUN_00618b60@0x00618b60, FUN_005c8810@0x005c8810, thunk_FUN_006235f0@0x006088a0, FUN_00606f10@0x00606f10
----------------------------------------------------------------

void FUN_00608300(void)

{
  long lVar1;
  
  if (cRam0070cda8 == '\x06') {
    FUN_00606f10();
    func_0x003adb70();
    uRam006c4fd7 = 1;
  }
  else if (cRam0070cda8 == '\x05') {
    cRam0070cda8 = '\x06';
  }
  else if (cRam0070cda8 == '\x04') {
    thunk_EXT_FUN_001b3720();
    cRam0070cda8 = '\x05';
  }
  else if (cRam0070cda8 == '\x03') {
    cRam0070cda8 = '\x04';
    FUN_005ac380();
  }
  else if (cRam0070cda8 == 'c') {
    cRam0070cda8 = '\x02';
    FUN_005de2a0(iRam003435bc + 0x2ff000);
    func_0x00106b60(0x701e20,0,0x100);
    func_0x00109eb8(0x701e20,0x64a110);
    uRam00701f20 = 0;
    FUN_005c80a0(0);
  }
  else if (cRam0070cda8 == '\x02') {
    lVar1 = FUN_005c8810();
    if (lVar1 == -100) {
      FUN_005ac380();
      thunk_FUN_006235f0();
    }
    else if (lVar1 == -1) {
      FUN_005ac380();
      cRam003c8a80 = '\0';
      uRam0070cd80 = 0x85;
      FUN_00606ac0();
    }
    else if (lVar1 == 2) {
      FUN_005ac380();
      cRam003c8a80 = '\0';
      cRam0070cda8 = 'c';
    }
    else if (lVar1 == 1) {
      if ((cRam003c8a80 == '\x02') ||
         ((cRam003c8a80 != '\x02' && (*(char *)(iRam00701070 + 0x2e) == '\0')))) {
        FUN_005ac380();
        cRam003c8a80 = '\0';
        FUN_00606ac0();
      }
      else {
        cRam0070cda8 = cRam0070cda8 + '\x01';
        cRam003c8a80 = '\x01';
      }
    }
  }
  else if (cRam0070cda8 == '\x01') {
    cRam0070cda8 = '\x02';
    func_0x00112b20(0);
    func_0x00106b60(0x701e20,0,0x100);
    if (cRam003c8a80 == '\x02') {
      FUN_005de2a0(iRam003435bc + 0x2ff000);
      uRam00701f20 = 1;
      func_0x00109eb8(0x701e20,0x8711fd);
      FUN_005c80a0(0);
    }
    else if (cRam003c8a80 == '\x01') {
      FUN_005de2a0(iRam003435bc + 0x2ff000);
      func_0x00109eb8(0x701e20,0x8710fc);
      uRam00701f20 = 0;
      FUN_005c80a0(0);
    }
    else {
      FUN_005de2a0(iRam003435bc + 0x2ff000);
      cRam003c8a80 = '\0';
      uRam00701f20 = 0;
      func_0x00109eb8(0x701e20,0x64a110);
      FUN_005c80a0(0);
    }
  }
  else if (cRam0070cda8 == '\0') {
    cRam0070cda8 = '\x01';
    FUN_00618b60();
    func_0x003adb80();
    thunk_EXT_FUN_001b3720();
    uRam006c4fd7 = 0;
  }
  return;
}



================================================================