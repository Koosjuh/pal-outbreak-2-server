FUNCTION FUN_005d8a70 @ 0x005d8a70  size=48
CALLERS (1): FUN_005ef3f0@0x005ef3f0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d8a70(uint param_1)

{
  if (*(char *)(iRam00701070 + 0x34) == '\0') {
    *(uint *)(iRam00701070 + 0x14) = param_1 | 0xff000000;
  }
  else {
    *(undefined4 *)(iRam00701070 + 0x14) = 0xff000000;
  }
  return;
}



================================================================