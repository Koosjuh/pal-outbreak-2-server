FUNCTION FUN_00623090 @ 0x00623090  size=288
CALLERS (1): FUN_00622180@0x00622180
CALLEES (5): FUN_0061ea10@0x0061ea10, thunk_FUN_0061f0d0@0x0061ea00, FUN_0060f910@0x0060f910, FUN_0061e940@0x0061e940, FUN_0060f8d0@0x0060f8d0
----------------------------------------------------------------

undefined4 FUN_00623090(void)

{
  char cVar1;
  long lVar2;
  undefined4 uVar3;
  
  cVar1 = *(char *)(iRam00715298 + 1);
  uVar3 = 0;
  if (cVar1 == '\x04') {
    uVar3 = 0xffffffff;
  }
  else if (cVar1 == '\x03') {
    uVar3 = 1;
  }
  else if (cVar1 == '\x02') {
    lVar2 = FUN_0060f910();
    if (lVar2 == -1) {
      *(undefined1 *)(iRam00715298 + 1) = 4;
    }
    else {
      if (lVar2 != 1) {
        if (lVar2 != 2) {
          return 0;
        }
        *(undefined1 *)(iRam00715298 + 0x28) = 1;
      }
      *(undefined1 *)(iRam00715298 + 1) = 3;
    }
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)(iRam00715298 + 1) = 2;
    FUN_0060f8d0(*(undefined1 *)(iRam00715298 + 0x10));
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iRam00715298 + 1) = 1;
    thunk_FUN_0061f0d0(0);
    FUN_0061ea10();
    FUN_0061e940();
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



================================================================