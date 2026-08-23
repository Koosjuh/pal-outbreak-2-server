FUNCTION FUN_005ee9f0 @ 0x005ee9f0  size=112
CALLERS (2): FUN_005eea60@0x005eea60, FUN_005f3420@0x005f3420
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ee9f0(undefined4 *param_1,int param_2)

{
  if (*(char *)*param_1 == '\t') {
    *(undefined1 *)(*(int *)(iRam007012a0 + 0x1c) + iRam007012a0 + 0x20) = 0x20;
  }
  else {
    *(char *)(*(int *)(iRam007012a0 + 0x1c) + iRam007012a0 + 0x20) = *(char *)*param_1;
  }
  *(int *)(iRam007012a0 + 0x1c) = *(int *)(iRam007012a0 + 0x1c) + 1;
  *(ushort *)(param_2 + 4) = *(short *)(param_2 + 4) + (ushort)*(byte *)(iRam007012a0 + 0x181);
  return;
}



================================================================