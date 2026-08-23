FUNCTION FUN_005e9ea0 @ 0x005e9ea0  size=76
CALLERS (0): 
CALLEES (1): FUN_005ec320@0x005ec320
----------------------------------------------------------------

undefined8 FUN_005e9ea0(undefined8 param_1)

{
  long lVar1;
  undefined1 auStack_110 [272];
  
  FUN_005ec320(param_1,auStack_110,0x100);
  lVar1 = func_0x0010a338(auStack_110,0x648528,7);
  if (lVar1 == 0) {
    *(undefined1 *)(iRam007012a0 + 0x1120) = 1;
  }
  return 0;
}



================================================================