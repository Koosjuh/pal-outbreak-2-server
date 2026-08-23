FUNCTION FUN_005acab0 @ 0x005acab0  size=676
CALLERS (1): FUN_005aca20@0x005aca20
CALLEES (25): FUN_005aec70@0x005aec70, FUN_005be330@0x005be330, FUN_005b24e0@0x005b24e0, FUN_005aefb0@0x005aefb0, FUN_005fe620@0x005fe620, FUN_005ff950@0x005ff950, FUN_005f6aa0@0x005f6aa0, FUN_005b1d10@0x005b1d10, FUN_005af4d0@0x005af4d0, FUN_005f76f0@0x005f76f0, FUN_005ae3e0@0x005ae3e0, FUN_005f8d40@0x005f8d40, ...
----------------------------------------------------------------

void FUN_005acab0(void)

{
  long lVar1;
  
  lVar1 = FUN_005be330(uRam0035a6f4);
  if (lVar1 != 0) {
    uRam006c50e8 = 0xe10;
  }
  lVar1 = FUN_005aedc0(0x6c4b90);
  if (lVar1 == 0) {
    FUN_005aefb0(0x6c4b90);
    FUN_005af090(0x6c4b90);
    FUN_00627a20();
    if (cRam006c4fc4 != '\0') {
      cRam006c4fc4 = cRam006c4fc4 + -1;
    }
    uRam006c5524 = 0;
    lVar1 = FUN_005ae770(0x6c4b90);
    if (lVar1 == 0) {
      lVar1 = FUN_005ae3e0(0x6c4b90);
      if (lVar1 == 0) {
        uRam006c5522 = 0;
        if (cRam006c4fbc == '\0') {
          switch(cRam006c4b90) {
          case '\0':
            FUN_005b24e0(0x6c4b90);
            break;
          case '\x01':
            thunk_FUN_005ace00(0x6c4b90);
            break;
          case '\x02':
            FUN_005f76f0(0x6c4b90);
            break;
          case '\x03':
            FUN_005f8d40(0x6c4b90);
            break;
          case '\x04':
            FUN_005fe620(0x6c4b90);
            break;
          case '\x05':
            FUN_00616c40(0x6c4b90);
            break;
          case '\x06':
            FUN_005f6aa0(0x6c4b90);
            break;
          case '\a':
            FUN_005ade20(0x6c4b90);
            break;
          case '\b':
            FUN_006177d0(0x6c4b90);
            break;
          case '\v':
            FUN_00617a50(0x6c4b90);
            break;
          case '\f':
            FUN_005ff950(0x6c4b90);
            break;
          case '\x0e':
            FUN_0062d5e0(0x6c4b90);
            break;
          case '\x0f':
            FUN_005af4d0(0x6c4b90);
          }
          FUN_00618c30();
          FUN_005b1d20(0x6c4b90);
        }
        else if (((((cRam006c4b90 == '\x05') || (cRam006c4b90 == '\x0e')) || (cRam006c4b90 == '\f'))
                 || ((cRam006c4b90 == '\x04' || (cRam006c4b90 == '\x03')))) ||
                (cRam006c4b90 == '\x02')) {
          lVar1 = FUN_005aec70(0x6c4b90);
          if (lVar1 == 0) {
            FUN_005b1a00(0x6c4b90);
            FUN_00618c30();
          }
          else {
            FUN_005b1d10(0x6c4b90);
            FUN_00618c30();
          }
        }
        else {
          FUN_005b1a00(0x6c4b90);
          FUN_00618c30();
        }
      }
      else {
        FUN_00618c30();
      }
    }
    else {
      FUN_00618c30();
    }
    if ((cRam006c5560 != '\0') && (cRam006c5560 = cRam006c5560 + -1, cRam006c5560 == '\0')) {
      uRam006c555f = 0;
    }
    iRam006c4fb0 = iRam006c4fb0 + 1;
  }
  return;
}



================================================================