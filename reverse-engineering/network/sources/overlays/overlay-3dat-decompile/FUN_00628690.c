FUNCTION FUN_00628690 @ 0x00628690  size=124
CALLERS (1): FUN_00627d60@0x00627d60
CALLEES (1): FUN_0062b9e0@0x0062b9e0
----------------------------------------------------------------

undefined4 FUN_00628690(int param_1,undefined1 *param_2)

{
  *(undefined1 *)(param_1 + 0x443) = 1;
  *param_2 = 5;
  param_2[1] = 0;
  FUN_0062b9e0();
  func_0x0010a4f0(param_1 + 0x1045,param_1 + 0xefb,0x10);
  func_0x0010a4f0(param_1 + 0x1055,param_1 + 0xf0b,0x10);
  func_0x00106b60(param_1 + 0x1069,0,0x25);
  func_0x00106b60(param_1 + 0x108e,0,0x25);
  return 0xffffffff;
}



================================================================