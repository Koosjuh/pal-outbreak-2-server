FUNCTION FUN_005d1e80 @ 0x005d1e80  size=3468
CALLERS (0): 
CALLEES (12): FUN_005dc1e0@0x005dc1e0, FUN_005d3930@0x005d3930, FUN_005d2c20@0x005d2c20, FUN_005d59f0@0x005d59f0, FUN_005cf600@0x005cf600, FUN_005d47f0@0x005d47f0, FUN_005d5c20@0x005d5c20, FUN_005d1d60@0x005d1d60, FUN_0061e730@0x0061e730, FUN_005d5cc0@0x005d5cc0, FUN_005d5b60@0x005d5b60, FUN_005d46a0@0x005d46a0, ...
----------------------------------------------------------------

void FUN_005d1e80(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  bool bVar5;
  char cVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  long lVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  
  cVar6 = FUN_005d1d60();
  if (cVar6 < '\0') {
    return;
  }
  lVar10 = (long)*(short *)(iRam00701078 + 0x12);
  if (0x1ac - *(short *)(iRam00701070 + 0x1c) < lVar10) {
    return;
  }
  if (((((long)*(short *)(iRam00701078 + 0x10) < (long)*(short *)(iRam00701070 + 0x1e)) ||
       (lVar10 < *(short *)(iRam00701070 + 0x1a))) ||
      ((long)(*(short *)(iRam00701070 + 0x1e) + 0x248) < (long)*(short *)(iRam00701078 + 0x10))) ||
     (iVar13 = 0, *(short *)(iRam00701070 + 0x1a) + 0x17c < lVar10)) {
    *(undefined4 *)(iRam00701078 + 0x20) = 0;
    *(undefined1 *)(iRam00701078 + 4) = 0;
    return;
  }
  bVar5 = true;
  while (bVar5) {
    iVar12 = iVar13 * 4;
    pcVar3 = *(char **)(iRam00701068 + iVar12 + 0x5ffc0);
    if (pcVar3 == (char *)0x0) break;
    cVar6 = *pcVar3;
    if (cVar6 != '\0') {
      fVar14 = *(float *)(pcVar3 + 0x34) - (float)*(int *)(iRam00701070 + 4);
      if ((fVar14 <= (float)(int)*(short *)(iRam00701078 + 0x10)) &&
         (iVar11 = *(int *)(iRam00701068 + iVar12 + 0x5ffc0),
         (float)(int)*(short *)(iRam00701078 + 0x10) <= *(float *)(iVar11 + 0x40) + fVar14)) {
        if (*(int *)(iRam00701078 + 0x20) != 0) {
          if (*(char *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) + 2) !=
              '\b') {
            return;
          }
          uVar7 = FUN_005d2c20();
          *(undefined4 *)(iRam00701078 + 0x20) = uVar7;
          return;
        }
        fVar14 = *(float *)(pcVar3 + 0x38) - (float)*(int *)(iRam00701070 + 8);
        if ((fVar14 < (float)(int)*(short *)(iRam00701078 + 0x12)) &&
           ((float)(int)*(short *)(iRam00701078 + 0x12) < *(float *)(iVar11 + 0x44) + fVar14)) {
          if ((*(char *)(iRam00701070 + 0x38) == '\0') && (*(char *)(iRam00701070 + 0x3a) == '\0'))
          {
            cVar1 = pcVar3[2];
            if (cVar1 == '\r') {
              if ((cVar6 == '\x03') || (cVar6 == '\x05')) {
                FUN_0061e730();
              }
            }
            else if ((((cVar1 == '\x05') || (cVar1 == '\x04')) || (cVar1 == '\x03')) ||
                    ((((cVar1 == '\x12' || (cVar1 == '\x11')) || (cVar1 == '\x02')) &&
                     (**(char **)(pcVar3 + 0x60) != '\0')))) {
              FUN_0061e730();
            }
          }
          pcVar3 = *(char **)(iRam00701068 + iVar12 + 0x5ffc0);
          cVar6 = pcVar3[2];
          if (cVar6 == '\f') {
            FUN_0061e730();
            iVar13 = *(int *)(iVar12 + iRam00701068 + 0x5ffc0);
            puVar8 = (undefined1 *)(iVar13 + 5);
            if (*(char *)(iVar13 + 5) == '\x01') {
              *puVar8 = 0;
              return;
            }
            *puVar8 = 1;
            return;
          }
          if (cVar6 == '\v') {
            FUN_0061e730();
            iVar11 = iVar13;
            goto LAB_005d2ac4;
          }
          if (cVar6 == '\b') {
            FUN_0061e730();
            if (*(int *)(iRam00701078 + 0x20) == iVar13) {
              *(int *)(iRam00701078 + 0x20) = 0;
              *(undefined1 *)(iRam00701078 + 2) = 0;
            }
            else {
              *(int *)(iRam00701078 + 0x20) = iVar13;
              *(undefined1 *)(iRam00701078 + 2) =
                   *(undefined1 *)(*(int *)(iVar12 + iRam00701068 + 0x5ffc0) + 5);
              *(undefined1 *)(iRam00701078 + 4) = 0;
              iVar13 = *(int *)(iRam00701078 + 0x20);
              while (((iVar13 = iVar13 + 1, iVar13 < 500 &&
                      (iVar11 = *(int *)(iRam00701068 + iVar13 * 4 + 0x5ffc0),
                      *(char *)(iVar11 + 2) == '\b')) && (*(char *)(iVar11 + 0x5f) != '\0'))) {
                *(char *)(iRam00701078 + 4) = *(char *)(iRam00701078 + 4) + '\x01';
              }
              bVar2 = *(byte *)(iRam00701078 + 4);
              if (bVar2 < 10) {
                *(undefined1 *)(iRam00701078 + 5) = 1;
              }
              else if ((int)((uint)bVar2 - (uint)*(byte *)(iRam00701078 + 2)) < 9) {
                *(byte *)(iRam00701078 + 5) = bVar2 - 9;
              }
              else {
                *(undefined1 *)(iRam00701078 + 5) = 1;
                while( true ) {
                  if ((499 < (ulong)*(byte *)(iRam00701078 + 5)) ||
                     (*(char *)(*(int *)(iRam00701068 +
                                         (*(int *)(iRam00701078 + 0x20) +
                                         (uint)*(byte *)(iRam00701078 + 5)) * 4 + 0x5ffc0) + 0x5f)
                      == *(char *)(iRam00701078 + 2))) break;
                  *(char *)(iRam00701078 + 5) = *(char *)(iRam00701078 + 5) + '\x01';
                }
              }
              if (*(byte *)(iRam00701078 + 4) < 10) {
                if (*(byte *)(iRam00701078 + 4) == 0) {
                  FUN_005cf600();
                  return;
                }
                if (380.0 < (*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 +
                                                0x5ffc0) + 0x38) - (float)*(int *)(iRam00701070 + 8)
                            ) + 180.0) {
                  *(undefined1 *)(iRam00701078 + 6) = 1;
                  *(short *)(iRam00701078 + 0x12) =
                       (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 +
                                                         iRam00701068 + 0x5ffc0) + 0x38) -
                                    (float)*(int *)(iRam00701070 + 8)) - 9.0);
                }
                else {
                  *(undefined1 *)(iRam00701078 + 6) = 0;
                  *(short *)(iRam00701078 + 0x12) =
                       (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 +
                                                         iRam00701068 + 0x5ffc0) + 0x38) -
                                    (float)*(int *)(iRam00701070 + 8)) + 20.0 + 9.0);
                }
                *(short *)(iRam00701078 + 0x10) =
                     (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 +
                                                       iRam00701068 + 0x5ffc0) + 0x34) -
                                  (float)*(int *)(iRam00701070 + 4)) + 10.0);
              }
              else {
                if (380.0 < (*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 +
                                                0x5ffc0) + 0x38) - (float)*(int *)(iRam00701070 + 8)
                            ) + 180.0) {
                  *(undefined1 *)(iRam00701078 + 6) = 1;
                  *(short *)(iRam00701078 + 0x12) =
                       (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 +
                                                         iRam00701068 + 0x5ffc0) + 0x38) -
                                    (float)*(int *)(iRam00701070 + 8)) - 9.0);
                }
                else {
                  *(undefined1 *)(iRam00701078 + 6) = 0;
                  *(short *)(iRam00701078 + 0x12) =
                       (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 +
                                                         iRam00701068 + 0x5ffc0) + 0x38) -
                                    (float)*(int *)(iRam00701070 + 8)) + 20.0 + 9.0);
                }
                *(short *)(iRam00701078 + 0x10) =
                     (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 +
                                                       iRam00701068 + 0x5ffc0) + 0x34) -
                                  (float)*(int *)(iRam00701070 + 4)) + 10.0);
              }
            }
            puVar8 = *(undefined1 **)(iVar12 + iRam00701068 + 0x5ffc0);
            fVar14 = *(float *)(puVar8 + 0x40) +
                     (*(float *)(puVar8 + 0x34) - (float)*(int *)(iRam00701070 + 4));
            if ((float)(int)*(short *)(iRam00701078 + 0x10) <= fVar14 - 16.0) {
              return;
            }
            if (fVar14 <= (float)(int)*(short *)(iRam00701078 + 0x10)) {
              return;
            }
            *puVar8 = 0xc;
            *(undefined4 *)(iRam00701068 + 0x69018) = 2;
            return;
          }
          if (cVar6 == '\x05') {
            if (pcVar3[0x5d] == '\x01') {
              FUN_005d5b60(0);
              return;
            }
            if (pcVar3[0x5d] != '\0') {
              return;
            }
            FUN_005d5cc0(0x642e00);
            *(undefined1 *)(iRam00701078 + 1) = 0;
            *(undefined4 *)(iRam00701078 + 0x20) = 0;
            *(undefined1 *)(*(int *)(iVar12 + iRam00701068 + 0x5ffc0) + 5) = 1;
            *(undefined4 *)(iRam00701068 + 0x69018) = 2;
            if (*(char *)(iRam00701070 + 0x2e) != '\b') {
              FUN_005d59f0();
              return;
            }
            FUN_005d5c20();
            return;
          }
          if (cVar6 == '\x04') {
            pcVar3[5] = '\x01';
            *(undefined4 *)(iRam00701068 + 0x69018) = 2;
            FUN_005d46a0(iVar13);
            return;
          }
          if (cVar6 == '\x03') {
            FUN_005d47f0(iVar13);
          }
          else if (((cVar6 == '\x12') || (cVar6 == '\x11')) || (cVar6 == '\x02')) {
            if (**(char **)(pcVar3 + 0x60) == '\0') {
              return;
            }
            FUN_005d3930(iVar13);
          }
          else {
            if (cVar6 != '\r') {
              if ((cVar6 != '\a') && (cVar6 != '\x06')) {
                return;
              }
              *(undefined1 *)(iRam00701068 + 0x68e84) = 1;
              FUN_0061e730();
              *(int *)(iRam00701078 + 0x20) = iVar13;
              *(short *)(iRam00701068 + 0x68e78) = (short)iVar13;
              iVar13 = *(int *)(iRam00701068 + 0x5ffc0 + iVar12);
              if (*(char *)(iVar13 + 2) == '\a') {
                FUN_005dc1e0(*(undefined4 *)(iVar13 + 100),*(undefined1 *)(iVar13 + 5),5);
              }
              else if (*(char *)(iVar13 + 2) == '\x06') {
                if (*(char *)(iVar13 + 0x5d) == '\x04') {
                  uVar9 = 1;
                  switch(((*(byte **)(iVar13 + 0x60))[1] - 0x30) +
                         (**(byte **)(iVar13 + 0x60) - 0x30) * 10) {
                  case 0:
                  case 2:
                  case 3:
                  case 4:
                  case 8:
                    uVar9 = 4;
                    break;
                  case 1:
                  case 5:
                  case 6:
                    uVar9 = 3;
                    break;
                  case 7:
                    uVar9 = 2;
                  }
                  FUN_005dc1e0(*(undefined4 *)(iVar13 + 100),*(undefined1 *)(iVar13 + 5),uVar9);
                }
                else {
                  FUN_005dc1e0(*(undefined4 *)(iVar13 + 100),*(undefined1 *)(iVar13 + 5),2);
                }
              }
              *(undefined1 *)(iRam00701068 + 0x68e84) = 1;
              *(undefined1 *)(iRam00701078 + 1) = 1;
              return;
            }
            if (*pcVar3 != '\x02') {
              if (*pcVar3 == '\x03') {
                FUN_005d3930(iVar13);
              }
              if (**(char **)(iVar12 + iRam00701068 + 0x5ffc0) != '\x05') {
                return;
              }
              FUN_005d47f0(iVar13);
              return;
            }
          }
        }
      }
    }
    iVar13 = iVar13 + 1;
    bVar5 = iVar13 < 500;
  }
  if (iVar13 != 500) {
    return;
  }
  *(undefined4 *)(iRam00701078 + 0x20) = 0;
  return;
