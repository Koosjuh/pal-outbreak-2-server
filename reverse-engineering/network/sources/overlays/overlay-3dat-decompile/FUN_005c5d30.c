FUNCTION FUN_005c5d30 @ 0x005c5d30  size=116
CALLERS (1): FUN_005c6500@0x005c6500
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c5d30(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_310 [4];
  undefined1 auStack_30c [780];
  
  func_0x00106b60(auStack_310,0,0x304);
  auStack_310[0] = 5;
  func_0x001069a8(auStack_30c,param_2,2);
  func_0x001df380(uRam006febac,0x8000,auStack_310,6,1,param_1);
  return;
}



================================================================