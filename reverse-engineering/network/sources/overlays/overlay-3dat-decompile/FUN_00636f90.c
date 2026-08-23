FUNCTION FUN_00636f90 @ 0x00636f90  size=432
CALLERS (2): FUN_00630c90@0x00630c90, FUN_00634ab0@0x00634ab0
CALLEES (11): FUN_00637540@0x00637540, FUN_006375d0@0x006375d0, FUN_00637690@0x00637690, FUN_00637140@0x00637140, FUN_00635bb0@0x00635bb0, FUN_006322c0@0x006322c0, FUN_00634970@0x00634970, FUN_00637430@0x00637430, FUN_00631670@0x00631670, FUN_006378b0@0x006378b0, FUN_00632330@0x00632330
----------------------------------------------------------------

void FUN_00636f90(int param_1)

{
  long lVar1;
  
  if (*(char *)(iRam00715da8 + 0x2f) == '\0') {
    lVar1 = FUN_00637430(*(undefined1 *)(param_1 + 3),iRam00715da8 + 0x1f,iRam00715da8 + 0x1e);
    if (lVar1 == 0) {
      *(undefined2 *)(iRam00715da8 + 0x48) = 0;
      *(undefined1 *)(iRam00715da8 + 0x35) = 0;
      FUN_006322c0();
      switch(*(undefined1 *)(param_1 + 3)) {
      case 0:
        FUN_00637540();
        FUN_00637690();
        FUN_00637140();
        *(undefined4 *)(iRam00715da8 + 0x248) = 1;
        break;
      case 1:
      case 2:
        FUN_00637540();
        FUN_00637690();
        FUN_00637140();
        *(undefined4 *)(iRam00715da8 + 0x248) = 1;
        break;
      case 3:
        FUN_00637540();
        FUN_00637690();
        if (*(char *)(iRam00715da8 + 0x36) == '\0') {
          *(undefined4 *)(iRam00715da8 + 0x248) = 1;
        }
        else {
          FUN_00632330();
          FUN_00634970(0,0);
        }
        FUN_00637140();
        break;
      case 4:
        FUN_00637540();
        FUN_00637690();
        FUN_006378b0();
        FUN_00637140();
        *(undefined4 *)(iRam00715da8 + 0x248) = 1;
        break;
      case 5:
        FUN_00631670();
        break;
      case 6:
      case 7:
        FUN_00635bb0();
        break;
      case 8:
      case 9:
        FUN_006375d0();
      }
    }
    else {
      *(undefined4 *)(iRam00715da8 + 0x248) = 5;
    }
  }
  else {
    *(undefined4 *)(iRam00715da8 + 0x248) = 5;
  }
  return;
}



================================================================