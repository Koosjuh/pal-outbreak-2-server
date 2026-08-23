FUNCTION FUN_005b9150 @ 0x005b9150  size=4148
CALLERS (0): 
CALLEES (9): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_00618c20@0x00618c20, FUN_0062fd30@0x0062fd30, FUN_005b9120@0x005b9120, FUN_005bb380@0x005bb380, FUN_005bacf0@0x005bacf0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005b9150(int param_1)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  char *pcVar10;
  short sVar11;
  int iVar12;
  undefined1 auStack_f0 [80];
  undefined1 auStack_a0 [80];
  undefined1 auStack_50 [80];
  
  cVar2 = *(char *)(param_1 + 4);
  if (cVar2 == '\x02') {
    FUN_00618c20();
  }
  else if (cVar2 == '\x01') {
    lVar7 = FUN_005b9120();
    if (lVar7 == 0) {
      cVar2 = *(char *)(param_1 + 2);
      if (((((((cVar2 == '-') || (cVar2 == 'r')) || (cVar2 == ',')) ||
            (((cVar2 == 'k' || (cVar2 == 'j')) ||
             ((cVar2 == 'p' || ((cVar2 == 'n' || (cVar2 == 'o')))))))) || (cVar2 == 'l')) ||
          (((((cVar2 == 'i' || (cVar2 == 'X')) || (cVar2 == 'h')) ||
            ((cVar2 == 'g' || (cVar2 == 'f')))) || (cVar2 == '#')))) ||
         (((cVar2 == '\x1d' || (cVar2 == '2')) || (cVar2 == '1')))) {
        FUN_005bb380(cVar2);
      }
      else {
        pcVar4 = (char *)FUN_0062fd30();
        if ((*(char *)(param_1 + 2) != '\x18') && (*(char *)(param_1 + 2) != 'Q')) {
          while( true ) {
            FUN_005af2c0(pcVar4[2]);
            FUN_005af2e0(pcVar4[1]);
            FUN_005af1e0(*(undefined2 *)(pcVar4 + 4),*(undefined2 *)(pcVar4 + 6),pcVar4[3],
                         *(undefined4 *)(pcVar4 + 8));
            if (*pcVar4 != '\0') break;
            pcVar4 = pcVar4 + 0xc;
          }
        }
        cVar2 = *(char *)(param_1 + 2);
        if ((((cVar2 == -0x56) || (cVar2 == -0x57)) || (cVar2 == -0x58)) ||
           ((cVar2 == -0x59 || (cVar2 == -0x5a)))) {
          FUN_005af2e0(pcVar4[0xd]);
          if (cRam006c5b40 == '\0') {
            uVar8 = FUN_0062fea0(0x22);
            func_0x00109728(auStack_50,0x639d60,uVar8,0x6c5b30);
          }
          else {
            uVar8 = FUN_0062fea0(0x22);
            uVar9 = FUN_0062fea0(0x23);
            func_0x00109728(auStack_50,0x639d70,uVar8,0x6c5b30,uVar9,0x6c5b40);
          }
          iVar6 = func_0x001ae3e0(auStack_50);
          iVar5 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar5 = iVar5 + 1;
          }
          iVar5 = iVar5 >> 1;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 1;
          }
          iVar6 = (iVar5 >> 1) * iVar6;
          if (iVar6 < 0) {
            iVar6 = iVar6 + 1;
          }
          sVar11 = 0x140 - (short)(iVar6 >> 1);
          FUN_005af2c0(0x12);
          uVar8 = FUN_0062fea0(0x22);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x12),2,uVar8);
          uVar8 = FUN_0062fea0(0x22);
          sVar3 = func_0x001ae3e0(uVar8);
          iVar6 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar6 = iVar6 + 1;
          }
          sVar11 = sVar11 + (short)(iVar6 >> 1) * sVar3;
          FUN_005af2c0(0x10);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x12),2,0x6c5b30);
          iVar6 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar6 = iVar6 + 1;
          }
          sVar3 = func_0x001ae3e0(0x6c5b30);
          sVar11 = sVar11 + (short)(iVar6 >> 1) * sVar3 + 0x12;
          if (cRam006c5b40 != '\0') {
            FUN_005af2c0(0x12);
            uVar8 = FUN_0062fea0(0x23);
            FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x12),2,uVar8);
            uVar8 = FUN_0062fea0(0x23);
            sVar3 = func_0x001ae3e0(uVar8);
            iVar6 = (int)pcVar4[0xd];
            if (pcVar4[0xd] < '\0') {
              iVar6 = iVar6 + 1;
            }
            FUN_005af2c0(0x11);
            FUN_005af1e0(sVar11 + (short)(iVar6 >> 1) * sVar3,*(undefined2 *)(pcVar4 + 0x12),2,
                         0x6c5b40);
          }
        }
        else if (cVar2 == -0x5b) {
          FUN_005af2e0(pcVar4[0xd]);
          if (cRam006c5b40 == '\0') {
            uVar8 = FUN_0062fea0(0x22);
            func_0x00109728(auStack_50,0x639d60,uVar8,0x6c5b30);
          }
          else {
            uVar8 = FUN_0062fea0(0x22);
            uVar9 = FUN_0062fea0(0x23);
            func_0x00109728(auStack_50,0x639d70,uVar8,0x6c5b30,uVar9,0x6c5b40);
          }
          iVar6 = func_0x001ae3e0(auStack_50);
          iVar5 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar5 = iVar5 + 1;
          }
          iVar5 = iVar5 >> 1;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 1;
          }
          iVar6 = (iVar5 >> 1) * iVar6;
          if (iVar6 < 0) {
            iVar6 = iVar6 + 1;
          }
          sVar11 = 0x140 - (short)(iVar6 >> 1);
          FUN_005af2c0(0x12);
          uVar8 = FUN_0062fea0(0x22);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x12),2,uVar8);
          uVar8 = FUN_0062fea0(0x22);
          sVar3 = func_0x001ae3e0(uVar8);
          iVar6 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar6 = iVar6 + 1;
          }
          sVar11 = sVar11 + (short)(iVar6 >> 1) * sVar3;
          FUN_005af2c0(0x10);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x12),2,0x6c5b30);
          iVar6 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar6 = iVar6 + 1;
          }
          sVar3 = func_0x001ae3e0(0x6c5b30);
          sVar11 = sVar11 + (short)(iVar6 >> 1) * sVar3 + 0x12;
          FUN_005af2c0(0x12);
          uVar8 = FUN_0062fea0(0x23);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x12),2,uVar8);
          uVar8 = FUN_0062fea0(0x23);
          sVar3 = func_0x001ae3e0(uVar8);
          iVar6 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar6 = iVar6 + 1;
          }
          FUN_005af2c0(0x11);
          FUN_005af1e0(sVar11 + (short)(iVar6 >> 1) * sVar3,*(undefined2 *)(pcVar4 + 0x12),2,
                       0x6c5b40);
          func_0x001ae3e0(0x6c5b40);
          FUN_005af2c0(0);
          uVar8 = FUN_005bacf0(uRam006c5048);
          func_0x00109728(auStack_50,0x639d60,uVar8,*(undefined4 *)(pcVar4 + 0x20));
          iVar6 = func_0x001ae3e0(auStack_50);
          iVar5 = (int)pcVar4[0x19];
          if (pcVar4[0x19] < '\0') {
            iVar5 = iVar5 + 1;
          }
          iVar5 = iVar5 >> 1;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 1;
          }
          iVar5 = (iVar5 >> 1) * iVar6;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 1;
          }
          sVar11 = 0x140 - (short)(iVar5 >> 1);
          FUN_005af2c0(4);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x1e),2,uVar8);
          FUN_005af2c0(0);
          sVar3 = func_0x001ae3e0(uVar8);
          iVar5 = (int)pcVar4[0x19];
          if (pcVar4[0x19] < '\0') {
            iVar5 = iVar5 + 1;
          }
          FUN_005af1e0(sVar11 + (short)(iVar5 >> 1) * sVar3,*(undefined2 *)(pcVar4 + 0x1e),2,
                       *(undefined4 *)(pcVar4 + 0x20));
          func_0x00109728(auStack_50,0x639d60,uVar8,*(undefined4 *)(pcVar4 + 0x2c));
          iVar5 = (int)pcVar4[0x25];
          if (pcVar4[0x25] < '\0') {
            iVar5 = iVar5 + 1;
          }
          iVar5 = iVar5 >> 1;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 1;
          }
          iVar6 = (iVar5 >> 1) * iVar6;
          if (iVar6 < 0) {
            iVar6 = iVar6 + 1;
          }
          sVar11 = 0x140 - (short)(iVar6 >> 1);
          FUN_005af2c0(4);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x2a),2,uVar8);
          FUN_005af2c0(0);
          sVar3 = func_0x001ae3e0(uVar8);
          iVar6 = (int)pcVar4[0x25];
          if (pcVar4[0x25] < '\0') {
            iVar6 = iVar6 + 1;
          }
          FUN_005af1e0(sVar11 + (short)(iVar6 >> 1) * sVar3,*(undefined2 *)(pcVar4 + 0x2a),2,
                       *(undefined4 *)(pcVar4 + 0x2c));
        }
        else if (cVar2 == -0x60) {
          uVar8 = FUN_005bacf0(uRam006c5048);
          func_0x00109728(auStack_50,0x639d68,uVar8,*(undefined4 *)(pcVar4 + 0x14));
          FUN_005af2e0(pcVar4[0xd]);
          iVar6 = func_0x001ae3e0(auStack_50);
          iVar5 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar5 = iVar5 + 1;
          }
          iVar5 = iVar5 >> 1;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 1;
          }
          iVar6 = (iVar5 >> 1) * iVar6;
          if (iVar6 < 0) {
            iVar6 = iVar6 + 1;
          }
          sVar11 = 0x140 - (short)(iVar6 >> 1);
          FUN_005af2c0(4);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x12),2,uVar8);
          sVar3 = func_0x001ae3e0(uVar8);
          iVar6 = (int)pcVar4[0xd];
          if (pcVar4[0xd] < '\0') {
            iVar6 = iVar6 + 1;
          }
          FUN_005af2c0(pcVar4[0xe]);
          FUN_005af1e0(sVar11 + (short)(iVar6 >> 1) * sVar3,*(undefined2 *)(pcVar4 + 0x12),2,
                       *(undefined4 *)(pcVar4 + 0x14));
          func_0x00109728(auStack_50,0x639d68,uVar8,*(undefined4 *)(pcVar4 + 0x20));
          iVar6 = func_0x001ae3e0(auStack_50);
          iVar5 = (int)pcVar4[0x19];
          if (pcVar4[0x19] < '\0') {
            iVar5 = iVar5 + 1;
          }
          iVar5 = iVar5 >> 1;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 1;
          }
          iVar6 = (iVar5 >> 1) * iVar6;
          if (iVar6 < 0) {
            iVar6 = iVar6 + 1;
          }
          sVar11 = 0x140 - (short)(iVar6 >> 1);
          FUN_005af2c0(4);
          FUN_005af1e0(sVar11,*(undefined2 *)(pcVar4 + 0x1e),2,uVar8);
          sVar3 = func_0x001ae3e0(uVar8);
          iVar6 = (int)pcVar4[0x19];
          if (pcVar4[0x19] < '\0') {
            iVar6 = iVar6 + 1;
          }
          FUN_005af2c0(pcVar4[0x1a]);
          FUN_005af1e0(sVar11 + (short)(iVar6 >> 1) * sVar3,*(undefined2 *)(pcVar4 + 0x1e),2,
                       *(undefined4 *)(pcVar4 + 0x20));
        }
        else if (((cVar2 != '\x1f') && (cVar2 != '{')) && ((cVar2 != 'x' && (cVar2 != 'w')))) {
          if (cVar2 == '\x18') {
            bVar1 = uRam006c5508 == 0;
            uRam006c5508 = uRam006c5508 - 1;
            if (bVar1) {
              uRam006c5508 = 0xff;
            }
            if ((uRam006c5508 & 0x80) == 0) {
              while( true ) {
                FUN_005af2c0(pcVar4[2]);
                FUN_005af1e0(*(undefined2 *)(pcVar4 + 4),*(undefined2 *)(pcVar4 + 6),2,
                             *(undefined4 *)(pcVar4 + 8));
                if (*pcVar4 != '\0') break;
                pcVar4 = pcVar4 + 0xc;
              }
            }
            else {
              do {
                pcVar10 = pcVar4 + 0xc;
                FUN_005af2c0(pcVar4[0xe]);
                FUN_005af1e0(*(undefined2 *)(pcVar4 + 0x10),*(undefined2 *)(pcVar4 + 0x12),2,
                             *(undefined4 *)(pcVar4 + 0x14));
                pcVar4 = pcVar10;
              } while (*pcVar10 == '\0');
            }
          }
          else {
            if (cVar2 != 'Q') {
              if (cVar2 != -0x62) {
                if ((cVar2 == 'a') || (cVar2 == '^')) {
                  FUN_005af2c0(0x12);
                  FUN_005af1e0(*(undefined2 *)(pcVar4 + 0x10),*(undefined2 *)(pcVar4 + 0x12),
                               pcVar4[0xf],0x6c5a8b);
                  FUN_005af2c0(0x11);
                  cVar2 = func_0x001ae3e0(0x6c5a9b);
                  FUN_005af1e0(*(undefined2 *)(pcVar4 + 0x1c),*(undefined2 *)(pcVar4 + 0x1e),
                               pcVar4[0x1b],0x6c5a9b);
                  FUN_005af2c0(0);
                  uVar8 = FUN_0062fea0(0x1a);
                  iVar6 = (int)cVar2;
                  if (cVar2 < '\0') {
                    iVar6 = iVar6 + 1;
                  }
                  FUN_005af1e0((int)*(short *)(pcVar4 + 0x1c) + (iVar6 >> 1) * 0x14 + 0x14,
                               *(undefined2 *)(pcVar4 + 0x1e),pcVar4[0x1b],uVar8);
                  return;
                }
                if ((cVar2 != '`') && (cVar2 != ']')) {
                  if ((((cVar2 != -0x50) && (cVar2 != -0x7d)) && (cVar2 != '\x05')) &&
                     (cVar2 != '\x15')) {
                    if ((cVar2 != '\x16') && (cVar2 != ' ')) {
                      if (cVar2 != '<') {
                        return;
                      }
                      iVar6 = *(int *)(param_1 + 0x10);
                      func_0x00106b60(auStack_50,0,0x50);
                      func_0x001069a8(auStack_50,iVar6 + 0x10,0x10);
                      func_0x00109728(auStack_a0,0x639d60,*(undefined4 *)(pcVar4 + 0x14),auStack_50)
                      ;
                      cVar2 = func_0x001ae3e0(auStack_a0);
                      FUN_005af2c0(0);
                      iVar5 = cVar2 * 10;
                      iVar6 = (int)((ulong)((long)(cVar2 * 5) << 0x21) >> 0x20);
                      if (iVar5 < 0) {
                        iVar6 = iVar5 + 1;
                      }
                      iVar12 = 0x140 - (iVar6 >> 1);
                      FUN_005af1e0(iVar12,*(undefined2 *)(pcVar4 + 0x12),pcVar4[0xf],
                                   *(undefined4 *)(pcVar4 + 0x14));
                      FUN_005af2c0(0x12);
                      iVar5 = func_0x001ae3e0(*(undefined4 *)(pcVar4 + 0x14));
                      iVar6 = (int)pcVar4[0xd];
                      if (pcVar4[0xd] < '\0') {
                        iVar6 = iVar6 + 1;
                      }
                      FUN_005af1e0(iVar12 + (iVar6 >> 1) * iVar5,*(undefined2 *)(pcVar4 + 0x12),
                                   pcVar4[0xf],auStack_50);
                      return;
                    }
                    FUN_005af2c0(0x12);
                    FUN_005af1e0(*(undefined2 *)(pcVar4 + 0x10),*(undefined2 *)(pcVar4 + 0x12),
                                 pcVar4[0xf],0x6c5a8b);
                    cVar2 = func_0x001ae3e0(0x6c5a9b);
                    FUN_005af2c0(0x11);
                    FUN_005af1e0(*(undefined2 *)(pcVar4 + 0x1c),*(undefined2 *)(pcVar4 + 0x1e),
                                 pcVar4[0x1b],0x6c5a9b);
                    FUN_005af2c0(0);
                    uVar8 = FUN_0062fea0(0x1a);
                    iVar6 = (int)cVar2;
                    if (cVar2 < '\0') {
                      iVar6 = iVar6 + 1;
                    }
                    FUN_005af1e0((int)*(short *)(pcVar4 + 0x1c) + (iVar6 >> 1) * 0x14 + 0x14,
                                 *(undefined2 *)(pcVar4 + 0x1e),pcVar4[0x1b],uVar8);
                    return;
                  }
                  func_0x00106b60(auStack_50,0,0x50);
                  func_0x001069a8(auStack_50,0x6c5a9b,0x10);
                  func_0x00109728(auStack_f0,0x639d60,*(undefined4 *)(pcVar4 + 0x14),auStack_50);
                  cVar2 = func_0x001ae3e0(auStack_f0);
                  FUN_005af2c0(0);
                  iVar5 = cVar2 * 10;
                  iVar6 = (int)((ulong)((long)(cVar2 * 5) << 0x21) >> 0x20);
                  if (iVar5 < 0) {
                    iVar6 = iVar5 + 1;
                  }
                  iVar12 = 0x140 - (iVar6 >> 1);
                  FUN_005af1e0(iVar12,*(undefined2 *)(pcVar4 + 0x12),pcVar4[0xf],
                               *(undefined4 *)(pcVar4 + 0x14));
                  FUN_005af2c0(0x12);
                  iVar5 = func_0x001ae3e0(*(undefined4 *)(pcVar4 + 0x14));
                  iVar6 = (int)pcVar4[0xd];
                  if (pcVar4[0xd] < '\0') {
                    iVar6 = iVar6 + 1;
                  }
                  FUN_005af1e0(iVar12 + (iVar6 >> 1) * iVar5,*(undefined2 *)(pcVar4 + 0x12),
                               pcVar4[0xf],auStack_50);
                  return;
                }
                FUN_005af2c0(0x12);
                FUN_005af1e0(*(undefined2 *)(pcVar4 + 0x10),*(undefined2 *)(pcVar4 + 0x12),
                             pcVar4[0xf],0x6c5a8b);
                cVar2 = func_0x001ae3e0(0x6c5a9b);
                FUN_005af2c0(0x11);
                FUN_005af1e0(*(undefined2 *)(pcVar4 + 0x1c),*(undefined2 *)(pcVar4 + 0x1e),
                             pcVar4[0x1b],0x6c5a9b);
                FUN_005af2c0(0);
                uVar8 = FUN_0062fea0(0x1a);
                iVar6 = (int)cVar2;
                if (cVar2 < '\0') {
                  iVar6 = iVar6 + 1;
                }
                FUN_005af1e0((int)*(short *)(pcVar4 + 0x1c) + (iVar6 >> 1) * 0x14 + 0x14,
                             *(undefined2 *)(pcVar4 + 0x1e),pcVar4[0x1b],uVar8);
                return;
              }
              pcVar4 = pcVar4 + 0xc;
            }
            FUN_005af2e0(pcVar4[1]);
            bVar1 = uRam006c5508 == 0;
            uRam006c5508 = uRam006c5508 - 1;
            if (bVar1) {
              uRam006c5508 = 0x3f;
            }
            if ((uRam006c5508 & 0x20) != 0) {
              cVar2 = *pcVar4;
              while (cVar2 == '\0') {
                FUN_005af2c0(pcVar4[2]);
                FUN_005af1e0(*(undefined2 *)(pcVar4 + 4),*(undefined2 *)(pcVar4 + 6),2,
                             *(undefined4 *)(pcVar4 + 8));
                pcVar4 = pcVar4 + 0xc;
                cVar2 = *pcVar4;
              }
              FUN_005af2c0(pcVar4[2]);
              FUN_005af1e0(*(undefined2 *)(pcVar4 + 4),*(undefined2 *)(pcVar4 + 6),2,
                           *(undefined4 *)(pcVar4 + 8));
            }
          }
        }
      }
    }
    else {
      if (cRam006c4fcd != -1) {
        uRam006c4fce = 0;
      }
      *(undefined1 *)(param_1 + 4) = 2;
    }
  }
  else if (cVar2 == '\0') {
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 1) = 1;
    uRam006c5508 = 0x3f;
    lVar7 = FUN_005b9120();
    if (lVar7 != 0) {
      if (cRam006c4fcd != -1) {
        uRam006c4fce = 0;
      }
      *(undefined1 *)(param_1 + 4) = 2;
    }
  }
  return;
}



================================================================