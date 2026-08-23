FUNCTION FUN_005bf230 @ 0x005bf230  size=68
CALLERS (9): FUN_005c0f60@0x005c0f60, FUN_005bbe00@0x005bbe00, FUN_005c2820@0x005c2820, FUN_005bdb00@0x005bdb00, FUN_005c4d20@0x005c4d20, FUN_005bc270@0x005bc270, FUN_005bfdd0@0x005bfdd0, FUN_005c44a0@0x005c44a0, FUN_005c2340@0x005c2340
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bf230(long param_1)

{
  undefined1 auStack_10 [16];
  
  if (param_1 != 0) {
    if (cRam006cbc84 == '\0') {
      auStack_10[0] = 0;
    }
    else {
      auStack_10[0] = 0xff;
    }
    (*(code *)param_1)(auStack_10,auStack_10);
  }
  return;
}



================================================================