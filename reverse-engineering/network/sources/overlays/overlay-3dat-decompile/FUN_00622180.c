FUNCTION FUN_00622180 @ 0x00622180  size=2724
CALLERS (1): FUN_00621f10@0x00621f10
CALLEES (25): FUN_00622c30@0x00622c30, FUN_00626900@0x00626900, FUN_00626e70@0x00626e70, FUN_00623670@0x00623670, FUN_00623360@0x00623360, FUN_006231b0@0x006231b0, FUN_00627540@0x00627540, FUN_00625190@0x00625190, FUN_00623090@0x00623090, FUN_006265f0@0x006265f0, FUN_006233e0@0x006233e0, FUN_0061f9f0@0x0061f9f0, ...
----------------------------------------------------------------

undefined4 FUN_00622180(void)

{
  char cVar1;
  char *pcVar2;
  long lVar3;
  undefined4 extraout_a0_lo;
  
  cVar1 = *pcRam00715298;
  if (((cVar1 == '+') || (cVar1 == '*')) || (cVar1 == '(')) {
    lVar3 = FUN_00623670();
    if (lVar3 != 0) {
      return 1;
    }
  }
  else if (cVar1 == '5') {
    lVar3 = FUN_00627540();
    if (lVar3 == 1) {
      uRam0071543c = 0;
      FUN_00621fb0(0x25);
    }
    else if (lVar3 != 0) {
      FUN_00621fb0(0x2e);
    }
  }
  else if (cVar1 == '4') {
    lVar3 = FUN_00627400();
    if (lVar3 == 1) {
      FUN_00621fb0(0x35);
    }
    else if (lVar3 != 0) {
      FUN_00621fb0(0x2e);
    }
  }
  else if (cVar1 == '3') {
    lVar3 = FUN_00626e70();
    if (lVar3 == 2) {
      FUN_00621fb0(0x2e);
    }
    else if (lVar3 == 1) {
      FUN_00621fb0(0x34);
    }
    else if (lVar3 != 0) {
      iRam00715478 = 1;
      cRam007152d0 = '\0';
      uRam007152a0 = 0;
      FUN_00621fb0(0x2c);
    }
  }
  else if (cVar1 == '2') {
    func_0x001ca720();
    lVar3 = FUN_00626900();
    func_0x001ca750();
    if (lVar3 == 3) {
      FUN_00621fb0(0x2c);
    }
    else if (lVar3 == 2) {
      FUN_00621fb0(0x31);
    }
    else if (lVar3 == 1) {
      if (cRam007152d0 == '\0') {
        FUN_00621fb0(0x33);
      }
      else {
        FUN_00621fb0(0x34);
      }
    }
    else if (lVar3 != 0) {
      FUN_00621fb0(0x28);
    }
  }
  else if (cVar1 == '1') {
    uRam0071543c = 1;
    lVar3 = FUN_00625190();
    if (lVar3 == 1) {
      uRam0071543c = 0;
      FUN_00621fb0(0x32);
    }
    else if (lVar3 != 0) {
      FUN_00621fb0(0x2e);
    }
  }
  else if (cVar1 == '0') {
    lVar3 = FUN_00624c70();
    if (lVar3 == 2) {
      FUN_00621fb0(0x2f);
    }
    else if (lVar3 == 1) {
      FUN_00621fb0(0x2e);
    }
    else if (lVar3 != 0) {
      FUN_00621fb0(0x2e);
    }
  }
  else if (cVar1 == '/') {
    uRam0071543c = 1;
    lVar3 = FUN_006265f0();
    if (lVar3 == 1) {
      FUN_00621fb0(0x31);
    }
    else if (lVar3 != 0) {
      FUN_00621fb0(0x2e);
    }
  }
  else if (cVar1 == '.') {
    uRam0071543c = 1;
    lVar3 = FUN_00624850();
    if (lVar3 == 2) {
      uRam0071543c = 0;
      FUN_00621fb0(0x30);
    }
    else if (lVar3 == 1) {
      FUN_00621fb0(0x2f);
    }
    else if (lVar3 != 0) {
      FUN_00621fb0(0x28);
    }
  }
  else if (cVar1 == '-') {
    uRam0071543c = 1;
    lVar3 = FUN_00625ea0();
    if (lVar3 != 0) {
      if (lVar3 == 1) {
        FUN_00621fb0(0x2e);
      }
      else {
        FUN_00621fb0(0x28);
      }
    }
  }
  else if (cVar1 == ',') {
    uRam0071543c = 1;
    lVar3 = FUN_00625670();
    if (lVar3 != -1) {
      if (lVar3 == 1) {
        if (iRam00715478 == 0) {
          FUN_00621fb0(0x2d);
        }
        else {
          FUN_00621fb0(0x2e);
        }
        iRam00715478 = 0;
        goto LAB_00622be4;
      }
      if (lVar3 == 0) goto LAB_00622be4;
    }
    FUN_00621fb0(0x28);
    iRam00715478 = 0;
  }
  else if (cVar1 != '\'') {
    if (cVar1 == '%') {
      uRam0071543c = 0;
      lVar3 = FUN_006233e0();
      if (lVar3 == 1) {
        func_0x001a7e90(0x622130);
        func_0x001a6780();
        FUN_00621fb0(0x27);
      }
      else if (lVar3 != 0) {
        FUN_00621fb0(0x28);
      }
    }
    else if (cVar1 == '!') {
      uRam0071543c = 1;
      lVar3 = FUN_006205c0();
      if (lVar3 == 1) {
        pcRam00715298[0x11] = '\x01';
        FUN_00621fb0(0x2c);
      }
      else if (lVar3 != 0) {
        pcRam00715298[0x11] = '\x01';
        lVar3 = func_0x001afb60(0xd);
        if (lVar3 == 0) {
          FUN_00621fb0(0x28);
        }
        else {
          FUN_00621fb0(0x2c);
        }
      }
    }
    else if (cVar1 == '\x1f') {
      uRam0071543c = 1;
      lVar3 = FUN_00620b60();
      if (lVar3 != 0) {
        pcRam00715298[0x11] = '\x01';
        FUN_00621fb0(0x21);
      }
    }
    else if (cVar1 == '\x1a') {
      uRam0071543c = 1;
      lVar3 = FUN_00623360();
      if (lVar3 == 1) {
        pcRam00715298[0xe] = '\x03';
        pcRam00715298[0x11] = '\0';
        FUN_00621fb0(6);
      }
      else if (lVar3 != 0) {
        return 0;
      }
    }
    else if (cVar1 == '\b') {
      uRam0071543c = 1;
      lVar3 = FUN_0061fd70();
      if (lVar3 == 1) {
        pcRam00715298[0x11] = '\0';
        FUN_00621fb0(4);
        pcVar2 = pcRam00715298;
        if (pcRam00715298[0x10] == '\0') {
          pcVar2[8] = '\0';
          pcVar2[9] = '\0';
        }
        else {
          pcVar2[8] = '\x01';
          pcVar2[9] = '\0';
        }
      }
      else if (lVar3 != 0) {
        pcRam00715298[0x11] = '\0';
        FUN_00621fb0(4);
        pcVar2 = pcRam00715298;
        pcVar2[8] = '\x02';
        pcVar2[9] = '\0';
      }
    }
    else if (cVar1 == '\a') {
      uRam0071543c = 1;
      lVar3 = FUN_006231b0();
      if (lVar3 == 1) {
        pcRam00715298[0x11] = '\0';
        FUN_00621fb0(0x1f);
      }
      else if (lVar3 != 0) {
        pcRam00715298[0x11] = '\x01';
        uRam00715474 = 0;
        FUN_00621fb0(4);
      }
    }
    else if (cVar1 == '\x06') {
      uRam0071543c = 1;
      lVar3 = FUN_00623090();
      if (lVar3 == 1) {
        func_0x001ad8b0(0);
        pcRam00715298[0x11] = '\x01';
        pcRam00715298[0xe] = '\0';
        FUN_00621fb0(7);
      }
      else if (lVar3 != 0) {
        func_0x001ad8b0(0);
        pcRam00715298[0x11] = '\x01';
        pcRam00715298[0xe] = '\0';
        uRam00715474 = 0;
        FUN_00621fb0(4);
      }
    }
    else if (cVar1 == '\x05') {
      uRam0071543c = 1;
      lVar3 = FUN_00620250();
      if (lVar3 == 1) {
        pcRam00715298[0xe] = '\x03';
        pcRam00715298[0x11] = '\0';
        FUN_00621fb0(6);
      }
      else if (lVar3 != 0) {
        pcRam00715298[0x11] = '\0';
        FUN_00621fb0(4);
        pcVar2 = pcRam00715298;
        if (pcRam00715298[0x10] == '\0') {
          pcVar2[8] = '\0';
          pcVar2[9] = '\0';
        }
        else {
          pcVar2[8] = '\x01';
          pcVar2[9] = '\0';
        }
      }
    }
    else if (cVar1 == '\x04') {
      if ((cRam003c98a0 == '\0') || (uRam00715474 == 0)) {
        uRam0071543c = 1;
        lVar3 = FUN_0061f9f0();
        if (lVar3 == 3) {
          pcRam00715298[0x11] = '\0';
          FUN_00621fb0(8);
          goto LAB_00622be4;
        }
        if (lVar3 != 2) {
          if (lVar3 == 1) {
            pcRam00715298[0xe] = '\x03';
            uRam007152f0 = 0;
            pcRam00715298[0x11] = '\0';
            FUN_00621fb0(6);
          }
          else if (lVar3 != 0) {
            pcRam00715298[0x11] = '\0';
            FUN_00621fb0(0x2a);
          }
          goto LAB_00622be4;
        }
      }
      pcRam00715298[0x11] = '\0';
      FUN_00621fb0(0x1a);
    }
    else {
      if (cVar1 == '\x03') {
        return 0;
      }
      if (cVar1 == '\x02') {
        uRam0071543c = 1;
        lVar3 = FUN_00622f40();
        if (lVar3 == 1) {
          pcRam00715298[0xc] = '\x01';
          pcRam00715298[0x11] = '\0';
          pcVar2 = pcRam00715298;
          if (cRam003c98a0 == '\0') {
            pcVar2[8] = '\0';
            pcVar2[9] = '\0';
          }
          else {
            pcVar2[8] = '\x01';
            pcVar2[9] = '\0';
          }
          FUN_00621fb0(4);
        }
        else if (lVar3 != 0) {
          FUN_00621fb0(0x2b);
        }
      }
      else if (cVar1 == '\x01') {
        uRam0071543c = 1;
        lVar3 = FUN_00622d60();
        if (lVar3 == 1) {
          FUN_00621fb0(2);
        }
        else if (lVar3 != 0) {
          FUN_00621fb0(0x2b);
        }
      }
      else if ((cVar1 == '\0') && (lVar3 = FUN_00622c30(), lVar3 != 0)) {
        FUN_00621fb0(1);
        uRam00715474 = (uint)bRam0034365c;
        uRam0071543c = extraout_a0_lo;
      }
    }
  }
LAB_00622be4:
  if ((pcRam00715298[0xe] & 1U) == 0) {
    FUN_0061e8f0(0);
  }
  return 0;
}



================================================================