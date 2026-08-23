FUNCTION FUN_005e9ef0 @ 0x005e9ef0  size=72
CALLERS (0): 
CALLEES (2): FUN_005ec650@0x005ec650, FUN_005ec430@0x005ec430
----------------------------------------------------------------

undefined8 FUN_005e9ef0(undefined8 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_110 [272];
  
  if (*(char *)(iRam007012a0 + 0x1120) != '\0') {
    FUN_005ec430(param_1,auStack_110,0x100);
    uVar1 = FUN_005ec650(auStack_110);
    *(undefined4 *)(iRam007012a0 + 0x1124) = uVar1;
  }
  return 0;
}



================================================================