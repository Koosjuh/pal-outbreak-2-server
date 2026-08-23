FUNCTION FUN_005eb3a0 @ 0x005eb3a0  size=76
CALLERS (0): 
CALLEES (2): FUN_005ec1b0@0x005ec1b0, FUN_005ec4f0@0x005ec4f0
----------------------------------------------------------------

undefined8 FUN_005eb3a0(undefined8 param_1)

{
  undefined4 uVar1;
  char acStack_110 [272];
  
  FUN_005ec1b0(param_1,acStack_110,0x100);
  if (acStack_110[0] != '\0') {
    uVar1 = FUN_005ec4f0(acStack_110);
    *(undefined4 *)(iRam007012a0 + 0xf18) = uVar1;
  }
  return 0;
}



================================================================