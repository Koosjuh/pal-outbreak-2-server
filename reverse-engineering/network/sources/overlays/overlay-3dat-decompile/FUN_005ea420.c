FUNCTION FUN_005ea420 @ 0x005ea420  size=116
CALLERS (0): 
CALLEES (3): FUN_005ef220@0x005ef220, FUN_005eef70@0x005eef70, FUN_005ef200@0x005ef200
----------------------------------------------------------------

undefined8 FUN_005ea420(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  
  FUN_005ef200();
  FUN_005eef70(param_2);
  bVar1 = *(byte *)(*(short *)(iRam007012a0 + 0x124) + iRam007012a0 + 0x168);
  if (1 < bVar1) {
    bVar1 = bVar1 - 1;
  }
  *(byte *)(iRam007012a0 + 0x2d3) = bVar1 + 0x30;
  *(undefined1 *)(iRam007012a0 + 0x2d4) = 0;
  FUN_005ef220();
  return 0;
}



================================================================