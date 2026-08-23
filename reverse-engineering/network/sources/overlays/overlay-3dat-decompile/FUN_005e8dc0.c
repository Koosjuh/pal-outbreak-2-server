FUNCTION FUN_005e8dc0 @ 0x005e8dc0  size=56
CALLERS (0): 
CALLEES (2): FUN_005ec650@0x005ec650, FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005e8dc0(undefined8 param_1)

{
  undefined2 uVar1;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  uVar1 = FUN_005ec650(auStack_110);
  *(undefined2 *)(iRam007012a0 + 0xdf6) = uVar1;
  return 0;
}



================================================================