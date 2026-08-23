
void FUN_001e5104(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uStack_24;
  uint uStack_20;
  short sStack_18;
  
  uStack_24 = *param_2;
  uStack_20 = *param_3;
  for (sStack_18 = 0x11; 1 < sStack_18; sStack_18 = sStack_18 + -1) {
    uVar1 = uStack_24 ^ param_1[sStack_18];
    uStack_24 = FUN_001e4ec8(param_1,uVar1);
    uStack_24 = uStack_20 ^ uStack_24;
    uStack_20 = uVar1;
  }
  uVar1 = param_1[1];
  *param_2 = uStack_20 ^ *param_1;
  *param_3 = uStack_24 ^ uVar1;
  return;
}

