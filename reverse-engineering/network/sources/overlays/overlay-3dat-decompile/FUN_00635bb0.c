FUNCTION FUN_00635bb0 @ 0x00635bb0  size=168
CALLERS (1): FUN_00636f90@0x00636f90
CALLEES (6): FUN_00637540@0x00637540, FUN_00637690@0x00637690, FUN_00631ff0@0x00631ff0, FUN_00635ba0@0x00635ba0, FUN_00637140@0x00637140, FUN_006322c0@0x006322c0
----------------------------------------------------------------

void FUN_00635bb0(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 extraout_a1_lo;
  undefined4 uVar4;
  
  cVar3 = FUN_00635ba0(*(undefined1 *)(iRam00715da8 + 0x1e),5);
  uVar4 = extraout_a1_lo;
  if (-1 < cVar3) {
    uVar1 = *(undefined1 *)(iRam00715da8 + 0x24);
    uVar2 = *(undefined1 *)(iRam00715da8 + 0x25);
    *(char *)(iRam00715da8 + 0x1e) = cVar3;
    FUN_00637540();
    FUN_00637690();
    FUN_00631ff0();
    FUN_00637140();
    FUN_006322c0();
    uVar4 = 1;
    *(undefined1 *)(iRam00715da8 + 0x24) = uVar1;
    *(undefined1 *)(iRam00715da8 + 0x25) = uVar2;
  }
  *(undefined4 *)(iRam00715da8 + 0x248) = uVar4;
  return;
}



================================================================