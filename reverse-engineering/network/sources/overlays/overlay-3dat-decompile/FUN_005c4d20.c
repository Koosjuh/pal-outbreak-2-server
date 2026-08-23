FUNCTION FUN_005c4d20 @ 0x005c4d20  size=152
CALLERS (2): FUN_005b5ac0@0x005b5ac0, FUN_005ffdc0@0x005ffdc0
CALLEES (2): FUN_005bf230@0x005bf230, FUN_005c5120@0x005c5120
----------------------------------------------------------------

undefined8 FUN_005c4d20(undefined8 param_1,undefined8 param_2,ushort param_3,undefined8 param_4)

{
  undefined1 auStack_310 [4];
  undefined1 auStack_30c [776];
  undefined4 uStack_4;
  
  FUN_005c5120(param_1,&uStack_4);
  func_0x00106b60(auStack_310,0,0x304);
  auStack_310[0] = 1;
  func_0x001069a8(auStack_30c,param_2,param_3);
  func_0x001df380(uRam006febac,0x8000,auStack_310,param_3 + 4,1,uStack_4);
  FUN_005bf230(param_4);
  return 0;
}



================================================================