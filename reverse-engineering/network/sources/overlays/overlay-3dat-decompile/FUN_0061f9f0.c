FUNCTION FUN_0061f9f0 @ 0x0061f9f0  size=892
CALLERS (1): FUN_00622180@0x00622180
CALLEES (17): FUN_0061e750@0x0061e750, FUN_0061f8c0@0x0061f8c0, FUN_0061e940@0x0061e940, FUN_0061f9d0@0x0061f9d0, FUN_0061f270@0x0061f270, FUN_0061f680@0x0061f680, FUN_0061e800@0x0061e800, FUN_0061ea20@0x0061ea20, FUN_0061e7f0@0x0061e7f0, FUN_0061f0f0@0x0061f0f0, FUN_0061f250@0x0061f250, FUN_0061f4b0@0x0061f4b0, ...
----------------------------------------------------------------

int FUN_0061f9f0(void)

{
  long lVar1;
  ulong uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  if (cRam007152e1 != '\x1f') {
    if (cRam007152e1 != '\x1e') {
      if (cRam007152e1 != '\x06') {
        if (cRam007152e1 != '\x05') {
          if (cRam007152e1 != '\x04') {
            if (cRam007152e1 != '\x03') {
              if (cRam007152e1 != '\x02') {
                if (cRam007152e1 == '\x01') {
                  lVar1 = FUN_0061f9d0();
                  if (lVar1 == 0) {
                    return 0;
                  }
                  sRam007152e4 = 10;
                  cRam007152e1 = cRam007152e1 + '\x01';
                  FUN_0061f1a0();
                  FUN_0061f1b0();
                  FUN_0061f250();
                  FUN_0061f270(2,0);
                  FUN_0061f8c0();
                  return 0;
                }
                if (cRam007152e1 == '\0') {
                  lVar1 = FUN_0061f970();
                  if (lVar1 == 0) {
                    return 0;
                  }
                  uRam007152f0 = 0;
                  cRam007152e1 = cRam007152e1 + '\x01';
                  FUN_0061e940();
                  FUN_0061ea20(0);
                  return 0;
                }
                return 0;
              }
              FUN_0061f4b0(0x36);
              FUN_0061f680(1);
              if (sRam007152e4 != 0) {
                sRam007152e4 = sRam007152e4 + -1;
                return 0;
              }
              uVar2 = FUN_0061e750();
              if ((uVar2 & 2) == 0) {
                if ((uVar2 & 1) != 0) {
                  iVar4 = (int)sRam007152e8;
                  do {
                    iVar5 = iVar4 + -1;
                    if (iVar5 != 1) {
                      if (iVar5 == 0) {
                        FUN_0061e720();
                        sRam007152e8 = (short)iVar5;
                      }
                      goto LAB_0061fc18;
                    }
                    iVar4 = 1;
                  } while (cRam003c98a0 == '\0');
                  FUN_0061e720();
                  sRam007152e8 = (short)iVar5;
                }
              }
              else {
                lVar1 = (long)sRam007152e8;
                do {
                  while( true ) {
                    iVar4 = (int)lVar1 + 1;
                    lVar1 = (long)iVar4;
                    sVar3 = (short)iVar4;
                    if (lVar1 == 2) break;
                    if (lVar1 != 1) goto LAB_0061fc18;
                    if (cRam003c98a0 != '\0') {
                      FUN_0061e720();
                      sRam007152e8 = sVar3;
                      goto LAB_0061fc18;
                    }
                  }
                } while (cRam003c9580 == '\0');
                FUN_0061e720();
                sRam007152e8 = sVar3;
              }
LAB_0061fc18:
              FUN_0061f4b0((int)sRam007152e8 + 0x2dU & 0xff);
              lVar1 = FUN_0061e7f0();
              if (lVar1 == 0) {
                lVar1 = FUN_0061e800();
                if (lVar1 == 0) {
                  return 0;
                }
                cRam007152e1 = 0x1e;
                return 0;
              }
              if (sRam007152e8 != 2) {
                func_0x001a6910(0,0,10);
              }
              uRam003c8a80 = 0;
              FUN_0061f0f0(0x200);
              FUN_0061f0f0(2);
              FUN_0061f0f0(4);
              if (((sRam007152e8 != 2) && (sRam007152e8 != 1)) && (sRam007152e8 != 0)) {
                return 0;
              }
              cRam007152e1 = cRam007152e1 + '\x01';
              return 0;
            }
            cRam007152e1 = '\x04';
          }
          iVar4 = (int)sRam007152e8;
          FUN_0061f0f0(0x80);
          FUN_0061f0f0(0x100);
          return iVar4 + 1;
        }
        cRam007152e1 = '\x06';
        FUN_0061f0f0(0x80);
        FUN_0061f0f0(0x100);
      }
      return -1;
    }
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061f0d0();
  }
  return -1;
}



================================================================