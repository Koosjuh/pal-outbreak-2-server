FUNCTION FUN_005d6460 @ 0x005d6460  size=172
CALLERS (2): FUN_005c9a00@0x005c9a00, FUN_005c9690@0x005c9690
CALLEES (2): FUN_005d5640@0x005d5640, FUN_005d5ba0@0x005d5ba0
----------------------------------------------------------------

undefined8 FUN_005d6460(void)

{
  char cVar1;
  
  cVar1 = *(char *)(iRam00701068 + 0x60dcc) + '\x01';
  *(char *)(iRam00701068 + 0x60dcc) = cVar1;
  if ((cVar1 != '\x02') && (cVar1 = FUN_005d5640(), cVar1 == '\x01')) {
    return 1;
  }
  *(undefined1 *)(iRam00701070 + 0x30) = 0;
  *(undefined1 *)(iRam00701068 + 0x60dca) = 3;
  FUN_005d5ba0(0);
  *(undefined1 *)(iRam00701078 + 2) = 1;
  return 2;
}



================================================================