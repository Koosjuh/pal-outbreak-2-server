FUNCTION FUN_005d8840 @ 0x005d8840  size=232
CALLERS (1): FUN_005ca1a0@0x005ca1a0
CALLEES (3): FUN_005d67d0@0x005d67d0, FUN_005d68e0@0x005d68e0, FUN_005d6810@0x005d6810
----------------------------------------------------------------

void FUN_005d8840(void)

{
  switch(uRam00701000) {
  case 1:
  case 2:
    uRam00701018 = FUN_005d6810(iRam00701068 + 0x4f588,uRam00701018);
    uRam00701018 = FUN_005d68e0(iRam00701068 + 0x4f588,uRam00701018);
    break;
  case 3:
    uRam00701018 = FUN_005d6810(iRam00701068 + 0x4f588,uRam00701018);
    break;
  case 4:
    uRam00701018 = FUN_005d67d0(iRam00701068 + 0x4f588,uRam00701018);
  }
  return;
}



================================================================