FUNCTION FUN_005fb860 @ 0x005fb860  size=336
CALLERS (1): FUN_005fb710@0x005fb710
CALLEES (5): FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005fba80@0x005fba80, FUN_005b9060@0x005b9060, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_005fb860(int param_1)

{
  char cVar1;
  long lVar2;
  
  if (*(char *)(param_1 + 0x10) == '\x01') {
    lVar2 = FUN_005b14b0(0x210);
    if (lVar2 != 0) {
      cVar1 = *(char *)(param_1 + 0x97c);
      if (cVar1 == '\x04') {
        *(undefined1 *)(param_1 + 0xe) = 0;
        *(undefined1 *)(param_1 + 0xf) = 0;
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x11) = 0;
        *(undefined1 *)(param_1 + 0x448) = 0;
        *(undefined1 *)(param_1 + 0x449) = 0;
        *(undefined1 *)(param_1 + 0x97c) = 1;
        FUN_005fba80();
      }
      else if (cVar1 == '\x03') {
        *(undefined1 *)(param_1 + 0xe) = 2;
        *(undefined1 *)(param_1 + 0xf) = 1;
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x11) = 0;
      }
      else if (cVar1 == '\x02') {
        *(undefined1 *)(param_1 + 0xe) = 1;
        *(undefined1 *)(param_1 + 0xf) = 0;
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x11) = 0;
      }
      else if (cVar1 == '\x01') {
        *(undefined1 *)(param_1 + 0xe) = 1;
        *(undefined1 *)(param_1 + 0xf) = 0;
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x11) = 0;
      }
      else if (cVar1 == '\0') {
        *(undefined1 *)(param_1 + 0xe) = 1;
        *(undefined1 *)(param_1 + 0xf) = 0;
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x11) = 0;
      }
      *(undefined1 *)(param_1 + 0x440) = 0;
      FUN_005b9110(0x4c);
    }
  }
  else if (*(char *)(param_1 + 0x10) == '\0') {
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (*(char *)(param_1 + 0x15) == '\x14') {
      FUN_005b9060(0x14,param_1 + 0x5ec);
    }
    else {
      FUN_005b8cf0();
    }
  }
  return;
}



================================================================