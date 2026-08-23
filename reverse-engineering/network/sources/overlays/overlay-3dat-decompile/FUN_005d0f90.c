FUNCTION FUN_005d0f90 @ 0x005d0f90  size=1748
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d0f90(void)

{
  short sVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (*(byte *)(iRam00701078 + 4) == 0) {
    if ((*(ushort *)(iRam00701068 + 0x4f8a2) & 0x10) == 0) {
      sVar1 = *(short *)(iRam00701078 + 0x10);
      if ((0x248 < sVar1) && (sVar1 < 0x280)) {
        *(int *)(iRam00701078 + 0x14) = (int)sVar1;
        *(int *)(iRam00701078 + 0x18) = (int)*(short *)(iRam00701078 + 0x12);
        *(int *)(iRam00701078 + 0x1c) =
             (int)*(short *)(iRam00701078 + 0x12) - (int)*(short *)(iRam00701070 + 0x24);
      }
      if ((0x17c < *(short *)(iRam00701078 + 0x12)) && (*(short *)(iRam00701078 + 0x12) < 0x1c0)) {
        *(int *)(iRam00701078 + 0x14) = (int)*(short *)(iRam00701078 + 0x10);
        *(int *)(iRam00701078 + 0x18) = (int)*(short *)(iRam00701078 + 0x12);
        *(int *)(iRam00701078 + 0x1c) =
             (int)*(short *)(iRam00701078 + 0x10) - (int)*(short *)(iRam00701070 + 0x28);
      }
    }
    else {
      if ((0x248 < *(short *)(iRam00701078 + 0x10)) && (*(short *)(iRam00701078 + 0x10) < 0x280)) {
        lVar2 = (long)*(short *)(iRam00701078 + 0x12);
        if ((0x10 < lVar2) && ((lVar2 < 0x17c && (0x248 < *(int *)(iRam00701078 + 0x14))))) {
          if (lVar2 == *(int *)(iRam00701078 + 0x18)) {
            return;
          }
          *(short *)(iRam00701070 + 0x24) =
               *(short *)(iRam00701078 + 0x12) - (short)*(undefined4 *)(iRam00701078 + 0x1c);
          if ((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 == 0) {
            iVar3 = (0x1a0 - *(short *)(iRam00701070 + 0x1a)) - (int)*(short *)(iRam00701070 + 0x1c)
            ;
          }
          else {
            iVar3 = (0x17c - *(short *)(iRam00701070 + 0x1a)) - (int)*(short *)(iRam00701070 + 0x1c)
            ;
          }
          *(int *)(iRam00701070 + 8) =
               (*(int *)(iRam00701070 + 0x10) * (*(short *)(iRam00701070 + 0x24) + -0x10)) / iVar3;
        }
      }
      lVar2 = (long)*(short *)(iRam00701078 + 0x10);
      if ((((0x10 < lVar2) && (lVar2 < 0x24c)) && (0x17c < *(short *)(iRam00701078 + 0x12))) &&
         (0x17c < *(int *)(iRam00701078 + 0x18))) {
        if (lVar2 == *(int *)(iRam00701078 + 0x14)) {
          return;
        }
        *(short *)(iRam00701070 + 0x28) =
             *(short *)(iRam00701078 + 0x10) - (short)*(undefined4 *)(iRam00701078 + 0x1c);
        *(int *)(iRam00701070 + 4) =
             (*(int *)(iRam00701070 + 0xc) * (*(short *)(iRam00701070 + 0x28) + -0x10)) / 0x228;
      }
    }
    if (((long)(*(short *)(iRam00701070 + 0x1e) + 0x248) <= (long)*(short *)(iRam00701078 + 0x10))
       || ((long)(*(short *)(iRam00701070 + 0x1a) + 0x17c) <= (long)*(short *)(iRam00701078 + 0x12))
       ) {
      iVar3 = 0x17c - *(short *)(iRam00701070 + 0x22);
      if ((long)iVar3 < (long)*(short *)(iRam00701070 + 0x24)) {
        *(short *)(iRam00701070 + 0x24) = (short)iVar3;
        *(int *)(iRam00701070 + 8) = *(int *)(iRam00701070 + 0x10) + -0x17c;
      }
      if (*(short *)(iRam00701070 + 0x24) < 0x10) {
        *(undefined2 *)(iRam00701070 + 0x24) = 0x10;
        *(undefined4 *)(iRam00701070 + 8) = 0;
      }
      iVar3 = 0x24c - *(short *)(iRam00701070 + 0x26);
      if ((long)iVar3 < (long)*(short *)(iRam00701070 + 0x28)) {
        *(short *)(iRam00701070 + 0x28) = (short)iVar3;
        *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 0xc) + -0x248;
      }
      if (*(short *)(iRam00701070 + 0x28) < 0x10) {
        *(undefined2 *)(iRam00701070 + 0x28) = 0x10;
        *(undefined4 *)(iRam00701070 + 4) = 0;
      }
    }
  }
  else {
    iVar3 = *(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0);
    fVar5 = *(float *)(iVar3 + 0x38) - (float)*(int *)(iRam00701070 + 8);
    fVar6 = (*(float *)(iVar3 + 0x34) - (float)*(int *)(iRam00701070 + 4)) +
            *(float *)(iVar3 + 0x40);
    if (10 < *(byte *)(iRam00701078 + 4)) {
      if ((*(ushort *)(iRam00701068 + 0x4f8a2) & 0x10) == 0) {
        fVar4 = (float)(int)*(short *)(iRam00701078 + 0x10);
        if ((fVar6 - 16.0 <= fVar4) && (fVar4 <= fVar6)) {
          if (*(char *)(iRam00701078 + 6) == '\0') {
            if ((float)(int)*(short *)(iRam00701078 + 0x12) <
                fVar5 + 18.0 + (float)(int)*(short *)(iRam00701078 + 8)) {
              return;
            }
            if (fVar5 + 18.0 + (float)(int)*(short *)(iRam00701078 + 10) <
                (float)(int)*(short *)(iRam00701078 + 0x12)) {
              return;
            }
          }
          else {
            if ((float)(int)*(short *)(iRam00701078 + 0x12) <
                (fVar5 - 180.0) + (float)(int)*(short *)(iRam00701078 + 8)) {
              return;
            }
            if ((fVar5 - 180.0) + (float)(int)*(short *)(iRam00701078 + 10) <
                (float)(int)*(short *)(iRam00701078 + 0x12)) {
              return;
            }
          }
          *(int *)(iRam00701078 + 0x14) = (int)*(short *)(iRam00701078 + 0x10);
          *(int *)(iRam00701078 + 0x18) = (int)*(short *)(iRam00701078 + 0x12);
          *(int *)(iRam00701078 + 0x1c) =
               (int)*(short *)(iRam00701078 + 0x12) - (int)*(short *)(iRam00701078 + 8);
        }
      }
      else if ((((*(int *)(iRam00701078 + 0x1c) != 0) &&
                (fVar6 - 16.0 <= (float)(int)*(short *)(iRam00701078 + 0x10))) &&
               ((float)(int)*(short *)(iRam00701078 + 0x10) <= fVar6)) &&
              (sVar1 = *(short *)(iRam00701078 + 0x12),
              (long)sVar1 != (long)*(int *)(iRam00701078 + 0x18))) {
        if (*(char *)(iRam00701078 + 6) == '\0') {
          fVar6 = (float)(int)sVar1;
          if (fVar6 < fVar5 + 18.0 + (float)(int)*(short *)(iRam00701078 + 8)) {
            return;
          }
          if (fVar5 + 18.0 + (float)(int)*(short *)(iRam00701078 + 10) < fVar6) {
            return;
          }
        }
        else {
          fVar6 = (float)(int)sVar1;
          if (fVar6 < (fVar5 - 180.0) + (float)(int)*(short *)(iRam00701078 + 8)) {
            return;
          }
          if ((fVar5 - 180.0) + (float)(int)*(short *)(iRam00701078 + 10) < fVar6) {
            return;
          }
        }
        *(short *)(iRam00701078 + 8) = sVar1 - (short)*(int *)(iRam00701078 + 0x1c);
        if (*(short *)(iRam00701078 + 8) < 0x12) {
          *(undefined1 *)(iRam00701078 + 5) = 1;
          *(undefined2 *)(iRam00701078 + 8) = 0x12;
          *(short *)(iRam00701078 + 10) = *(short *)(iRam00701078 + 0xc) + 0x12;
        }
        else {
          *(char *)(iRam00701078 + 5) =
               (char)((int)((uint)*(byte *)(iRam00701078 + 4) *
                           (*(short *)(iRam00701078 + 8) + -0x12)) / 0x90) + '\x01';
          if (*(char *)(iRam00701078 + 5) == '\0') {
            *(undefined1 *)(iRam00701078 + 5) = 1;
          }
        }
      }
    }
  }
  return;
}



================================================================