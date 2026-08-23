FUNCTION FUN_005f23c0 @ 0x005f23c0  size=144
CALLERS (1): FUN_005f3420@0x005f3420
CALLEES (0): 
----------------------------------------------------------------

byte * FUN_005f23c0(byte *param_1)

{
  if ((*(char *)(iRam007012a0 + 0xd8de) == '\0') &&
     ((*(byte *)(((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
                 (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0 + 0x2530) & 1) == 0))
  {
    while ((*param_1 != 0 && (((&DAT_006494f0)[*param_1] & 2) != 0))) {
      param_1 = param_1 + 1;
    }
  }
  return param_1;
}



================================================================