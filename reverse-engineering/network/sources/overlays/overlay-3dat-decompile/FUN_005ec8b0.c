FUNCTION FUN_005ec8b0 @ 0x005ec8b0  size=108
CALLERS (1): FUN_005eea60@0x005eea60
CALLEES (0): 
----------------------------------------------------------------

byte * FUN_005ec8b0(byte *param_1)

{
  if ((*(char *)(iRam007012a0 + 0xd8cc) == '\0') && (*(char *)(iRam007012a0 + 0x18b) == '\0')) {
    while ((*param_1 != 0 && (((&DAT_006491b0)[*param_1] & 2) != 0))) {
      param_1 = param_1 + 1;
    }
  }
  return param_1;
}



================================================================