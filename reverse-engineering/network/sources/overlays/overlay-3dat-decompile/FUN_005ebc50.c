FUNCTION FUN_005ebc50 @ 0x005ebc50  size=108
CALLERS (0): 
CALLEES (2): FUN_005ec1b0@0x005ec1b0, FUN_005ec4f0@0x005ec4f0
----------------------------------------------------------------

undefined8 FUN_005ebc50(undefined8 param_1)

{
  undefined4 uVar1;
  char acStack_110 [272];
  
  FUN_005ec1b0(param_1,acStack_110,0x100);
  if ((*(char *)(iRam007012a0 + 0x186) == -10) && (acStack_110[0] != '\0')) {
    uVar1 = FUN_005ec4f0(acStack_110);
    *(undefined4 *)(iRam007012a0 + 0xf18) = uVar1;
  }
  return 0;
}



================================================================