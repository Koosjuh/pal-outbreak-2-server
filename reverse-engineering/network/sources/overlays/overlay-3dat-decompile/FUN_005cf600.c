FUNCTION FUN_005cf600 @ 0x005cf600  size=120
CALLERS (2): FUN_005cfb20@0x005cfb20, FUN_005d1e80@0x005d1e80
CALLEES (1): FUN_0061e740@0x0061e740
----------------------------------------------------------------

void FUN_005cf600(void)

{
  *(short *)(iRam00701078 + 0x12) =
       (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0)
                               + 0x38) - (float)*(int *)(iRam00701070 + 8)) + 10.0);
  *(undefined1 *)(iRam00701078 + 4) = 0;
  *(undefined4 *)(iRam00701078 + 0x20) = 0;
  FUN_0061e740();
  return;
}



================================================================