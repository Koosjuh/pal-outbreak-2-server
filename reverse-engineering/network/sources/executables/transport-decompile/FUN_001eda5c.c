
undefined4 FUN_001eda5c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  ushort auStack_20 [8];
  
  FUN_001069a8(auStack_20,param_2,0x10);
  uVar1 = FUN_001ed74c(param_1,param_2,auStack_20[0] & 0x3ff);
  return uVar1;
}

