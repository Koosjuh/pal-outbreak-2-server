FUNCTION FUN_00622f40 @ 0x00622f40  size=336
CALLERS (1): FUN_00622180@0x00622180
CALLEES (5): FUN_0061ea10@0x0061ea10, FUN_00623a40@0x00623a40, FUN_0061f4b0@0x0061f4b0, FUN_0061f0d0@0x0061f0d0, FUN_00623b10@0x00623b10
----------------------------------------------------------------

undefined4 FUN_00622f40(void)

{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  FUN_0061f4b0(0x38);
  if (*(char *)(iRam00715298 + 1) == '\x01') {
    if (*(short *)(iRam00715298 + 6) < 1) {
      if (*(char *)(iRam00715298 + 2) == '\x01') {
        lVar1 = FUN_00623b10();
        if (lVar1 == 0) {
          uVar2 = 0xffffffff;
          if (*(int *)(iRam00715298 + 0x180) == 0) {
            uVar2 = 1;
          }
          *(undefined1 *)(iRam00715298 + 1) = 0;
          *(undefined2 *)(iRam00715298 + 4) = 10;
          FUN_0061ea10();
          FUN_0061f0d0();
        }
      }
      else if (*(char *)(iRam00715298 + 2) == '\0') {
        *(undefined1 *)(iRam00715298 + 2) = 1;
        *(undefined2 *)(iRam00715298 + 8) = 0;
        *(undefined2 *)(iRam00715298 + 10) = 0;
        FUN_00623a40(0);
      }
    }
    else {
      *(short *)(iRam00715298 + 6) = *(short *)(iRam00715298 + 6) + -1;
    }
  }
  else if (*(char *)(iRam00715298 + 1) == '\0') {
    if (*(short *)(iRam00715298 + 4) == 0) {
      *(undefined1 *)(iRam00715298 + 1) = 1;
      *(undefined1 *)(iRam00715298 + 2) = 0;
      *(undefined2 *)(iRam00715298 + 6) = 10;
    }
    else {
      *(short *)(iRam00715298 + 4) = *(short *)(iRam00715298 + 4) + -1;
    }
  }
  FUN_0061f4b0(*(undefined1 *)(iRam00715298 + 0x16c));
  return uVar2;
}



================================================================