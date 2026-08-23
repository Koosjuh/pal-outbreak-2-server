
undefined8
FUN_001c0f40(undefined1 *param_1,char *param_2,undefined8 param_3,undefined8 param_4,short *param_5,
            short *param_6,short *param_7,undefined1 *param_8)

{
  char cVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  byte bVar6;
  short *psVar7;
  undefined1 *puVar8;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  lVar4 = FUN_001c0ca0();
  puVar8 = (undefined1 *)param_3;
  psVar7 = (short *)param_4;
  if (lVar4 < 0) {
    *param_8 = 0xaf;
    *param_1 = 2;
    uVar5 = 0;
    *param_2 = '\0';
    *puVar8 = 0;
    *psVar7 = 0;
    *param_5 = 0;
    *param_6 = 0;
    *param_7 = 0;
  }
  else {
    bVar6 = bRam0035b74c;
    if (bRam0035b74d < bRam0035b74c) {
      bVar6 = bRam0035b74d + 1;
    }
    cVar1 = *param_2;
    bRam0035b74d = bVar6;
    if (cVar1 == 'd') {
      lVar4 = FUN_001c2770(param_3,param_4);
      if (lVar4 == 0) {
        uVar5 = 0;
      }
      else {
        bRam0035b74c = 0;
        bRam0035b74e = 10;
        *param_2 = '\x01';
        *puVar8 = 0;
        uVar5 = 5;
        *psVar7 = 0x5a;
        *param_5 = 0;
      }
    }
    else if (cVar1 == 'c') {
      uVar5 = 0;
      *param_2 = 'd';
      *puVar8 = 0;
      *psVar7 = 0;
    }
    else if (cVar1 == '\a') {
      uVar5 = 0;
      if (bVar6 == 100) {
        *param_1 = 0;
        uVar5 = 2;
        *param_2 = '\0';
        *psVar7 = 0;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
      }
    }
    else if (cVar1 == '\x06') {
      bRam0035b74e = 100;
      bRam0035b74c = 100;
      *param_2 = *param_2 + '\x01';
      FUN_001c0dc0();
      FUN_001c0b20();
      FUN_001eeb00(0);
      uVar5 = 0;
      uRam0035ba98 = uRam0035a6d0;
    }
    else {
      uVar5 = 4;
      if (cVar1 == '\x05') {
        if (*param_5 < 0x1f) {
          bVar6 = bRam0035b74c;
          if (((int)*psVar7 % 0x1e == 0) && (bVar6 = bRam0035b74e, bRam0035b74c < bRam0035b74e)) {
            bVar6 = bRam0035b74c + 1;
          }
          bRam0035b74c = bVar6;
          sVar2 = *psVar7;
          *psVar7 = sVar2 + -1;
          if (sVar2 < 1) {
            *psVar7 = 0;
            lVar4 = FUN_001eeb50(0x35a6d0);
            if (lVar4 < 0) {
              *param_8 = 0xae;
              *param_1 = 2;
              uVar5 = 0;
              *param_2 = '\0';
              *puVar8 = 0;
              *psVar7 = 0;
              *param_5 = 0;
              *param_6 = 0;
              *param_7 = 0;
            }
            else {
              switch(uRam0035a6dc) {
              case 0:
              case 5:
              case 6:
              case 7:
              case 8:
              case 9:
                if (sRam0035a6e0 == 0xd) {
                  *param_8 = 0xfe;
                  *param_1 = 2;
                  *param_2 = '\0';
                  *puVar8 = 0;
                  *psVar7 = 0;
                  *param_5 = 0;
                  *param_6 = 0;
                  *param_7 = 0;
                }
                else if (sRam0035a6e0 == 6) {
                  *param_8 = 0xab;
                  *param_1 = 2;
                  *param_2 = '\0';
                  *puVar8 = 0;
                  *psVar7 = 0;
                  *param_5 = 0;
                  *param_6 = 0;
                  *param_7 = 0;
                }
                else if (sRam0035a6e0 == 3) {
                  *param_8 = 0xfb;
                  *param_1 = 2;
                  *param_2 = '\0';
                  *puVar8 = 0;
                  *psVar7 = 0;
                  *param_5 = 0;
                  *param_6 = 0;
                  *param_7 = 0;
                }
                else if (sRam0035a6e0 == 5) {
                  lVar4 = FUN_001c0de0();
                  if (lVar4 == 0) {
                    *param_2 = 'c';
                  }
                  else {
                    *param_8 = 0xae;
                    *param_1 = 2;
                    *param_2 = '\0';
                    *puVar8 = 0;
                    *psVar7 = 0;
                    *param_5 = 0;
                    *param_6 = 0;
                    *param_7 = 0;
                  }
                }
                else if (sRam0035a6e0 == 1) {
                  sVar2 = *param_6;
                  *param_6 = sVar2 + -1;
                  if ((short)(sVar2 + -1) == 0) {
                    *param_8 = 0xae;
                    *param_1 = 2;
                    *param_2 = '\0';
                    *puVar8 = 0;
                    *psVar7 = 0;
                    *param_5 = 0;
                    *param_6 = 0;
                    *param_7 = 0;
                  }
                  else {
                    *param_2 = 'c';
                  }
                }
                else if (sRam0035a6e0 == 0xc) {
                  sVar2 = *param_7;
                  *param_7 = sVar2 + -1;
                  if ((short)(sVar2 + -1) == 0) {
                    *param_8 = 0xfe;
                    *param_1 = 2;
                    *param_2 = '\0';
                    *puVar8 = 0;
                    *psVar7 = 0;
                    *param_5 = 0;
                    *param_6 = 0;
                    *param_7 = 0;
                  }
                  else {
                    *param_2 = 'c';
                  }
                }
                else if (sRam0035a6e0 == 2) {
                  lVar4 = FUN_001c0d60();
                  if (lVar4 == 0) {
                    *param_2 = 'c';
                  }
                  else {
                    *param_8 = 0xfd;
                    *param_1 = 2;
                    *param_2 = '\0';
                    *puVar8 = 0;
                    *psVar7 = 0;
                    *param_5 = 0;
                    *param_6 = 0;
                    *param_7 = 0;
                  }
                }
                else {
                  *param_8 = 0xae;
                  *param_1 = 2;
                  *param_2 = '\0';
                  *puVar8 = 0;
                  *psVar7 = 0;
                  *param_5 = 0;
                  *param_6 = 0;
                  *param_7 = 0;
                }
                return 0;
              case 1:
                bRam0035b74e = 0xc;
                if (bRam0035b74c < 0xb) {
                  bRam0035b74c = 0xb;
                }
                break;
              case 2:
                bRam0035b74e = 0x3c;
                if (bRam0035b74c < 0xc) {
                  bRam0035b74c = 0xc;
                }
                break;
              case 3:
                bRam0035b74e = 0x46;
                if (bRam0035b74c < 0x3c) {
                  bRam0035b74c = 0x3c;
                }
                break;
              case 4:
                bRam0035b74e = 0x50;
                if (bRam0035b74c < 0x46) {
                  bRam0035b74c = 0x46;
                }
                *param_2 = *param_2 + '\x01';
                break;
              default:
                *param_8 = 0xae;
                *param_1 = 2;
                *param_2 = '\0';
                *puVar8 = 0;
                *psVar7 = 0;
                *param_5 = 0;
                *param_6 = 0;
                *param_7 = 0;
              }
              uVar5 = 0;
              *psVar7 = 0x1d;
            }
          }
          else {
            uVar5 = 0;
          }
        }
        else {
          *param_8 = 0xaa;
          *param_1 = 2;
          uVar5 = 0;
          *param_2 = '\0';
          *puVar8 = 0;
          *psVar7 = 0;
          *param_5 = 0;
          *param_6 = 0;
          *param_7 = 0;
        }
      }
      else if (cVar1 == '\x04') {
        if (*param_5 < 0x1f) {
          *param_2 = '\x05';
          uVar5 = 0;
          *psVar7 = 0x1d;
        }
        else {
          *param_8 = 0xaa;
          *param_1 = 2;
          uVar5 = 0;
          *param_2 = '\0';
          *puVar8 = 0;
          *psVar7 = 0;
          *param_5 = 0;
          *param_6 = 0;
          *param_7 = 0;
        }
      }
      else if (cVar1 == '\x03') {
        bRam0035b74c = 6;
        if ((*piRam0035c3d8 == 2) || (*piRam0035c3d8 == 3)) {
          iVar3 = FUN_001ee9d0();
          piRam0035c3d8[4] = iVar3;
          if (piRam0035c3d8[4] < 0) {
            *param_8 = 0xaf;
            *param_1 = 2;
            *param_2 = '\0';
            *puVar8 = 0;
            *psVar7 = 0;
            *param_5 = 0;
            *param_6 = 0;
            *param_7 = 0;
            return 0;
          }
        }
        lVar4 = FUN_001eea10(0x35cc50);
        if (lVar4 < 0) {
          *param_8 = 0xae;
          *param_1 = 2;
          uVar5 = 0;
          *param_2 = '\0';
          *puVar8 = 0;
          *psVar7 = 0;
          *param_5 = 0;
          *param_6 = 0;
          *param_7 = 0;
        }
        else {
          FUN_00106b60(0x35a6d0,0,0x14);
          uVar5 = 0;
          *param_2 = *param_2 + '\x02';
          *psVar7 = 0x3b;
        }
      }
      else if (cVar1 == '\x02') {
        bRam0035b74c = 4;
        lVar4 = FUN_001ee8d0();
        if (lVar4 < 0) {
          *param_8 = 0xae;
          *param_1 = 2;
          uVar5 = 0;
          *param_2 = '\0';
          *puVar8 = 0;
          *psVar7 = 0;
          *param_5 = 0;
          *param_6 = 0;
          *param_7 = 0;
        }
        else {
          uStack_4 = 10;
          FUN_001ee900(&uStack_4);
          uVar5 = 0;
          *param_2 = *param_2 + '\x01';
          *psVar7 = 0;
        }
      }
      else if (cVar1 == '\x01') {
        sVar2 = *psVar7;
        *psVar7 = sVar2 + -1;
        if (sVar2 < 1) {
          *psVar7 = 0;
          bRam0035b74c = 2;
          lVar4 = FUN_001ee3b0(*piRam0035c3d8,piRam0035c3d8[1]);
          if (lVar4 < 0) {
            *param_8 = 0xae;
            *param_1 = 2;
            uVar5 = 0;
            *param_2 = '\0';
            *puVar8 = 0;
            *psVar7 = 0;
            *param_5 = 0;
            *param_6 = 0;
            *param_7 = 0;
          }
          else {
            uVar5 = 0;
            *param_2 = *param_2 + '\x01';
          }
        }
        else {
          uVar5 = 0;
        }
      }
      else if (cVar1 == '\n') {
        FUN_001ee9b0(*piRam0035c3d8,piRam0035c3d8[1],0,2,&uStack_10);
        *param_2 = '\x01';
        uRam0035cc50 = 0x35cc30;
        uRam0035cc30 = 0x35cc20;
        uRam0035cc34 = 0x35cc18;
        uRam0035cc38 = 0x35cc60;
        uRam0035cc44 = 0x35bdd0;
        uRam0035cc48 = 0x35bbb0;
        uRam0035cc4c = 0x35bab0;
        uRam0035cc3c = uStack_10;
        uRam0035cc20 = 4;
        uRam0035cc40 = uStack_c;
        uRam0035cc54 = 0;
        uRam0035cc22 = 0;
        uRam0035cc24 = 0;
        uRam0035cc26 = 1;
        uRam0035cc28 = 1;
        uRam0035cc57 = uRam0035baa8;
        uRam0035cc56 = cRam0035bec8 == '\x02';
        uRam0035cc18 = (ushort)bRam0035bec0;
        if (cRam0035bdc0 != '\0') {
          puRam0035cc1c = (undefined *)0x35bdc0;
        }
        else {
          puRam0035cc1c = &DAT_00248498;
        }
        uRam0035cc1a = (ushort)(cRam0035bdc0 != '\0');
        FUN_00106b60(0x35cc60,0,0x10);
        uVar5 = 0;
        uRam0035cc60 = (ushort)bRam0035baa0;
      }
      else if (cVar1 == '\0') {
        if (piRam0035c3d8 == (int *)0x0) {
          *param_8 = 0xaf;
        }
        else {
          bRam0035b74e = 10;
          bRam0035b74c = 0;
          bRam0035b74d = 0;
          *puVar8 = 0;
          *psVar7 = 0;
          *param_5 = 0;
          *param_6 = 3;
          *param_7 = 2;
          if (*piRam0035c3d8 == 1) {
            if ((cRam0035bec8 == '\0') || (cRam0035bec8 == '\x01')) {
              *param_1 = 1;
            }
            else if (cRam0035bec8 == '\x02') {
              *param_2 = '\n';
            }
          }
          else {
            *param_2 = '\n';
          }
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}

