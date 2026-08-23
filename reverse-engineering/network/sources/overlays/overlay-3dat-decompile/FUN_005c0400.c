FUNCTION FUN_005c0400 @ 0x005c0400  size=108
CALLERS (2): FUN_005f91f0@0x005f91f0, FUN_0062de90@0x0062de90
CALLEES (2): FUN_005bf180@0x005bf180, FUN_005bf0e0@0x005bf0e0
----------------------------------------------------------------

undefined8 FUN_005c0400(undefined8 param_1,code *param_2)

{
  undefined1 auStack_10 [16];
  
  FUN_005bf0e0(2,param_1);
  FUN_005bf180(2);
  uRam006ff2b0 = 1;
  func_0x00106b60(0x7006d0,0,0x20);
  auStack_10[0] = 0;
  (*param_2)(auStack_10,auStack_10);
  return 0;
}



================================================================