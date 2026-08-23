FUNCTION FUN_005ebb50 @ 0x005ebb50  size=120
CALLERS (0): 
CALLEES (2): FUN_005ec650@0x005ec650, FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005ebb50(undefined8 param_1)

{
  undefined1 uVar1;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    uVar1 = FUN_005ec650(auStack_110);
    *(undefined1 *)(iRam007012a0 + 0xf14) = uVar1;
    if (*(char *)(iRam007012a0 + 0xf14) == '\x01') {
      *(undefined1 *)(iRam007012a0 + 0xf14) = 0;
    }
  }
  return 0;
}



================================================================