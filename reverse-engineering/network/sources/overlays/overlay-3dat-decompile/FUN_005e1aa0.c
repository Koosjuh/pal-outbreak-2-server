FUNCTION FUN_005e1aa0 @ 0x005e1aa0  size=760
CALLERS (2): FUN_005dcb90@0x005dcb90, FUN_005e4840@0x005e4840
CALLEES (1): FUN_005dda30@0x005dda30
----------------------------------------------------------------

void FUN_005e1aa0(float param_1,float param_2,float param_3,float param_4,undefined8 param_5,
                 int param_6)

{
  short sVar1;
  short sVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  
  sVar1 = *(short *)(iRam00701070 + 0x1e);
  fVar4 = (float)(int)sVar1;
  if (fVar4 <= param_1) {
    fVar4 = param_1;
  }
  sVar2 = *(short *)(iRam00701070 + 0x1a);
  fVar5 = (float)(int)sVar2;
  if (fVar5 <= param_2) {
    fVar5 = param_2;
  }
  iVar3 = 0x280 - *(short *)(iRam00701070 + 0x20);
  if ((float)iVar3 < param_3) {
    param_3 = (float)(int)(short)iVar3;
  }
  iVar3 = 0x1c0 - *(short *)(iRam00701070 + 0x1c);
  if ((float)iVar3 < param_4) {
    param_4 = (float)(int)(short)iVar3;
  }
  if (((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 == 0) ||
     ((int)(*(ushort *)(iRam00701070 + 0x18) & 2) >> 1 == 0)) {
    if ((float)(sVar1 + 0x247) < fVar4) {
      return;
    }
    if ((float)(sVar2 + 0x17b) < fVar5) {
      return;
    }
    iVar3 = sVar1 + 0x248;
    if ((float)iVar3 < param_3) {
      param_3 = (float)(int)(short)iVar3;
    }
    iVar3 = sVar2 + 0x17c;
    if ((float)iVar3 < param_4) {
      param_4 = (float)(int)(short)iVar3;
    }
  }
  else {
    if ((float)(sVar1 + 0x247) < fVar4) {
      return;
    }
    if ((float)(sVar2 + 0x17b) < fVar5) {
      return;
    }
    iVar3 = sVar1 + 0x248;
    if ((float)iVar3 < param_3) {
      param_3 = (float)(int)(short)iVar3;
    }
    iVar3 = sVar2 + 0x17c;
    if ((float)iVar3 < param_4) {
      param_4 = (float)(int)(short)iVar3;
    }
  }
  FUN_005dda30(fVar4,fVar5,param_3,fVar5 + (float)param_6,param_5);
  FUN_005dda30(param_3 - (float)param_6,fVar5,param_3,param_4,param_5);
  FUN_005dda30(fVar4,param_4 - (float)param_6,param_3,param_4,param_5);
  FUN_005dda30(fVar4,fVar5,fVar4 + (float)param_6,param_4,param_5);
  return;
}



================================================================