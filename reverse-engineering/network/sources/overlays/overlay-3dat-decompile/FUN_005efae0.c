FUNCTION FUN_005efae0 @ 0x005efae0  size=72
CALLERS (2): FUN_005f21f0@0x005f21f0, FUN_005f2280@0x005f2280
CALLEES (0): 
----------------------------------------------------------------

int FUN_005efae0(void)

{
  char cVar1;
  
  cVar1 = *(char *)(iRam007012a0 + 0xe96a);
  if (cVar1 != '\0') {
    *(char *)(iRam007012a0 + 0xe96a) = cVar1 + -1;
  }
  return iRam007012a0 + (uint)*(byte *)(iRam007012a0 + 0xe96a) * 0x100 + 0xd96a;
}



================================================================