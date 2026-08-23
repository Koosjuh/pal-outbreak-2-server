FUNCTION FUN_005dcb90 @ 0x005dcb90  size=2044
CALLERS (0): 
CALLEES (4): FUN_005e1aa0@0x005e1aa0, FUN_005e0570@0x005e0570, FUN_005dfee0@0x005dfee0, FUN_005e4840@0x005e4840
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005dd310) */

void FUN_005dcb90(int param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  bool bVar10;
  float fVar11;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == 'c') {
    FUN_005dfee0();
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
  }
  else if ((((cVar1 == '\x01') || (cVar1 != '\0')) && (*(char *)(iRam00701070 + 0x34) == '\0')) &&
          ((*(char *)(iRam00701070 + 0x36) == '\0' ||
           (((*(char *)(iRam00701070 + 0x2e) != '\x03' && (*(char *)(iRam00701070 + 0x2e) != '\x01')
             ) && (*(char *)(iRam00701070 + 0x3a) == '\0')))))) {
    if ((*(ushort *)(iRam00701070 + 0x18) & 1) == 0) {
      if (*(short *)(iRam00701068 + 0x68e78) == 0) {
        *(short *)(iRam00701078 + 0x10) = *(short *)(iRam00701070 + 0x1e) << 1;
        *(undefined2 *)(iRam00701078 + 0x12) = 0x19e;
      }
      else {
        if (*(char *)(iRam00701068 + 0x68e88) != '\0') {
          *(undefined2 *)(param_1 + 10) = 0;
          *(undefined1 *)(iRam00701068 + 0x68e88) = 0;
        }
        if (*(short *)(param_1 + 10) < 1) {
          *(undefined2 *)(param_1 + 0xc) = 0xf;
        }
        if (0xfe < *(short *)(param_1 + 10)) {
          *(undefined2 *)(param_1 + 0xc) = 0xfff1;
        }
        *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + *(short *)(param_1 + 0xc);
        if (*(char *)(iRam00701068 + 0x68e85) == '\x01') {
          FUN_005e4840();
        }
      }
    }
    else {
      bVar10 = (long)*(short *)(iRam00701078 + 0x12) <=
               (long)(*(short *)(iRam00701070 + 0x1a) + 0x17c) &&
               ((long)*(short *)(iRam00701078 + 0x10) <=
                (long)(*(short *)(iRam00701070 + 0x1e) + 0x248) &&
               *(char *)(iRam00701068 + 0x68e82) == '\x03');
      if (((*(char *)(iRam00701068 + 0x68e85) == '\x02') ||
          (*(char *)(iRam00701068 + 0x68e85) == '\x01')) &&
         ((*(char *)(iRam00701068 + 0x68e83) == '\0' &&
          ((iVar6 = *(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0), iVar6 != 0
           && (*(char *)(iVar6 + 2) != '\b')))))) {
        if ((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 == 0) {
          iVar6 = 0x1b0 - *(short *)(iRam00701070 + 0x1c);
        }
        else {
          iVar6 = 0x19c - *(short *)(iRam00701070 + 0x1c);
        }
        if ((long)*(short *)(iRam00701078 + 0x12) < (long)iVar6) {
          for (uVar7 = 0; uVar7 < 500; uVar7 = uVar7 + 1 & 0xffff) {
            iVar6 = uVar7 * 4;
            pcVar3 = *(char **)(iRam00701068 + iVar6 + 0x5ffc0);
            if (pcVar3 == (char *)0x0) break;
            cVar1 = *pcVar3;
            if (cVar1 == '\0') goto LAB_005dd2e0;
            cVar2 = pcVar3[2];
            if ((((((cVar2 == '\f') || (cVar2 == '\v')) || (cVar2 == '\x05')) ||
                 ((cVar2 == '\x04' || (cVar2 == '\x03')))) ||
                ((cVar2 == '\b' || ((cVar2 == '\a' || (cVar2 == '\x06')))))) || (cVar2 == '\x02')) {
LAB_005dcf74:
              fVar11 = *(float *)(pcVar3 + 0x34) - (float)*(int *)(iRam00701070 + 4);
              if ((fVar11 <= (float)(int)*(short *)(iRam00701078 + 0x10)) &&
                 (iVar4 = *(int *)(iRam00701068 + iVar6 + 0x5ffc0),
                 (float)(int)*(short *)(iRam00701078 + 0x10) <= *(float *)(iVar4 + 0x40) + fVar11))
              {
                fVar11 = *(float *)(pcVar3 + 0x38) - (float)*(int *)(iRam00701070 + 8);
                if ((fVar11 < (float)(int)*(short *)(iRam00701078 + 0x12)) &&
                   ((float)(int)*(short *)(iRam00701078 + 0x12) < *(float *)(iVar4 + 0x44) + fVar11)
                   ) {
                  if (*(char *)(iRam00701068 + 0x68e88) != '\0') {
                    *(undefined2 *)(param_1 + 10) = 0;
                    *(undefined1 *)(iRam00701068 + 0x68e88) = 0;
                  }
                  if (*(short *)(param_1 + 10) < 1) {
                    *(undefined2 *)(param_1 + 0xc) = 0xf;
                  }
                  if (0xfe < *(short *)(param_1 + 10)) {
                    *(undefined2 *)(param_1 + 0xc) = 0xfff1;
                  }
                  *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + *(short *)(param_1 + 0xc);
                  if (*(short *)(param_1 + 0xc) < 1) {
                    uVar9 = 0xffffffffff0a0a0a;
                  }
                  else {
                    uVar9 = 0xffffffffff808080;
                  }
                  iVar4 = *(int *)(iVar6 + iRam00701068 + 0x5ffc0);
                  FUN_005e1aa0((*(float *)(iVar4 + 0x34) - (float)*(int *)(iRam00701070 + 4)) - 2.0,
                               (*(float *)(iVar4 + 0x38) - (float)*(int *)(iRam00701070 + 8)) - 2.0,
                               ((*(float *)(iVar4 + 0x34) + *(float *)(iVar4 + 0x40)) -
                               (float)*(int *)(iRam00701070 + 4)) + 2.0,
                               ((*(float *)(iVar4 + 0x38) + *(float *)(iVar4 + 0x44)) -
                               (float)*(int *)(iRam00701070 + 8)) + 2.0,uVar9,3);
                  iVar4 = *(int *)(iVar6 + iRam00701068 + 0x5ffc0);
                  if (*(char *)(iVar4 + 2) == '\x02') {
                    iVar8 = uVar7 * 4;
                    pcVar3 = *(char **)(iVar8 + iRam00701068 + 0x5ffbc);
                    if (((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) &&
                       (lVar5 = func_0x00109d70(*(undefined4 *)(pcVar3 + 0x60),
                                                *(undefined4 *)(iVar4 + 0x60)), lVar5 == 0)) {
                      iVar4 = *(int *)(iVar8 + iRam00701068 + 0x5ffbc);
                      FUN_005e1aa0((*(float *)(iVar4 + 0x34) - (float)*(int *)(iRam00701070 + 4)) -
                                   2.0,(*(float *)(iVar4 + 0x38) - (float)*(int *)(iRam00701070 + 8)
                                       ) - 2.0,
                                   ((*(float *)(iVar4 + 0x34) + *(float *)(iVar4 + 0x40)) -
                                   (float)*(int *)(iRam00701070 + 4)) + 2.0,
                                   ((*(float *)(iVar4 + 0x38) + *(float *)(iVar4 + 0x44)) -
                                   (float)*(int *)(iRam00701070 + 8)) + 2.0,uVar9,3);
                    }
                    pcVar3 = *(char **)(iVar8 + iRam00701068 + 0x5ffc4);
                    if (((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) &&
                       (lVar5 = func_0x00109d70(*(undefined4 *)(pcVar3 + 0x60),
                                                *(undefined4 *)
                                                 (*(int *)(iVar6 + iRam00701068 + 0x5ffc0) + 0x60)),
                       lVar5 == 0)) {
                      iVar6 = *(int *)(uVar7 * 4 + iRam00701068 + 0x5ffc4);
                      FUN_005e1aa0((*(float *)(iVar6 + 0x34) - (float)*(int *)(iRam00701070 + 4)) -
                                   2.0,(*(float *)(iVar6 + 0x38) - (float)*(int *)(iRam00701070 + 8)
                                       ) - 2.0,
                                   ((*(float *)(iVar6 + 0x34) + *(float *)(iVar6 + 0x40)) -
                                   (float)*(int *)(iRam00701070 + 4)) + 2.0,
                                   ((*(float *)(iVar6 + 0x38) + *(float *)(iVar6 + 0x44)) -
                                   (float)*(int *)(iRam00701070 + 8)) + 2.0,uVar9,3);
                    }
                  }
                  bVar10 = true;
                  *(short *)(iRam00701068 + 0x68e78) = (short)uVar7;
                  break;
                }
              }
            }
            else if (cVar2 == '\r') {
              if ((cVar1 == '\x03') || (cVar1 == '\x05')) goto LAB_005dcf74;
            }
            else if (((cVar2 == '\x12') || (cVar2 == '\x11')) &&
                    (**(char **)(pcVar3 + 0x60) != '\0')) goto LAB_005dcf74;
LAB_005dd2e0:
          }
        }
      }
      if (bVar10) {
        FUN_005e0570((float)(int)*(short *)(iRam00701078 + 0x10),
                     (float)(int)*(short *)(iRam00701078 + 0x12));
      }
      else {
        FUN_005e0570((float)(int)*(short *)(iRam00701078 + 0x10),
                     (float)(int)*(short *)(iRam00701078 + 0x12),0);
      }
    }
  }
  return;
}



================================================================