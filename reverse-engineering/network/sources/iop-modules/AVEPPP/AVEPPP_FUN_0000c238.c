FUNCTION FUN_0000c238 @ 0x0000c238 size=48
CALLERS (1): FUN_0000d5a8@0x0000d5a8
CALLEES (0): 

undefined4 FUN_0000c238(int param_1,short param_2)

{
  if ((ushort)(param_2 - 0x80U) < 0xf81) {
    *(short *)(param_1 + 6) = param_2;
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | 2;
    return 0;
  }
  return 0xffffffff;
}


================================================================