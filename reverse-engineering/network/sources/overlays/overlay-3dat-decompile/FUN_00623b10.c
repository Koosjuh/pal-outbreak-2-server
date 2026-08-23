FUNCTION FUN_00623b10 @ 0x00623b10  size=196
CALLERS (1): FUN_00622f40@0x00622f40
CALLEES (1): FUN_00623be0@0x00623be0
----------------------------------------------------------------

undefined4 FUN_00623b10(void)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  cVar1 = *(char *)(iRam00715298 + 0x160);
  if (cVar1 == '\x02') {
    uVar2 = 0;
  }
  else {
    if (cVar1 == '\x01') {
      lVar3 = FUN_00623be0();
      if (lVar3 == 0) {
        return 0;
      }
    }
    else if (cVar1 == '\0') {
      if ((*(int *)(iRam00715298 + 0x168) == 1) || (*(int *)(iRam00715298 + 0x168) != 0)) {
        return 0;
      }
      *(undefined1 *)(iRam00715298 + 0x160) = 1;
      uVar2 = func_0x001bcba0(*(undefined4 *)(iRam00715298 + 0x178));
      *(undefined4 *)(iRam00715298 + 0x17c) = uVar2;
    }
    func_0x001f4630();
    uVar2 = 1;
  }
  return uVar2;
}



================================================================