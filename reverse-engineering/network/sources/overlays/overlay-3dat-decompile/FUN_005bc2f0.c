FUNCTION FUN_005bc2f0 @ 0x005bc2f0  size=72
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (2): FUN_005c7e30@0x005c7e30, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bc2f0(void)

{
  if (cRam006ff2b1 != '\0') {
    func_0x00106b60(0x6fc5e8,0,0x300);
    FUN_005c7e30(6);
    FUN_005bdf90(0xb,0);
  }
  return;
}



================================================================
FUNCTION thunk_FUN_005c61b0 @ 0x005bc340  size=8
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (0): 
----------------------------------------------------------------

void thunk_FUN_005c61b0(undefined8 param_1)

{
  undefined1 auStack_310 [784];
  
  func_0x00106b60(auStack_310,0,0x304);
  auStack_310[0] = 0xf;
  func_0x001df380(uRam006febac,0x8000,auStack_310,4,1,param_1);
  return;
}



================================================================