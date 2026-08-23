FUNCTION FUN_00622c30 @ 0x00622c30  size=304
CALLERS (1): FUN_00622180@0x00622180
CALLEES (4): FUN_0061ea10@0x0061ea10, FUN_0061f8b0@0x0061f8b0, FUN_0061ea20@0x0061ea20, FUN_0061f970@0x0061f970
----------------------------------------------------------------

undefined4 FUN_00622c30(void)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  cVar1 = *(char *)(iRam00715298 + 1);
  if (cVar1 == '\x02') {
    *(undefined1 *)(iRam00715298 + 2) = 0;
    *(undefined1 *)(iRam00715298 + 3) = 0;
    *(undefined1 *)(iRam00715298 + 0x12) = 0;
    *(undefined1 *)(iRam00715298 + 0x28) = 0;
    *(undefined1 *)(iRam00715298 + 0x15) = 0;
    *(undefined1 *)(iRam00715298 + 0xc) = 0;
    *(undefined1 *)(iRam00715298 + 0xc) = 0;
    uRam007152a0 = 0;
    if (*(char *)(iRam00715298 + 0x88) == '\0') {
      func_0x00106b60(iRam00715298 + 0x88,0,0x80);
      func_0x00109728(iRam00715298 + 0x88,0x66a830);
    }
    FUN_0061ea10();
    FUN_0061ea20(0);
    FUN_0061f8b0();
    uVar2 = 1;
  }
  else {
    if (cVar1 == '\x01') {
      lVar3 = FUN_0061f970();
      if (lVar3 != 0) {
        *(char *)(iRam00715298 + 1) = *(char *)(iRam00715298 + 1) + '\x01';
      }
    }
    else {
      if (cVar1 != '\0') {
        return 0;
      }
      *(undefined1 *)(iRam00715298 + 1) = 1;
      *(undefined1 *)(iRam00715298 + 0x11) = 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



================================================================