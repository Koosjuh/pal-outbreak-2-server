FUNCTION FUN_00631670 @ 0x00631670  size=176
CALLERS (3): FUN_00636f90@0x00636f90, FUN_006314a0@0x006314a0, FUN_00635940@0x00635940
CALLEES (6): FUN_00637540@0x00637540, FUN_00637690@0x00637690, FUN_00631ff0@0x00631ff0, FUN_00637140@0x00637140, FUN_006322c0@0x006322c0, FUN_00637260@0x00637260
----------------------------------------------------------------

void FUN_00631670(void)

{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 5;
  if ((*(char *)(iRam00715da8 + 0x2f) == '\0') &&
     (*(int *)(*(int *)(iRam00715da8 + 0x10) + 0x28) != 0)) {
    lVar1 = FUN_00637260(5,iRam00715da8 + 0x1f,iRam00715da8 + 0x1e);
    if (lVar1 == 0) {
      FUN_00631ff0();
      *(undefined1 *)(iRam00715da8 + 0x35) = 0;
      FUN_00637540();
      FUN_00637690();
      FUN_00637140();
      FUN_006322c0();
      uVar2 = 1;
    }
    else {
      *(undefined1 *)(iRam00715da8 + 0x35) = 0;
      *(undefined2 *)(iRam00715da8 + 0x48) = 0;
    }
  }
  *(undefined4 *)(iRam00715da8 + 0x248) = uVar2;
  return;
}



================================================================