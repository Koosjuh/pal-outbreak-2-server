FUNCTION FUN_005e9bd0 @ 0x005e9bd0  size=96
CALLERS (0): 
CALLEES (2): FUN_005ec1b0@0x005ec1b0, FUN_005ec6d0@0x005ec6d0
----------------------------------------------------------------

undefined8 FUN_005e9bd0(undefined8 param_1)

{
  undefined2 uVar1;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  uVar1 = FUN_005ec6d0(auStack_110,0);
  *(undefined2 *)(iRam007012a0 + 0x8f4) = uVar1;
  if (*(ushort *)(iRam007012a0 + 0x8f4) < 2) {
    *(undefined2 *)(iRam007012a0 + 0x8f4) = 2;
  }
  return 0;
}



================================================================