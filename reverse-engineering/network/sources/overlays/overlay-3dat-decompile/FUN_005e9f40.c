FUNCTION FUN_005e9f40 @ 0x005e9f40  size=52
CALLERS (0): 
CALLEES (1): FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005e9f40(undefined8 param_1)

{
  if (*(char *)(iRam007012a0 + 0x1120) != '\0') {
    FUN_005ec1b0(param_1,iRam007012a0 + 0x1128,0x100);
  }
  return 0;
}



================================================================