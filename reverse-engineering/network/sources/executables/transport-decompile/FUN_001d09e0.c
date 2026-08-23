
void FUN_001d09e0(undefined2 *param_1,undefined1 *param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined2 uVar1;
  
  uVar1 = param_1[2];
  *param_2 = (char)*param_1;
  param_2[1] = (char)uVar1;
  param_2[2] = 0;
  FUN_001d0510(param_1,param_2,param_4,param_1 + 4,param_3,param_5);
  return;
}

