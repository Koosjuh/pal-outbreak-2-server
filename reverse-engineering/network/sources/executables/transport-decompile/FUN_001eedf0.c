
int FUN_001eedf0(uint *param_1)

{
  uint uVar1;
  short sVar2;
  
  uVar1 = *param_1;
  sVar2 = FUN_001ef540(uVar1,param_1[1],uVar1 | ~(uVar1 & param_1[1]));
  return -(uint)(sVar2 < 0);
}

