FUNCTION FUN_005cf680 @ 0x005cf680  size=608
CALLERS (1): FUN_005cfb20@0x005cfb20
CALLEES (1): FUN_0061e720@0x0061e720
----------------------------------------------------------------

void FUN_005cf680(void)

{
  byte bVar1;
  
  *(short *)(iRam00701078 + 0x10) =
       (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0)
                               + 0x34) - (float)*(int *)(iRam00701070 + 4)) + 10.0);
  if (*(char *)(iRam00701078 + 6) == '\0') {
    bVar1 = *(byte *)(iRam00701078 + 4);
    if (bVar1 < 0xb) {
      if ((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) + 0x38) -
          (float)*(int *)(iRam00701070 + 8)) + 20.0 + (float)(int)((bVar1 - 1) * 0x12) <=
          (float)(int)*(short *)(iRam00701078 + 0x12)) {
        return;
      }
      *(short *)(iRam00701078 + 0x12) = *(short *)(iRam00701078 + 0x12) + 0x12;
    }
    else if ((float)(int)*(short *)(iRam00701078 + 0x12) <
             (*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) + 0x38
                        ) - (float)*(int *)(iRam00701070 + 8)) + 20.0 + 162.0) {
      *(short *)(iRam00701078 + 0x12) = *(short *)(iRam00701078 + 0x12) + 0x12;
    }
    else {
      if ((int)(bVar1 - 10) < (int)(uint)*(byte *)(iRam00701078 + 5)) {
        return;
      }
      *(byte *)(iRam00701078 + 5) = *(byte *)(iRam00701078 + 5) + 1;
    }
  }
  else if ((float)(int)*(short *)(iRam00701078 + 0x12) <=
           (*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) + 0x38)
           - (float)*(int *)(iRam00701070 + 8)) - 18.0) {
    *(short *)(iRam00701078 + 0x12) = *(short *)(iRam00701078 + 0x12) + 0x12;
  }
  else {
    if (*(byte *)(iRam00701078 + 4) < 0xb) {
      return;
    }
    if ((int)(*(byte *)(iRam00701078 + 4) - 10) < (int)(uint)*(byte *)(iRam00701078 + 5)) {
      return;
    }
    *(byte *)(iRam00701078 + 5) = *(byte *)(iRam00701078 + 5) + 1;
  }
  FUN_0061e720();
  return;
}



================================================================