FUNCTION FUN_005c0d30 @ 0x005c0d30  size=132
CALLERS (3): FUN_00600de0@0x00600de0, FUN_005fa190@0x005fa190, FUN_0062f1e0@0x0062f1e0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c0d30(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xffff) * 0x118;
  func_0x00109eb8(param_2,iVar1 + 0x6cdbe6);
  func_0x00109eb8(param_3,iVar1 + 0x6cdbf6);
  func_0x001069a8(param_4,iVar1 + 0x6cdc0a,0xf0);
  return 0;
}



================================================================