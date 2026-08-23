FUNCTION FUN_005bdfe0 @ 0x005bdfe0  size=120
CALLERS (24): FUN_005bb980@0x005bb980, FUN_005bbe00@0x005bbe00, FUN_005c5a10@0x005c5a10, FUN_005bb8e0@0x005bb8e0, FUN_005bfb40@0x005bfb40, FUN_005c0060@0x005c0060, FUN_005c7420@0x005c7420, FUN_005c29c0@0x005c29c0, FUN_005bfe90@0x005bfe90, FUN_005c44a0@0x005c44a0, FUN_005c76e0@0x005c76e0, FUN_005bb4d0@0x005bb4d0, ...
CALLEES (3): FUN_005be9d0@0x005be9d0, FUN_005be120@0x005be120, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bdfe0(long param_1)

{
  undefined1 auStack_10 [16];
  
  if (sRam006cbc7e == 0x10) {
    if (param_1 != 0) {
      FUN_005bdf90(param_1,0);
    }
  }
  else if (sRam006cbc7e == 2) {
    if (cRam006cbc84 == '\0') {
      auStack_10[0] = 0;
    }
    else {
      auStack_10[0] = 0xff;
      FUN_005be9d0();
    }
    FUN_005be120(auStack_10,1,0);
  }
  return;
}



================================================================