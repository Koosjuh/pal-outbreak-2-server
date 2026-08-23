FUNCTION FUN_005e4840 @ 0x005e4840  size=668
CALLERS (1): FUN_005dcb90@0x005dcb90
CALLEES (3): FUN_005e1aa0@0x005e1aa0, FUN_005e2060@0x005e2060, FUN_005e07c0@0x005e07c0
----------------------------------------------------------------

void FUN_005e4840(int param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  byte bVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  if (0 < *(short *)(param_1 + 0xc)) {
    iVar2 = *(int *)(iRam00701068 + 0x5ffc0 + (uint)*(ushort *)(iRam00701068 + 0x68e78) * 4);
    cVar1 = *(char *)(iVar2 + 2);
    if (((((cVar1 != '\x02') && (cVar1 != '\f')) && (cVar1 != '\v')) &&
        (((cVar1 != '\b' && (cVar1 != '\a')) &&
         ((cVar1 != '\x06' && ((cVar1 != '\x05' && (cVar1 != '\x04')))))))) &&
       ((cVar1 != '\x03' &&
        ((((cVar1 != '\x12' && (cVar1 != '\x11')) && (cVar1 == '\r')) &&
         ((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 == 0)))))) {
      bVar4 = *(byte *)(iVar2 + 0x5d) & 0xf;
      if (bVar4 == 4) {
        lVar3 = 5;
      }
      else if (bVar4 == 3) {
        lVar3 = 4;
      }
      else if (bVar4 == 2) {
        lVar3 = 3;
      }
      else if (bVar4 == 1) {
        if ((*(byte *)(iVar2 + 0x5d) & 0x10) == 0x10) {
          lVar3 = 4;
        }
        else {
          lVar3 = 2;
        }
      }
      else {
        lVar3 = 0;
      }
      if (lVar3 != 0) {
        FUN_005e07c0(*(float *)(iVar2 + 0x34) - (float)*(int *)(iRam00701070 + 4),
                     *(float *)(iVar2 + 0x38) - (float)*(int *)(iRam00701070 + 8),0,0,lVar3,
                     0xffffffffff808080);
        if (*(char *)(iRam00701070 + 0x5c3) == '\0') {
          return;
        }
        FUN_005e2060();
        return;
      }
    }
    fVar6 = (*(float *)(iVar2 + 0x38) - (float)*(int *)(iRam00701070 + 8)) - 1.0;
    fVar5 = (float)(0x1c0 - *(short *)(iRam00701070 + 0x1c));
    if (fVar6 <= fVar5) {
      fVar7 = ((*(float *)(iVar2 + 0x38) + *(float *)(iVar2 + 0x44)) -
              (float)*(int *)(iRam00701070 + 8)) + 3.0;
      if (fVar7 <= fVar5) {
        fVar5 = fVar7;
      }
      FUN_005e1aa0((*(float *)(iVar2 + 0x34) - (float)*(int *)(iRam00701070 + 4)) - 1.0,fVar6,
                   ((*(float *)(iVar2 + 0x34) + *(float *)(iVar2 + 0x40)) -
                   (float)*(int *)(iRam00701070 + 4)) + 3.0,fVar5,0xffffffffff808080,3);
    }
  }
  return;
}



================================================================