FUNCTION FUN_005daba0 @ 0x005daba0  size=648
CALLERS (0): 
CALLEES (4): FUN_005ddb40@0x005ddb40, FUN_005dfee0@0x005dfee0, FUN_005e00e0@0x005e00e0, FUN_005e15e0@0x005e15e0
----------------------------------------------------------------

void FUN_005daba0(undefined8 param_1)

{
  char cVar1;
  byte bVar2;
  undefined8 uVar3;
  ushort uVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  
  if (((int)(*(ushort *)(iRam00701070 + 0x18) & 0x200) >> 9 == 0) &&
     (*(char *)(iRam00701068 + 0x68e7e) != '\x04')) {
    uVar3 = FUN_005e00e0(1);
    FUN_005ddb40(0xffffffffffffffff,uVar3,0,0,0x280,0x1c0,0,0);
  }
  iVar5 = (int)param_1;
  cVar1 = *(char *)(iVar5 + 6);
  if (cVar1 == 'c') {
    FUN_005dfee0(param_1);
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
  }
  else {
    if (cVar1 == '\x01') {
      bVar2 = *(byte *)(iVar5 + 0x5f);
    }
    else {
      if (cVar1 == '\0') {
        return;
      }
      bVar2 = *(byte *)(iVar5 + 0x5f);
    }
    if (*(int *)((uint)bVar2 * 4 + iRam00701068 + 0x68dd8) != 0) {
      uVar4 = 0;
      if (*(char *)(iVar5 + 0x5d) == '\0') {
        fVar7 = (float)((int)*(short *)(iRam00701070 + 0x1a) -
                       (int)*(short *)(iRam00701070 + 8) %
                       (int)(short)(int)(*(float *)(iVar5 + 0x38) + *(float *)(iVar5 + 0x44)));
      }
      else {
        fVar7 = (float)(int)*(short *)(iRam00701070 + 0x1a);
      }
      for (; fVar7 < 448.0; fVar7 = fVar7 + *(float *)(iVar5 + 0x44)) {
        if (*(char *)(iVar5 + 0x5d) == '\0') {
          fVar6 = (float)((int)*(short *)(iRam00701070 + 0x1e) -
                         (int)*(short *)(iRam00701070 + 4) %
                         (int)(short)(int)(*(float *)(iVar5 + 0x34) + *(float *)(iVar5 + 0x40)));
        }
        else {
          fVar6 = (float)(int)*(short *)(iRam00701070 + 0x1e);
        }
        for (; fVar6 < 640.0; fVar6 = fVar6 + *(float *)(iVar5 + 0x40)) {
          if (0x200 < (ushort)(uVar4 + 1)) {
            return;
          }
          FUN_005e15e0(fVar6,fVar7,*(undefined4 *)(iVar5 + 0x40),*(undefined4 *)(iVar5 + 0x44),
                       *(undefined1 *)(iVar5 + 0x5f),0,0);
          uVar4 = uVar4 + 1;
        }
      }
    }
  }
  return;
}



================================================================