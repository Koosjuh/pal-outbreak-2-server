
void FUN_001eb088(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uStack_14;
  
  iVar1 = *param_1;
  if (param_5 < 1) {
    uStack_14 = param_2 - param_3;
  }
  else if (param_4 == 0) {
    uStack_14 = (param_2 - param_3) + 0x22;
  }
  else {
    uStack_14 = param_2 - param_4;
  }
  if (uStack_14 < 0x11) {
    uStack_14 = 0x11;
  }
  if (32000 < uStack_14) {
    uStack_14 = 32000;
  }
  if (0 < iVar1) {
    if (iVar1 == 0) {
      trap(7);
    }
    if (10 < uStack_14 / iVar1) {
      uStack_14 = iVar1 * 10;
    }
  }
  *param_1 = uStack_14;
  return;
}

