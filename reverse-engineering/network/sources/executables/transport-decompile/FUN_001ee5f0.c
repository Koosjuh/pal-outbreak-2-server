
undefined8 FUN_001ee5f0(int *param_1)

{
  undefined2 uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (*param_1 < 0) {
    *param_1 = -1;
  }
  else {
    uVar1 = FUN_001ef770((short)*param_1);
    *param_1 = -1;
    uVar2 = FUN_001ee150(uVar1);
  }
  return uVar2;
}

