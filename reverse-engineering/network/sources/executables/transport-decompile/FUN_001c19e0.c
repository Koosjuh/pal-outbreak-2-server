
undefined4
FUN_001c19e0(undefined1 *param_1,char *param_2,undefined8 param_3,undefined8 param_4,short *param_5,
            short *param_6,undefined2 *param_7,undefined1 *param_8)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  long lVar4;
  byte bVar5;
  short *psVar6;
  undefined1 *puVar7;
  
  lVar4 = FUN_001c0ca0();
  psVar6 = (short *)param_4;
  puVar7 = (undefined1 *)param_3;
  if (lVar4 < 0) {
    *param_8 = 0xaf;
    *param_1 = 2;
    uVar3 = 0;
    *param_2 = '\0';
    *puVar7 = 0;
    *psVar6 = 0;
    *param_5 = 0;
    *param_6 = 0;
    *param_7 = 0;
  }
  else {
    bVar5 = bRam0035b74c;
    if (bRam0035b74d < bRam0035b74c) {
      bVar5 = bRam0035b74d + 1;
    }
    cVar1 = *param_2;
    bRam0035b74d = bVar5;
    if (cVar1 == 'd') {
      lVar4 = FUN_001c2770(param_3,param_4);
      if (lVar4 == 0) {
        uVar3 = 0;
      }
      else {
        bRam0035b74c = 0;
        bRam0035b74e = 10;
        *param_2 = '\x01';
        *puVar7 = 0;
        uVar3 = 5;
        *psVar6 = 0x5a;
        *param_5 = 0;
      }
    }
    else if (cVar1 == 'c') {
      uVar3 = 0;
      *param_2 = 'd';
      *puVar7 = 0;
      *psVar6 = 0;
    }
    else if (cVar1 == '\x1f') {
      uVar3 = 0;
      if (bVar5 == 100) {
        *param_1 = 0;
        uVar3 = 2;
        *param_2 = '\0';
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
    }
    else if (cVar1 == '\x1e') {
      FUN_001eee90(0);
      iRam0035a6c8 = 0;
      lVar4 = FUN_001eef00(0x35a6c8);
      if ((lVar4 < 0) || (iRam0035a6c8 == 0)) {
        *param_8 = 0xad;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
      else {
        bRam0035b74e = 100;
        uVar3 = 0;
        bRam0035b74c = 100;
        *param_2 = *param_2 + '\x01';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
    }
    else if (cVar1 == '\x18') {
      bVar5 = bRam0035b74c;
      if (((int)*psVar6 % 0x1e == 0) && (bVar5 = bRam0035b74e, bRam0035b74c < bRam0035b74e)) {
        bVar5 = bRam0035b74c + 1;
      }
      bRam0035b74c = bVar5;
      sVar2 = *psVar6;
      *psVar6 = sVar2 + -1;
      uVar3 = 0;
      if ((short)(sVar2 + -1) < 1) {
        *psVar6 = 0;
        bRam0035b74e = 100;
        if (bRam0035b74c < 0x46) {
          bRam0035b74c = 0x46;
        }
        FUN_001c0b20();
        lVar4 = FUN_001ef160(0x35a6c0);
        if (lVar4 < 0) {
          *param_8 = 0xae;
          *param_1 = 2;
          uVar3 = 0;
          *param_2 = '\0';
          *puVar7 = 0;
          *psVar6 = 0;
          *param_5 = 0;
          *param_6 = 0;
          *param_7 = 0;
        }
        else {
          uRam0035ba88 = uRam0035a6c0;
          lVar4 = FUN_001eefb0(0,uRam0035a6c0);
          if (lVar4 < 0) {
            *param_8 = 0xae;
            *param_1 = 2;
            uVar3 = 0;
            *param_2 = '\0';
            *puVar7 = 0;
            *psVar6 = 0;
            *param_5 = 0;
            *param_6 = 0;
            *param_7 = 0;
          }
          else {
            uVar3 = 0;
            *param_2 = '\x1e';
          }
        }
      }
    }
    else if (cVar1 == '\x17') {
      if (*param_5 < 0x1f) {
        bVar5 = bRam0035b74c;
        if (((int)*psVar6 % 0x1e == 0) && (bVar5 = bRam0035b74e, bRam0035b74c < bRam0035b74e)) {
          bVar5 = bRam0035b74c + 1;
        }
        bRam0035b74c = bVar5;
        *psVar6 = *psVar6 + 1;
        lVar4 = FUN_001ef0d0();
        if (lVar4 < 0) {
          if (*param_6 < 3) {
            FUN_001ef070();
            *param_2 = 'c';
            *param_6 = *param_6 + 1;
          }
          else {
            FUN_001ef070();
            *param_8 = 0xac;
            *param_1 = 2;
            *param_2 = '\0';
            *puVar7 = 0;
            *psVar6 = 0;
            *param_5 = 0;
            *param_6 = 0;
            *param_7 = 0;
          }
          uVar3 = 0;
        }
        else {
          if (lVar4 == 3) {
            bRam0035b74e = 0x46;
            if (bRam0035b74c < 0x3c) {
              bRam0035b74c = 0x3c;
            }
            FUN_001ef100(0x35a6c0);
            uRam0035ba98 = uRam0035a6c0;
            uRam0035ba90 = uRam0035a6c4;
            FUN_001eedf0(0x35a6c0);
            *param_2 = *param_2 + '\x01';
            *psVar6 = 0x5a;
          }
          uVar3 = 0;
        }
      }
      else {
        FUN_001ef070();
        *param_8 = 0xaa;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
    }
    else if (cVar1 == '\x16') {
      lVar4 = FUN_001ef040();
      if (lVar4 < 0) {
        *param_8 = 0xae;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
      else {
        lVar4 = FUN_001ef0a0(0,5);
        if (lVar4 < 0) {
          *param_8 = 0xae;
          *param_1 = 2;
          uVar3 = 0;
          *param_2 = '\0';
          *puVar7 = 0;
          *psVar6 = 0;
          *param_5 = 0;
          *param_6 = 0;
          *param_7 = 0;
        }
        else {
          uVar3 = 0;
          *param_2 = *param_2 + '\x01';
          *psVar6 = 0;
        }
      }
    }
    else if (cVar1 == '\x15') {
      if (*param_5 < 0x1f) {
        bVar5 = bRam0035b74c;
        if (((int)*psVar6 % 0x1e == 0) && (bVar5 = bRam0035b74e, bRam0035b74c < bRam0035b74e)) {
          bVar5 = bRam0035b74c + 1;
        }
        bRam0035b74c = bVar5;
        *psVar6 = *psVar6 + 1;
        lVar4 = FUN_001eee60();
        if (lVar4 == 0) {
          if (0x1c2 < *psVar6) {
            if (*param_6 < 3) {
              *param_2 = 'c';
              *param_6 = *param_6 + 1;
            }
            else {
              *param_8 = 0xae;
              *param_1 = 2;
              *param_2 = '\0';
              *puVar7 = 0;
              *psVar6 = 0;
              *param_5 = 0;
              *param_6 = 0;
              *param_7 = 0;
            }
          }
          uVar3 = 0;
        }
        else {
          bRam0035b74e = 0x3c;
          if (bRam0035b74c < 0x14) {
            bRam0035b74c = 0x14;
          }
          uVar3 = 0;
          *param_2 = *param_2 + '\x01';
          *psVar6 = 0;
        }
      }
      else {
        *param_8 = 0xaa;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
    }
    else if (cVar1 == '\x14') {
      bRam0035b74e = 0x14;
      if (bRam0035b74c < 0xb) {
        bRam0035b74c = 0xb;
      }
      lVar4 = FUN_001eee30(uRam0035baa8);
      if (lVar4 < 0) {
        *param_8 = 0xae;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
      else {
        uVar3 = 0;
        *param_2 = *param_2 + '\x01';
        *psVar6 = 0;
      }
    }
    else if (cVar1 == '\r') {
      if (*param_5 < 0x1f) {
        bVar5 = bRam0035b74c;
        if (((int)*psVar6 % 0x1e == 0) && (bVar5 = bRam0035b74e, bRam0035b74c < bRam0035b74e)) {
          bVar5 = bRam0035b74c + 1;
        }
        bRam0035b74c = bVar5;
        sVar2 = *psVar6;
        *psVar6 = sVar2 + -1;
        if (sVar2 < 1) {
          *psVar6 = 0;
          bRam0035b74e = 100;
          if (bRam0035b74c < 0x46) {
            bRam0035b74c = 0x46;
          }
          FUN_001c0b20();
          lVar4 = FUN_001eefb0(0,uRam0035ba88);
          if (lVar4 < 0) {
            *param_8 = 0xae;
            *param_1 = 2;
            uVar3 = 0;
            *param_2 = '\0';
            *puVar7 = 0;
            *psVar6 = 0;
            *param_5 = 0;
            *param_6 = 0;
            *param_7 = 0;
          }
          else {
            uVar3 = 0;
            *param_2 = '\x1e';
          }
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        *param_8 = 0xaa;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
    }
    else if (cVar1 == '\f') {
      if (*param_5 < 0x1f) {
        bVar5 = bRam0035b74c;
        if (((int)*psVar6 % 0x1e == 0) && (bVar5 = bRam0035b74e, bRam0035b74c < bRam0035b74e)) {
          bVar5 = bRam0035b74c + 1;
        }
        bRam0035b74c = bVar5;
        *psVar6 = *psVar6 + 1;
        lVar4 = FUN_001eee60();
        if (lVar4 == 0) {
          if (0x1c2 < *psVar6) {
            if (*param_6 < 3) {
              *param_2 = 'c';
              *param_6 = *param_6 + 1;
            }
            else {
              *param_8 = 0xae;
              *param_1 = 2;
              *param_2 = '\0';
              *puVar7 = 0;
              *psVar6 = 0;
              *param_5 = 0;
              *param_6 = 0;
              *param_7 = 0;
            }
          }
          uVar3 = 0;
        }
        else {
          bRam0035b74e = 0x46;
          if (bRam0035b74c < 0x14) {
            bRam0035b74c = 0x14;
          }
          uVar3 = 0;
          *param_2 = *param_2 + '\x01';
          *psVar6 = 0x96;
          *param_6 = 0;
        }
      }
      else {
        *param_8 = 0xaa;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
    }
    else if (cVar1 == '\v') {
      lVar4 = FUN_001eee30(uRam0035baa8);
      if (lVar4 < 0) {
        *param_8 = 0xae;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
      else {
        uVar3 = 0;
        *param_2 = *param_2 + '\x01';
        *psVar6 = 0;
      }
    }
    else if (cVar1 == '\n') {
      bRam0035b74e = 0x14;
      if (bRam0035b74c < 10) {
        bRam0035b74c = 10;
      }
      uRam0035a6c0 = uRam0035ba98;
      uRam0035a6c4 = uRam0035ba90;
      lVar4 = FUN_001eedf0(0x35a6c0);
      if (lVar4 < 0) {
        *param_8 = 0xae;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
      else {
        uVar3 = 0;
        *param_2 = *param_2 + '\x01';
      }
    }
    else if (cVar1 == '\x03') {
      bRam0035b74c = 6;
      lVar4 = FUN_001eedc0();
      if (lVar4 < 0) {
        *param_8 = 0xae;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
      else {
        if (cRam0035bec8 == '\0') {
          *param_2 = '\n';
        }
        else if (cRam0035bec8 == '\x01') {
          *param_2 = '\x14';
        }
        uVar3 = 0;
      }
    }
    else if (cVar1 == '\x02') {
      bRam0035b74c = 2;
      lVar4 = FUN_001ee3b0(*puRam0035c3d8,puRam0035c3d8[1]);
      if (lVar4 < 0) {
        *param_8 = 0xae;
        *param_1 = 2;
        uVar3 = 0;
        *param_2 = '\0';
        *puVar7 = 0;
        *psVar6 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
      else {
        uVar3 = 0;
        *param_2 = *param_2 + '\x01';
      }
    }
    else if (cVar1 == '\x01') {
      sVar2 = *psVar6;
      *psVar6 = sVar2 + -1;
      if (sVar2 < 1) {
        *psVar6 = 0;
        bRam0035b74e = 10;
        uVar3 = 0;
        bRam0035b74c = 0;
        *param_2 = *param_2 + '\x01';
      }
      else {
        uVar3 = 0;
      }
    }
    else if (cVar1 == '\0') {
      uVar3 = 0;
      *param_2 = '\x01';
      *puVar7 = 0;
      *psVar6 = 0;
      *param_5 = 0;
      *param_6 = 0;
      *param_7 = 0;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

