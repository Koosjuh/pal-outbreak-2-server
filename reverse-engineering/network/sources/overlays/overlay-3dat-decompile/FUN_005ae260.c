FUNCTION FUN_005ae260 @ 0x005ae260  size=96
CALLERS (1): FUN_005ae130@0x005ae130
CALLEES (3): FUN_005de2a0@0x005de2a0, FUN_005af2f0@0x005af2f0, FUN_005c80a0@0x005c80a0
----------------------------------------------------------------

undefined8 FUN_005ae260(int param_1)

{
  *(char *)(param_1 + 0x993) = *(char *)(param_1 + 0x993) + '\x01';
  uRam00701f20 = 0;
  func_0x00112b20(0);
  FUN_005de2a0(iRam003435bc + 0x2ff000);
  FUN_005c80a0(1);
  FUN_005af2f0(0,10);
  return 0;
}



================================================================