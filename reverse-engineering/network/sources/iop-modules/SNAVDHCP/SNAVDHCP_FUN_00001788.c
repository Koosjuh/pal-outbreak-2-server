FUNCTION FUN_00001788 @ 0x00001788 size=644
CALLERS (3): FUN_00000d68@0x00000d68, FUN_00000cac@0x00000cac, FUN_00000248@0x00000248
CALLEES (7): FUN_00002d04@0x00002d04, FUN_00002130@0x00002130, FUN_00001d38@0x00001d38, FUN_00001438@0x00001438, FUN_00001a94@0x00001a94, FUN_00002110@0x00002110, FUN_00002150@0x00002150

int FUN_00001788(void)

{
  int iVar1;
  uint uVar2;
  
  DAT_00002f50 = 0;
  if (DAT_00002eb0 == 1) {
    iVar1 = FUN_00001a94();
  }
  else if (DAT_00002eb0 == 2) {
    iVar1 = FUN_00001d38();
  }
  else if (DAT_00002eb0 == 6) {
    iVar1 = FUN_00002150();
  }
  else {
    iVar1 = DAT_00002eb0;
    if ((((DAT_00002eb0 == 3) || (DAT_00002eb0 == 4)) || (DAT_00002eb0 == 5)) &&
       (DAT_00004298 != 0xffffffff)) {
      iVar1 = FUN_00002d04();
      uVar2 = DAT_00004290 + (iVar1 - DAT_00004294);
      DAT_000042a4 = DAT_000042a4 + uVar2 / 1000;
      DAT_00004290 = uVar2 % 1000;
      DAT_00004294 = iVar1;
      if (DAT_000042a4 < DAT_00004298) {
        if ((DAT_00002eb0 != 5) && (DAT_000042a0 <= DAT_000042a4)) {
          DAT_00002eb0 = 5;
          DAT_00002f7c = 0;
        }
        if (((DAT_00002eb0 != 4) && (DAT_00002eb0 != 5)) && (DAT_0000429c <= DAT_000042a4)) {
          DAT_00002eb0 = 4;
          DAT_00002f7c = 0;
        }
        if (DAT_00002eb0 == 4) {
          iVar1 = FUN_00002130();
        }
        else {
          iVar1 = DAT_00002eb0;
          if (DAT_00002eb0 == 5) {
            iVar1 = FUN_00002110();
          }
        }
      }
      else {
        if (-1 < DAT_00002f88) {
          FUN_00001438();
          DAT_00002f88 = -1;
        }
        DAT_00002eb0 = -1;
        DAT_00002f50 = 9;
        iVar1 = DAT_00002eb0;
      }
    }
  }
  return iVar1;
}


================================================================