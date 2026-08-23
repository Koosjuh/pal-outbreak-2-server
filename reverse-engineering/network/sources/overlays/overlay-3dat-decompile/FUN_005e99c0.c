FUNCTION FUN_005e99c0 @ 0x005e99c0  size=60
CALLERS (0): 
CALLEES (2): FUN_005ecf20@0x005ecf20, FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005e99c0(undefined8 param_1)

{
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  *(undefined1 *)(iRam007012a0 + 0x17f) = 3;
  FUN_005ecf20(auStack_110);
  return 0;
}



================================================================