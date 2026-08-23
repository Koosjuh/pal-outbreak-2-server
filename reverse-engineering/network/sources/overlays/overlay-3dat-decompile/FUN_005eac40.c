FUNCTION FUN_005eac40 @ 0x005eac40  size=88
CALLERS (0): 
CALLEES (2): FUN_005ec1b0@0x005ec1b0, FUN_005ec4f0@0x005ec4f0
----------------------------------------------------------------

undefined8 FUN_005eac40(undefined8 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    uVar1 = FUN_005ec4f0(auStack_110);
    *(undefined4 *)(iRam007012a0 + 0xe08) = uVar1;
  }
  return 0;
}



================================================================