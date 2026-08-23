FUNCTION FUN_005dda30 @ 0x005dda30  size=272
CALLERS (5): FUN_005e1aa0@0x005e1aa0, FUN_005e1a30@0x005e1a30, FUN_005e0440@0x005e0440, FUN_005e1da0@0x005e1da0, FUN_005e19b0@0x005e19b0
CALLEES (1): FUN_005dd920@0x005dd920
----------------------------------------------------------------

void FUN_005dda30(float param_1,float param_2,float param_3,float param_4,undefined4 param_5)

{
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  if (((short)(int)param_1 + -4) % 5 == 0) {
    param_1 = param_1 - 1.0;
  }
  if (((short)(int)param_3 + -4) % 5 == 0) {
    param_3 = param_3 + 1.0;
  }
  FUN_005dd920(1,0);
  uStack_10 = (undefined2)(int)param_1;
  uStack_e = (undefined2)(int)param_2;
  uStack_c = (undefined2)(int)param_3;
  uStack_a = (undefined2)(int)param_4;
  uStack_8 = param_5;
  func_0x001a2800(&uStack_10);
  return;
}



================================================================