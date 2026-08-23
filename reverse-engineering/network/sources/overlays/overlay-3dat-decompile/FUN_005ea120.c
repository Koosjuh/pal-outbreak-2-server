FUNCTION FUN_005ea120 @ 0x005ea120  size=104
CALLERS (0): 
CALLEES (1): FUN_005eef70@0x005eef70
----------------------------------------------------------------

undefined8 FUN_005ea120(undefined8 param_1,undefined8 param_2)

{
  *(undefined1 *)((uint)*(byte *)(iRam007012a0 + 0xe96c) + iRam007012a0 + 0xe96d) = 0;
  *(char *)(iRam007012a0 + 0xe96c) = *(char *)(iRam007012a0 + 0xe96c) + '\x01';
  FUN_005eef70(param_2);
  return 0;
}



================================================================