FUNCTION FUN_005e1da0 @ 0x005e1da0  size=388
CALLERS (3): FUN_005e3a80@0x005e3a80, FUN_005e2fa0@0x005e2fa0, FUN_005dc010@0x005dc010
CALLEES (1): FUN_005dda30@0x005dda30
----------------------------------------------------------------

void FUN_005e1da0(float param_1,float param_2,float param_3,float param_4,undefined8 param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)(int)*(short *)(iRam00701070 + 0x1e);
  if (fVar2 <= param_1) {
    fVar2 = param_1;
  }
  fVar3 = (float)(int)*(short *)(iRam00701070 + 0x1a);
  if (fVar3 <= param_2) {
    fVar3 = param_2;
  }
  iVar1 = 0x280 - *(short *)(iRam00701070 + 0x20);
  if ((float)iVar1 < param_3) {
    param_3 = (float)(int)(short)iVar1;
  }
  iVar1 = 0x1c0 - *(short *)(iRam00701070 + 0x1c);
  if ((float)iVar1 < param_4) {
    param_4 = (float)(int)(short)iVar1;
  }
  FUN_005dda30(fVar2,fVar3,param_3,fVar3 + 1.0,param_5);
  FUN_005dda30(param_3 - 1.0,fVar3,param_3,param_4,param_5);
  FUN_005dda30(fVar2,param_4 - 1.0,param_3,param_4,param_5);
  FUN_005dda30(fVar2,fVar3,fVar2 + 1.0,param_4,param_5);
  return;
}



================================================================