LAB_005d2ac4:
  iVar11 = iVar11 + 1;
  if (iVar11 < 500) {
    iVar4 = *(int *)(iRam00701068 + iVar11 * 4 + 0x5ffc0);
    if ((iVar4 == 0) || (*(char *)(iVar4 + 2) == '\x13')) goto LAB_005d2b5c;
    if ((*(char *)(iVar4 + 2) == '\v') &&
       (lVar10 = func_0x00109d70(*(undefined4 *)(iVar4 + 0x60),
                                 *(undefined4 *)(*(int *)(iVar12 + iRam00701068 + 0x5ffc0) + 0x60)),
       lVar10 == 0)) {
      *(undefined1 *)(*(int *)(iRam00701068 + iVar11 * 4 + 0x5ffc0) + 5) = 0;
    }
    goto LAB_005d2ac4;
  }
LAB_005d2b5c:
  do {
    iVar13 = iVar13 + -1;
    if (iVar13 < 1) {
LAB_005d2b64:
      *(undefined1 *)(*(int *)(iVar12 + iRam00701068 + 0x5ffc0) + 5) = 1;
      return;
    }
    iVar11 = *(int *)(iRam00701068 + iVar13 * 4 + 0x5ffc0);
    if ((iVar11 == 0) || (*(char *)(iVar11 + 2) == '\x13')) goto LAB_005d2b64;
    if ((*(char *)(iVar11 + 2) == '\v') &&
       (lVar10 = func_0x00109d70(*(undefined4 *)(iVar11 + 0x60),
                                 *(undefined4 *)(*(int *)(iVar12 + iRam00701068 + 0x5ffc0) + 0x60)),
       lVar10 == 0)) {
      *(undefined1 *)(*(int *)(iRam00701068 + iVar13 * 4 + 0x5ffc0) + 5) = 0;
    }
  } while( true );
}



================================================================