
void FUN_001d0400(int param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  param_2 = param_2 & 0xff;
  FUN_001cbc20(param_2 * 8 + 0x3000);
  FUN_001a7b70(0x15,2);
  FUN_001a7b70(1,0x800);
  FUN_001a7b70(0x12,0x8000);
  FUN_001a7b70(0x62,0);
  FUN_001a7b70(0xc,1);
  FUN_001a7b70(0x66,0);
  FUN_001a7b70(2,0);
  FUN_001a7b70(0,0);
  piVar2 = (int *)(param_1 + 0x70);
  uVar1 = FUN_001ab460(8,0xb);
  *(undefined4 *)(param_1 + 0x878) = uVar1;
  *piVar2 = param_1 + 0x890;
  *(int *)(param_1 + 0x888) = param_1 + 0x910;
  if (cRam00343577 == '\0') {
    FUN_001cce80(param_2,0xffffffffffffffff,piVar2,3);
  }
  else {
    FUN_001a1750(0,piVar2,param_2,3);
  }
  return;
}

