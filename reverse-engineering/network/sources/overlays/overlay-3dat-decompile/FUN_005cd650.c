FUNCTION FUN_005cd650 @ 0x005cd650  size=180
CALLERS (0): 
CALLEES (2): FUN_005e0050@0x005e0050, FUN_005dfcf0@0x005dfcf0
----------------------------------------------------------------

void FUN_005cd650(void)

{
  FUN_005e0050();
  if (cRam00701e10 != '\0') {
    cRam00701e10 = '\x03';
  }
  FUN_005dfcf0();
  if (*(char *)(iRam00701070 + 0x2e) == '\x05') {
    *(undefined1 *)(iRam00701070 + 1) = 2;
    *(undefined1 *)(iRam00701070 + 2) = 0;
  }
  else if (*(char *)(iRam00701070 + 0x2e) == '\0') {
    *(undefined4 *)(iRam00701068 + 0x6901c) = 3;
    *(undefined1 *)(iRam00701070 + 1) = 2;
    *(undefined1 *)(iRam00701070 + 2) = 0;
  }
  uRam00700fe0 = 1;
  return;
}



================================================================