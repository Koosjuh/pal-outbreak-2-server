FUNCTION FUN_005da500 @ 0x005da500  size=336
CALLERS (1): FUN_005e7e30@0x005e7e30
CALLEES (1): FUN_005da4b0@0x005da4b0
----------------------------------------------------------------

void FUN_005da500(undefined1 param_1)

{
  long lVar1;
  
  *(undefined1 *)(iRam00701070 + 0x35) = param_1;
  switch(param_1) {
  case 0:
    *(undefined1 *)(iRam00701070 + 0x33) = 1;
    break;
  case 1:
    *(undefined1 *)(iRam00701070 + 0x31) = 1;
    if (*(char *)(iRam00701070 + 0x33) != '\0') {
      lVar1 = func_0x00109d70(iRam00701070 + 0x57f,iRam00701070 + 0x55d);
      if (lVar1 != 0) {
        FUN_005da4b0(4,1);
        return;
      }
      *(undefined1 *)(iRam00701070 + 0x33) = 0;
    }
    break;
  case 3:
    *(undefined1 *)(iRam00701070 + 0x31) = 1;
    FUN_005da4b0(4);
    *(undefined1 *)(iRam00701070 + 0x33) = 0;
    break;
  case 4:
    *(undefined1 *)(iRam00701070 + 0x33) = 1;
    break;
  case 5:
    FUN_005da4b0(4,1);
    *(undefined1 *)(iRam00701070 + 0x33) = 0;
    break;
  case 6:
    if ((*(char *)(iRam00701070 + 0x57f) != '\0') && (*(char *)(iRam00701070 + 0x33) != '\0')) {
      *(undefined1 *)(iRam00701070 + 0x33) = 0;
      FUN_005da4b0(5,2);
    }
    break;
  case 8:
    FUN_005da4b0(6,1);
  }
  return;
}



================================================================