FUNCTION FUN_005e9b70 @ 0x005e9b70  size=92
CALLERS (0): 
CALLEES (2): FUN_005ec650@0x005ec650, FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005e9b70(undefined8 param_1)

{
  undefined2 uVar1;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  uVar1 = FUN_005ec650(auStack_110);
  *(undefined2 *)(iRam007012a0 + 0x8f2) = uVar1;
  if (*(ushort *)(iRam007012a0 + 0x8f2) < 4) {
    *(undefined2 *)(iRam007012a0 + 0x8f2) = 4;
  }
  return 0;
}



================================================================