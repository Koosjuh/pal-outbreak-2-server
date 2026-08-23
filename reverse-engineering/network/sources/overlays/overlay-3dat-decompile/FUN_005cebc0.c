FUNCTION FUN_005cebc0 @ 0x005cebc0  size=1100
CALLERS (1): FUN_005cf3a0@0x005cf3a0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005cebc0(ushort param_1,char param_2)

{
  int iVar1;
  float fVar2;
  
  if (param_2 == '\0') {
    iVar1 = *(int *)((uint)param_1 * 4 + iRam00701068 + 0x5ffc0);
    if ((float)(0x19c - *(short *)(iRam00701070 + 0x1c)) < *(float *)(iVar1 + 0x38)) {
      *(undefined2 *)(iRam00701068 + 0x68e78) = 0;
      return 0;
    }
    if ((float)(0x270 - *(short *)(iRam00701070 + 0x20)) < *(float *)(iVar1 + 0x34)) {
      *(undefined2 *)(iRam00701068 + 0x68e78) = 0;
      return 0;
    }
  }
  iVar1 = (uint)param_1 * 4;
  *(short *)(iRam00701078 + 0x12) =
       (short)(int)((*(float *)(*(int *)(iVar1 + iRam00701068 + 0x5ffc0) + 0x38) -
                    (float)*(int *)(iRam00701070 + 8)) + 10.0);
  if (0x17c < *(short *)(iRam00701078 + 0x12)) {
    *(undefined2 *)(iRam00701078 + 0x12) = 0x17c;
    *(int *)(iRam00701070 + 8) =
         (int)((float)*(int *)(iRam00701070 + 8) +
              (*(float *)(*(int *)(iVar1 + iRam00701068 + 0x5ffc0) + 0x38) -
              (float)(*(int *)(iRam00701070 + 8) + 0x17c)) + 10.0);
  }
  if (*(short *)(iRam00701078 + 0x12) < *(short *)(iRam00701070 + 0x1a)) {
    *(short *)(iRam00701078 + 0x12) = *(short *)(iRam00701070 + 0x1a) + 10;
    *(int *)(iRam00701070 + 8) =
         (int)((float)*(int *)(iRam00701070 + 8) -
              (((float)*(int *)(iRam00701070 + 8) -
               *(float *)(*(int *)(iVar1 + iRam00701068 + 0x5ffc0) + 0x38)) + 10.0));
    fVar2 = *(float *)(*(int *)(iVar1 + iRam00701068 + 0x5ffc0) + 0x38) -
            (float)*(int *)(iRam00701070 + 8);
    if (fVar2 < (float)(int)*(short *)(iRam00701070 + 0x1a)) {
      *(int *)(iRam00701070 + 8) =
           (int)((float)*(int *)(iRam00701070 + 8) -
                ((float)(int)*(short *)(iRam00701070 + 0x1a) - fVar2));
    }
  }
  *(short *)(iRam00701078 + 0x10) =
       (short)(int)((*(float *)(*(int *)(iVar1 + iRam00701068 + 0x5ffc0) + 0x34) -
                    (float)*(int *)(iRam00701070 + 4)) + 10.0);
  if (0x248 < *(short *)(iRam00701078 + 0x10)) {
    *(undefined2 *)(iRam00701078 + 0x10) = 0x248;
    *(int *)(iRam00701070 + 4) =
         (int)((float)*(int *)(iRam00701070 + 4) +
              (*(float *)(*(int *)(iVar1 + iRam00701068 + 0x5ffc0) + 0x34) -
              (float)(*(int *)(iRam00701070 + 4) + 0x248)) + 10.0);
  }
  if (*(short *)(iRam00701078 + 0x10) < *(short *)(iRam00701070 + 0x1a)) {
    *(short *)(iRam00701078 + 0x10) = *(short *)(iRam00701070 + 0x1a) + 10;
    *(int *)(iRam00701070 + 4) =
         (int)((float)*(int *)(iRam00701070 + 4) -
              (((float)*(int *)(iRam00701070 + 4) -
               *(float *)(*(int *)(iVar1 + iRam00701068 + 0x5ffc0) + 0x34)) + 10.0));
    fVar2 = *(float *)(*(int *)(iVar1 + iRam00701068 + 0x5ffc0) + 0x34) -
            (float)*(int *)(iRam00701070 + 4);
    if (fVar2 < (float)(int)*(short *)(iRam00701070 + 0x1e)) {
      *(int *)(iRam00701070 + 4) =
           (int)((float)*(int *)(iRam00701070 + 4) -
                ((float)(int)*(short *)(iRam00701070 + 0x1e) - fVar2));
    }
  }
  *(ushort *)(iRam00701068 + 0x68e78) = param_1;
  return 1;
}



================================================================