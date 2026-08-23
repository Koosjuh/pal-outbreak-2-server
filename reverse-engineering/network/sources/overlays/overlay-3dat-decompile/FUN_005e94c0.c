FUNCTION FUN_005e94c0 @ 0x005e94c0  size=68
CALLERS (0): 
CALLEES (2): FUN_005ec920@0x005ec920, FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005e94c0(undefined8 param_1)

{
  undefined1 uVar1;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  uVar1 = FUN_005ec920(auStack_110,0x6482b0,0x48);
  *(undefined1 *)(iRam007012a0 + 0x4e4) = uVar1;
  return 0;
}



================================================================