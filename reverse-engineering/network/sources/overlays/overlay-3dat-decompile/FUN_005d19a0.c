FUNCTION FUN_005d19a0 @ 0x005d19a0  size=632
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d19a0(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined2 uVar4;
  int iVar5;
  float fVar6;
  
  if ((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 != 0) {
    *(undefined1 *)(iRam00701068 + 0x68e82) = 1;
  }
  if ((int)(*(ushort *)(iRam00701070 + 0x18) & 2) >> 1 == 0) goto LAB_005d1a80;
  if ((long)*(short *)(iRam00701078 + 0x10) <= (long)(0x270 - *(short *)(iRam00701070 + 0x20))) {
    if ((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 == 0) {
      if (((long)*(short *)(iRam00701078 + 0x12) <= (long)(0x1b0 - *(short *)(iRam00701070 + 0x1c)))
         || ((long)(0x1c0 - *(short *)(iRam00701070 + 0x1c)) <=
             (long)*(short *)(iRam00701078 + 0x12))) goto LAB_005d1a80;
    }
    else if (((long)*(short *)(iRam00701078 + 0x12) <=
              (long)(0x19c - *(short *)(iRam00701070 + 0x1c))) ||
            (0x1ab < (long)*(short *)(iRam00701078 + 0x12))) {
LAB_005d1a80:
      iVar5 = 0;
      do {
        while( true ) {
          if ((499 < iVar5) ||
             (pcVar3 = *(char **)(iRam00701068 + iVar5 * 4 + 0x5ffc0), pcVar3 == (char *)0x0)) {
            *(undefined1 *)(iRam00701068 + 0x68e82) = 1;
            return;
          }
          cVar1 = *pcVar3;
          if (cVar1 != '\0') break;
LAB_005d1bf0:
          iVar5 = iVar5 + 1;
        }
        fVar6 = *(float *)(pcVar3 + 0x34) - (float)*(int *)(iRam00701070 + 4);
        if (((float)(int)*(short *)(iRam00701078 + 0x10) < fVar6) ||
           (*(float *)(pcVar3 + 0x40) + fVar6 < (float)(int)*(short *)(iRam00701078 + 0x10)))
        goto LAB_005d1bf0;
        fVar6 = *(float *)(pcVar3 + 0x38) - (float)*(int *)(iRam00701070 + 8);
        if (((float)(int)*(short *)(iRam00701078 + 0x12) <= fVar6) ||
           (*(float *)(pcVar3 + 0x44) + fVar6 <= (float)(int)*(short *)(iRam00701078 + 0x12)))
        goto LAB_005d1bf0;
        cVar2 = pcVar3[2];
        uVar4 = (undefined2)iVar5;
        if ((cVar2 == '\a') || (cVar2 == '\x06')) {
          *(undefined2 *)(iRam00701068 + 0x68e78) = uVar4;
          return;
        }
        if (cVar2 == '\r') {
          if (((cVar1 == '\x03') || (cVar1 == '\x05')) && (pcVar3[5] != '\0')) {
            *(undefined2 *)(iRam00701068 + 0x68e78) = uVar4;
            return;
          }
          goto LAB_005d1bf0;
        }
        if (((cVar2 == '\x12') || (cVar2 == '\x11')) || (cVar2 == '\x02')) {
          if (**(char **)(pcVar3 + 0x60) != '\0') {
            *(undefined2 *)(iRam00701068 + 0x68e78) = uVar4;
            return;
          }
          goto LAB_005d1bf0;
        }
        iVar5 = iVar5 + 1;
      } while( true );
    }
  }
  return;
}



================================================================