
undefined4 FUN_001c2770(char *param_1,short *param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  
  FUN_001c0670(1,0x1a,1,0x2484a0);
  cVar1 = *param_1;
  if (cVar1 == '\x14') {
    sVar2 = *param_2;
    *param_2 = sVar2 + -1;
    if (sVar2 < 1) {
      *param_2 = 0;
      *param_1 = '\0';
      *param_2 = 0;
      return 1;
    }
    return 0;
  }
  if (cVar1 == '\n') {
    sVar2 = *param_2;
    *param_2 = sVar2 + -1;
    if (sVar2 < 1) {
      *param_2 = 0;
      *param_1 = '\x14';
      *param_2 = 0;
      return 0;
    }
    return 0;
  }
  if (cVar1 == '\t') {
    sVar2 = *param_2;
    *param_2 = sVar2 + -1;
    if (sVar2 < 1) {
      *param_2 = 0;
      FUN_001ee6e0();
      *param_1 = *param_1 + '\x01';
      *param_2 = 0x14;
      return 0;
    }
    return 0;
  }
  if (cVar1 != '\b') {
    if (cVar1 == '\a') {
      *param_2 = *param_2 + -1;
      if (*param_2 < 0) {
        *param_1 = *param_1 + '\x01';
        *param_2 = 0;
      }
      else if (((int)*param_2 % 0x1e == 0) &&
              ((lVar4 = FUN_001eeb50(0x35a6d0), sRam0035a6dc == 0 || (lVar4 < 0)))) {
        *param_1 = *param_1 + '\x01';
        *param_2 = 0;
      }
      return 0;
    }
    if (cVar1 == '\x06') {
      iVar3 = *piRam0035c3d8;
      if (iVar3 == 1) {
        if ((cRam0035bec8 == '\0') || (cRam0035bec8 == '\x01')) {
          FUN_001eef50();
          *param_2 = 0x1e;
          *param_1 = *param_1 + '\x02';
        }
        else if (cRam0035bec8 == '\x02') {
          FUN_001eed60(0);
          *param_2 = 300;
          *param_1 = *param_1 + '\x01';
        }
      }
      else if ((iVar3 == 3) || (iVar3 == 2)) {
        FUN_001eed60(0);
        *param_2 = 300;
        *param_1 = *param_1 + '\x01';
      }
      return 0;
    }
    if (cVar1 == '\x05') {
      lVar4 = FUN_001ef0d0();
      if (((lVar4 != -1) && (lVar4 != -2)) && (lVar4 != 0)) {
        sVar2 = *param_2;
        *param_2 = sVar2 + -1;
        if (0 < sVar2) {
          return 0;
        }
        *param_2 = 0;
      }
      FUN_001ef070();
      *param_1 = *param_1 + '\x01';
      *param_2 = 0;
      return 0;
    }
    if (cVar1 == '\x04') {
      uRam0035a6c4 = 0;
      uRam0035a6c0 = uRam0035ba98;
      lVar4 = FUN_001ef190(0x35a6c0);
      if (lVar4 == 0) {
        *param_1 = *param_1 + '\x01';
        *param_2 = 300;
      }
      else {
        FUN_001ef070();
        *param_1 = *param_1 + '\x02';
      }
      return 0;
    }
    if (cVar1 != '\x03') {
      if (cVar1 == '\x02') {
        sVar2 = *param_2;
        *param_2 = sVar2 + -1;
        if (sVar2 < 1) {
          *param_2 = 0;
          lVar4 = FUN_001ee190();
          if (lVar4 == 2) {
            *param_1 = '\x06';
          }
          else {
            *param_1 = *param_1 + '\x01';
          }
          return 0;
        }
        return 0;
      }
      if (cVar1 == '\x01') {
        FUN_001ee5f0(0x35a6f4);
        FUN_00106b60(0x35a6f0,0,0x2c);
        uRam0035a6f4 = 0xffffffff;
        *param_1 = *param_1 + '\x01';
        *param_2 = 0;
        return 0;
      }
      if (cVar1 != '\0') {
        return 0;
      }
      lVar4 = FUN_001ee190();
      if (lVar4 == 0) {
        *param_1 = '\x14';
        *param_2 = 0;
      }
      else {
        lVar4 = FUN_001ee190();
        if (lVar4 == 3) {
          *param_1 = *param_1 + '\x01';
          *param_2 = 0;
          return 0;
        }
        *param_1 = '\x02';
        *param_2 = 0;
      }
      return 0;
    }
    FUN_001ee770();
    if (*piRam0035c3d8 == 1) {
      if (cRam0035bec8 == '\x02') {
        FUN_001eeb30(0);
        *param_1 = '\x06';
      }
      else if (cRam0035bec8 == '\x01') {
        FUN_001ef000(0,uRam0035ba88);
        FUN_001eeec0(0);
        *param_1 = *param_1 + '\x01';
      }
      else if (cRam0035bec8 == '\0') {
        FUN_001ef000(0,uRam0035ba88);
        FUN_001eeec0(0);
        *param_1 = '\x06';
      }
    }
    else {
      FUN_001eeb30(0);
      *param_1 = '\x06';
    }
    return 0;
  }
  sVar2 = *param_2;
  *param_2 = sVar2 + -1;
  if (0 < sVar2) {
    return 0;
  }
  *param_2 = 0;
  iVar3 = *piRam0035c3d8;
  if (iVar3 == 1) {
    if ((cRam0035bec8 == '\0') || (cRam0035bec8 == '\x01')) {
      FUN_001eef80();
    }
    else if (cRam0035bec8 == '\x02') {
      FUN_001eed90();
    }
  }
  else {
    if ((iVar3 != 3) && (iVar3 != 2)) {
      cVar1 = *param_1;
      goto LAB_001c2cc4;
    }
    FUN_001eed90();
  }
  cVar1 = *param_1;
LAB_001c2cc4:
  *param_1 = cVar1 + '\x01';
  *param_2 = 0x14;
  return 0;
}

