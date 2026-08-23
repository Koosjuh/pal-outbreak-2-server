FUNCTION FUN_006352e0 @ 0x006352e0  size=256
CALLERS (3): FUN_00630f20@0x00630f20, FUN_00634ab0@0x00634ab0, FUN_006300a0@0x006300a0
CALLEES (7): FUN_00630420@0x00630420, FUN_00630750@0x00630750, FUN_00634970@0x00634970, FUN_006355a0@0x006355a0, FUN_006353e0@0x006353e0, FUN_00635900@0x00635900, FUN_00632330@0x00632330
----------------------------------------------------------------

void FUN_006352e0(int param_1)

{
  long lVar1;
  undefined2 uStack_2;
  
  if (*(char *)(iRam00715da8 + 0x30) == '\x01') {
    if (*(char *)(iRam00715da8 + 0x36) == '\0') {
      if (*(char *)(iRam00715da8 + 0x2f) == '\x03') {
        lVar1 = FUN_00635900();
        if (lVar1 == 1) {
          FUN_006355a0(*(undefined2 *)(param_1 + 4));
        }
      }
      else if (*(char *)(iRam00715da8 + 0x2f) == '\0') {
        if (*(char *)(iRam00715da8 + 0x26) == '\0') {
          FUN_006353e0();
        }
      }
      else {
        FUN_006353e0();
      }
    }
    else {
      FUN_00632330();
      FUN_00634970(0,0);
    }
  }
  else {
    lVar1 = FUN_00630420(&uStack_2);
    if (lVar1 != 0) {
      if (*(char *)(iRam00715da8 + 0x2f) == '\x03') {
        FUN_006355a0(uStack_2);
      }
      else {
        FUN_00630750(uStack_2);
      }
    }
  }
  return;
}



================================================================