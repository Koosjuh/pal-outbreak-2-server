FUNCTION FUN_006375d0 @ 0x006375d0  size=180
CALLERS (2): FUN_00636f90@0x00636f90, FUN_00635c60@0x00635c60
CALLEES (6): FUN_00637540@0x00637540, FUN_00637690@0x00637690, FUN_00637140@0x00637140, FUN_00637570@0x00637570, FUN_006322c0@0x006322c0, FUN_00634470@0x00634470
----------------------------------------------------------------

void FUN_006375d0(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  
  cVar3 = FUN_00637570(*(undefined1 *)(iRam00715da8 + 0x1e));
  if (cVar3 < '\0') {
    *(undefined4 *)(iRam00715da8 + 0x248) = 5;
  }
  else {
    uVar1 = *(undefined1 *)(iRam00715da8 + 0x24);
    uVar2 = *(undefined1 *)(iRam00715da8 + 0x25);
    *(char *)(iRam00715da8 + 0x1e) = cVar3;
    FUN_00637540();
    FUN_00637690();
    FUN_00637140();
    FUN_006322c0();
    *(undefined4 *)(iRam00715da8 + 0x248) = 1;
    *(undefined1 *)(iRam00715da8 + 0x24) = uVar1;
    *(undefined1 *)(iRam00715da8 + 0x25) = uVar2;
    FUN_00634470();
  }
  return;
}



================================================================