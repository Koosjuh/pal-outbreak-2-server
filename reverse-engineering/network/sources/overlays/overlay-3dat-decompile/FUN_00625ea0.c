FUNCTION FUN_00625ea0 @ 0x00625ea0  size=1860
CALLERS (1): FUN_00622180@0x00622180
CALLEES (16): FUN_0061e750@0x0061e750, FUN_0061f2d0@0x0061f2d0, FUN_0061f1f0@0x0061f1f0, FUN_0061f1d0@0x0061f1d0, FUN_0061f0e0@0x0061f0e0, FUN_0061e910@0x0061e910, FUN_0061f680@0x0061f680, FUN_0061e800@0x0061e800, FUN_0061e7f0@0x0061e7f0, FUN_0061f760@0x0061f760, FUN_0061f0f0@0x0061f0f0, FUN_0061f4b0@0x0061f4b0, ...
----------------------------------------------------------------

undefined4 FUN_00625ea0(void)

{
  ulong uVar1;
  long lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = FUN_0061e750();
  if (cRam007152e1 == '\x03') {
    FUN_0061f4b0(0xa5);
    FUN_0061f680(0xf);
    lVar2 = FUN_0061e910();
    if (lVar2 == 0) {
      FUN_0061f0e0();
      uVar3 = 0xffffffff;
    }
  }
  else if (cRam007152e1 == '\x02') {
    lVar2 = FUN_0061e910();
    if (lVar2 == 0) {
      FUN_0061f0e0();
      uVar3 = 1;
    }
  }
  else if (cRam007152e1 == '\x01') {
    if (cRam007152e2 == '\f') {
      sRam007152e4 = sRam007152e4 + -1;
      if (sRam007152e4 < 1) {
        cRam007152e2 = '\x01';
        sRam007152e4 = 10;
        sRam007152ea = 0;
        FUN_0061f1d0();
      }
    }
    else if (cRam007152e2 == '\v') {
      if (sRam007152e4 == 0) {
        lVar2 = FUN_0061e7f0();
        if (lVar2 == 0) {
          lVar2 = FUN_0061e800();
          if (lVar2 != 0) {
            sRam007152e4 = 10;
            cRam007152e2 = cRam007152e2 + '\x01';
            FUN_0061f0f0(0x10000);
            FUN_0061f0f0(0x400);
          }
        }
        else {
          cRam007152e2 = '\0';
          cRam007152e1 = '\x03';
          FUN_0061e960(0,0x14,1);
        }
      }
      else {
        sRam007152e4 = sRam007152e4 + -1;
      }
      if (cRam007152e2 != '\f') {
        FUN_0061f4b0(0xa5);
        FUN_0061f680(0xf);
      }
    }
    else if (cRam007152e2 == '\n') {
      sRam007152e4 = sRam007152e4 + -1;
      if (sRam007152e4 < 1) {
        cRam007152e2 = '\v';
        sRam007152e4 = 10;
        FUN_0061f470();
        FUN_0061f1f0();
      }
    }
    else if (cRam007152e2 == '\x03') {
      if (sRam007152e4 == 0) {
        uVar1 = FUN_0061e750();
        if ((uVar1 & 1) == 0) {
          if (((uVar1 & 2) != 0) && (sRam007152e8 != 1)) {
            FUN_0061e720();
            sRam007152e8 = 1;
          }
        }
        else if (sRam007152e8 != 0) {
          FUN_0061e720();
          sRam007152e8 = 0;
        }
        lVar2 = FUN_0061e7f0();
        if (lVar2 == 0) {
          lVar2 = FUN_0061e800();
          if (lVar2 != 0) {
            cRam007152e2 = '\n';
            sRam007152e4 = 10;
            FUN_0061f0e0();
          }
        }
        else if (sRam007152e8 == 0) {
          FUN_0061f0f0(0x200000);
          FUN_0061f0f0(0x80000);
          FUN_0061f0f0(0x100000);
          cRam007152e2 = '\0';
          cRam007152e1 = '\x02';
          FUN_0061e960(0,0x14,1);
        }
        else {
          cRam007152e2 = '\n';
          sRam007152e4 = 10;
          FUN_0061f0e0();
        }
      }
      else {
        sRam007152e4 = sRam007152e4 + -1;
      }
      if (cRam007152e2 != '\n') {
        FUN_0061f4b0(0xa6);
        FUN_0061f680(0x10);
      }
    }
    else if (cRam007152e2 == '\x02') {
      sRam007152e4 = sRam007152e4 + -1;
      if (sRam007152e4 < 1) {
        cRam007152e2 = '\x03';
        sRam007152e4 = 10;
        sRam007152e8 = 1;
        FUN_0061f1f0();
        FUN_0061f2d0(0x10,2);
      }
    }
    else if (cRam007152e2 == '\x01') {
      if (sRam007152e4 == 0) {
        if (((uVar1 & 8) == 0) || ((long)(int)(uRam00365cf0 - 1) <= (long)sRam007152ea)) {
          if (((uVar1 & 4) == 0) || (sRam007152ea < 1)) {
            lVar2 = FUN_0061e800();
            if (lVar2 != 0) {
              cRam007152e2 = 10;
              sRam007152e4 = 10;
              FUN_0061f0e0();
              return 0;
            }
            if (((long)sRam007152ea == (long)(int)(uRam00365cf0 - 1)) &&
               (lVar2 = FUN_0061e7f0(), lVar2 != 0)) {
              cRam007152e2 = 0;
              sRam007152e4 = 10;
              sRam007152ea = 0;
              FUN_0061f1d0();
              FUN_0061f2d0(0x10,2);
              sRam007152e8 = 1;
              return 0;
            }
          }
          else {
            sRam007152e4 = 10;
            sRam007152ea = sRam007152ea + -1;
            FUN_0061e720();
          }
        }
        else {
          sRam007152ea = sRam007152ea + 1;
          sRam007152e4 = 10;
          FUN_0061e720();
        }
      }
      else {
        sRam007152e4 = sRam007152e4 + -1;
      }
      FUN_0061f760(0x15);
    }
    else if (cRam007152e2 == '\0') {
      FUN_0061f760(0x13);
      FUN_0061f680(0x10);
      if (sRam007152e4 == 0) {
        lVar2 = FUN_0061e7f0();
        if (lVar2 == 0) {
          lVar2 = FUN_0061e800();
          if (lVar2 == 0) {
            if (((uVar1 & 1) == 0) || (sRam007152e8 < 1)) {
              if (((uVar1 & 2) != 0) && (sRam007152e8 < 2)) {
                FUN_0061e720();
                sRam007152e8 = sRam007152e8 + 1;
              }
            }
            else {
              FUN_0061e720();
              sRam007152e8 = sRam007152e8 + -1;
            }
          }
          else {
            cRam007152e2 = '\n';
            sRam007152e4 = 10;
            FUN_0061f0e0();
          }
        }
        else if (sRam007152e8 == 2) {
          FUN_0061f0f0(0x200000);
          FUN_0061f0f0(0x80000);
          FUN_0061f0f0(0x100000);
          sRam007152ea = 0;
          cRam007152e2 = '\x01';
        }
        else if (sRam007152e8 == 1) {
          cRam007152e2 = '\n';
          sRam007152e4 = 10;
          FUN_0061f0e0();
        }
        else if (sRam007152e8 == 0) {
          FUN_0061f0f0(0x200000);
          FUN_0061f0f0(0x80000);
          FUN_0061f0f0(0x100000);
          cRam007152e2 = '\0';
          cRam007152e1 = '\x02';
          FUN_0061e960(0,0x14,1);
        }
      }
      else {
        sRam007152e4 = sRam007152e4 + -1;
      }
    }
  }
  else if (cRam007152e1 == '\0') {
    FUN_0061f1a0();
    FUN_0061f1d0();
    sRam007152ea = 0;
    cRam007152e2 = '\x01';
    sRam007152e4 = 10;
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061e960(0,0x14,0);
    sRam007152e8 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



================================================================