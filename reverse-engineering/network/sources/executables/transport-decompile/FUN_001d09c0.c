
void FUN_001d09c0(undefined2 *param_1,undefined1 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined2 uVar1;
  
  uVar1 = param_1[2];
  *param_2 = (char)*param_1;
  param_2[1] = (char)uVar1;
  FUN_001d06d0(param_1,param_2,param_1 + 4,param_3,param_4);
  return;
}

