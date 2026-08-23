FUNCTION FUN_005e97d0 @ 0x005e97d0  size=100
CALLERS (0): 
CALLEES (1): FUN_005e9790@0x005e9790
----------------------------------------------------------------

undefined8 FUN_005e97d0(undefined8 param_1,undefined8 param_2)

{
  FUN_005e9790(param_2);
  *(undefined1 *)(iRam007012a0 + 0x7f0) = 1;
  func_0x00106b60(iRam007012a0 + 0x7f1,0,0x101);
  *(undefined4 *)(iRam007012a0 + 4) = 0;
  *(undefined1 *)param_2 = 0;
  return 0;
}



================================================================