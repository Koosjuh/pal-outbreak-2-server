FUNCTION FUN_005fe620 @ 0x005fe620  size=272
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (8): FUN_00603e40@0x00603e40, FUN_005aec70@0x005aec70, FUN_005fe730@0x005fe730, FUN_00628e10@0x00628e10, FUN_005f5f80@0x005f5f80, FUN_006052f0@0x006052f0, FUN_00628ee0@0x00628ee0, FUN_005f5ec0@0x005f5ec0
----------------------------------------------------------------

void FUN_005fe620(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = FUN_005aec70();
  if (lVar2 == 0) {
    iVar3 = (int)param_1;
    cVar1 = *(char *)(iVar3 + 1);
    if (cVar1 == '\n') {
      lVar2 = FUN_005f5f80();
      if (lVar2 != 0) {
        FUN_005f5ec0(param_1);
        *(undefined1 *)(iVar3 + 0xf) = 6;
      }
    }
    else if (cVar1 == '\x03') {
      lVar2 = FUN_00628e10(param_1);
      if ((lVar2 == 1) || (lVar2 == -2)) {
        FUN_00628ee0(param_1);
        *(undefined1 *)(iVar3 + 0xf) = 6;
      }
    }
    else if (cVar1 == '\x06') {
      FUN_006052f0(param_1,1);
    }
    else if (cVar1 == '\a') {
      FUN_006052f0(param_1,0);
    }
    else if (cVar1 == '\x01') {
      FUN_00603e40(param_1);
    }
    else if (cVar1 == '\0') {
      FUN_005fe730(param_1);
    }
  }
  return;
}



================================================================