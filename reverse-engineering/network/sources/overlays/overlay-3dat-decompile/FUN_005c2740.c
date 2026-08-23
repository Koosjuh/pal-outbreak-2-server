FUNCTION FUN_005c2740 @ 0x005c2740  size=132
CALLERS (1): FUN_00601580@0x00601580
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c2740(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xffff) * 0x118;
  func_0x00109eb8(param_2,iVar1 + 0x6ce046);
  func_0x00109eb8(param_3,iVar1 + 0x6ce056);
  func_0x001069a8(param_4,iVar1 + 0x6ce06a,0xf0);
  return 0;
}



================================================================