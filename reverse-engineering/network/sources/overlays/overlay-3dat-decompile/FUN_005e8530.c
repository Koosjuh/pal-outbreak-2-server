FUNCTION FUN_005e8530 @ 0x005e8530  size=80
CALLERS (0): 
CALLEES (2): FUN_005ec1b0@0x005ec1b0, FUN_005d8aa0@0x005d8aa0
----------------------------------------------------------------

undefined8 FUN_005e8530(undefined8 param_1)

{
  undefined1 auStack_100 [256];
  
  FUN_005ec1b0(param_1,auStack_100,0x100);
  if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
    FUN_005d8aa0(auStack_100);
  }
  return 0;
}



================================================================