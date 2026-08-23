FUNCTION FUN_005e9940 @ 0x005e9940  size=128
CALLERS (0): 
CALLEES (1): FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005e9940(undefined8 param_1)

{
  char acStack_110 [272];
  
  FUN_005ec1b0(param_1,acStack_110,0x100);
  if (acStack_110[0] == '#') {
    *(undefined1 *)(iRam007012a0 + 0x17f) = 1;
    func_0x00109eb8(iRam007012a0 + 0x8f6,acStack_110);
  }
  else {
    *(undefined1 *)(iRam007012a0 + 0x17f) = 2;
    func_0x00109eb8(iRam007012a0 + 0x9f6,acStack_110);
  }
  return 0;
}



================================================================