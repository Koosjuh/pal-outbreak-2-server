FUNCTION FUN_005d9e30 @ 0x005d9e30  size=104
CALLERS (1): FUN_005e67a0@0x005e67a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d9e30(undefined1 param_1)

{
  switch(param_1) {
  default:
    *(undefined1 *)(iRam00701070 + 0x34) = 0;
    break;
  case 1:
  case 2:
  case 4:
  case 5:
    *(undefined1 *)(iRam00701070 + 0x34) = 1;
  }
  *(undefined1 *)(iRam00701070 + 0x2f) = *(undefined1 *)(iRam00701070 + 0x30);
  *(undefined1 *)(iRam00701070 + 0x30) = param_1;
  return;
}



================================================================