FUNCTION FUN_006312c0 @ 0x006312c0  size=216
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (4): FUN_00637540@0x00637540, FUN_00637690@0x00637690, FUN_00631ff0@0x00631ff0, FUN_00637140@0x00637140
----------------------------------------------------------------

void FUN_006312c0(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  if (*(char *)(iRam00715da8 + 0x2f) == '\x02') {
    FUN_00631ff0();
  }
  cVar1 = *(char *)(iRam00715da8 + 0x1e);
  puVar2 = (undefined1 *)(iRam00715da8 + 0x1e);
  if ((cVar1 == '\x0f') || (cVar1 == '\a')) {
    if ((*(uint *)(iRam00715da8 + 0x20) & 1) == 0) {
      *puVar2 = 0;
    }
  }
  else {
    if (cVar1 != '\0') {
      return;
    }
    if ((*(uint *)(iRam00715da8 + 0x20) & 0x8000) == 0) {
      *puVar2 = 0xf;
    }
    else {
      if ((*(uint *)(iRam00715da8 + 0x20) & 0x80) != 0) {
        return;
      }
      *puVar2 = 7;
    }
  }
  FUN_00637540();
  FUN_00637690();
  FUN_00637140();
  *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  return;
}



================================================================