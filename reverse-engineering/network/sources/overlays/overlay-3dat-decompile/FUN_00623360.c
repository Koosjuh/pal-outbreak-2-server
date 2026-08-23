FUNCTION FUN_00623360 @ 0x00623360  size=120
CALLERS (1): FUN_00622180@0x00622180
CALLEES (0): 
----------------------------------------------------------------

char FUN_00623360(void)

{
  if (cRam003c98a0 == '\x02') {
    *(undefined1 *)(iRam00715298 + 0x12) = 1;
    *(undefined1 *)(iRam00715298 + 0xc) = 0;
    *(undefined1 *)(iRam00715298 + 0xc) = 0;
  }
  else {
    *(undefined1 *)(iRam00715298 + 0xc) = 1;
    *(undefined1 *)(iRam00715298 + 0xc) = 1;
  }
  *(undefined1 *)(iRam00715298 + 0x10) = 1;
  return cRam003c98a0;
}



================================================================