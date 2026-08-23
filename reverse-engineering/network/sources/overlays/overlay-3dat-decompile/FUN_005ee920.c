FUNCTION FUN_005ee920 @ 0x005ee920  size=128
CALLERS (2): FUN_005eea60@0x005eea60, FUN_005f3420@0x005f3420
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ee920(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)*param_1;
  do {
    uVar1 = uVar2 << 1;
    uVar2 = uVar1 & 0xff;
    *(undefined1 *)(iRam007012a0 + *(int *)(iRam007012a0 + 0x1c) + 0x20) = *(undefined1 *)*param_1;
    *(int *)(iRam007012a0 + 0x1c) = *(int *)(iRam007012a0 + 0x1c) + 1;
    *param_1 = *param_1 + 1;
  } while ((uVar1 & 0x80) != 0);
  *param_1 = *param_1 + -1;
  *(ushort *)(param_2 + 4) = *(short *)(param_2 + 4) + (ushort)*(byte *)(iRam007012a0 + 0x181);
  return;
}



================================================================