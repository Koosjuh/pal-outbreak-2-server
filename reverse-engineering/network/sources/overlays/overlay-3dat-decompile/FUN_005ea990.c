FUNCTION FUN_005ea990 @ 0x005ea990  size=120
CALLERS (0): 
CALLEES (2): FUN_005ec650@0x005ec650, FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005ea990(undefined8 param_1)

{
  undefined1 uVar1;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    uVar1 = FUN_005ec650(auStack_110);
    *(undefined1 *)(iRam007012a0 + 0xdfc) = uVar1;
    if (*(char *)(iRam007012a0 + 0xdfc) != '\0') {
      *(char *)(iRam007012a0 + 0xdfc) = *(char *)(iRam007012a0 + 0xdfc) + '\x01';
    }
  }
  return 0;
}



================================================================