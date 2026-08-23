
void FUN_0017c920(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  long lVar1;
  undefined4 uVar2;
  
  *param_4 = 0;
  *param_3 = 0;
  if (((param_1 != 0) && (0 < param_2)) && (0 < param_2)) {
    do {
      lVar1 = FUN_00106910(param_1,0x258948,1);
      if ((lVar1 == 0) && (lVar1 = FUN_00106910(param_1,0x2588d0,8), lVar1 == 0)) {
        *param_3 = param_1;
        uVar2 = FUN_0017c9e8(param_1);
        *param_4 = uVar2;
      }
      param_2 = param_2 + -1;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}
