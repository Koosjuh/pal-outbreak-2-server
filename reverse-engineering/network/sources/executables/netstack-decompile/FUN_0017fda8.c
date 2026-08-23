
void FUN_0017fda8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  ulong unaff_s4;
  undefined4 uStack_a0;
  int iStack_9c;
  undefined1 auStack_98 [40];
  undefined4 auStack_70 [4];
  
  auStack_70[0] = 0x28;
  iStack_9c = (int)param_4;
  FUN_001069a8((uint)&uStack_a0 | 8,param_5,param_4);
  uStack_a0 = (undefined4)param_2;
  FUN_001069a8(auStack_98 + (int)param_4,param_3,param_2);
  FUN_0017f948(param_1,unaff_s4 & 0xffffffff00000000 | 0x103400b,auStack_70,&uStack_a0);
  return;
}

