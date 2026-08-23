FUNCTION FUN_00630f20 @ 0x00630f20  size=264
CALLERS (2): FUN_00634ab0@0x00634ab0, FUN_006300a0@0x006300a0
CALLEES (6): FUN_00633930@0x00633930, FUN_00633ab0@0x00633ab0, FUN_006352e0@0x006352e0, FUN_00630c50@0x00630c50, FUN_00633430@0x00633430, FUN_00633470@0x00633470
----------------------------------------------------------------

void FUN_00630f20(long param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(iRam00715da8 + 0x2f);
  if ((cVar1 == '\x03') || (cVar1 == '\x02')) {
    if (param_1 == 0) {
      FUN_006352e0(*(undefined4 *)(iRam00715da8 + 8));
    }
    else {
      FUN_00633430();
    }
    if (*(char *)(iRam00715da8 + 0x30) == '\x01') {
      *(undefined4 *)(iRam00715da8 + 0x248) = 1;
    }
  }
  else if (cVar1 == '\x01') {
    *(undefined4 *)(iRam00715da8 + 0x248) = 0;
    lVar2 = FUN_00630c50();
    if (lVar2 == 0) {
      FUN_00633ab0();
    }
    else {
      FUN_00633930();
    }
  }
  else if (cVar1 == '\0') {
    if (*(short *)(iRam00715da8 + 0x260) == 0) {
      if ((param_1 == 0) &&
         (FUN_006352e0(*(undefined4 *)(iRam00715da8 + 8)), *(char *)(iRam00715da8 + 0x30) == '\x01')
         ) {
        *(undefined4 *)(iRam00715da8 + 0x248) = 1;
      }
    }
    else {
      FUN_00633470();
    }
  }
  return;
}



================================================================