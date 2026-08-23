
void FUN_001c3450(int param_1,int param_2,int param_3)

{
  if (cRam0035ccb3 == '\0') {
    param_3 = *(int *)(param_1 + 0xe0) + param_3;
    if (param_3 < param_2) {
      *(int *)(param_1 + 0xe0) = param_3;
    }
    else if (*(int *)(param_1 + 0xe0) < param_2) {
      *(int *)(param_1 + 0xe0) = param_2;
    }
  }
  return;
}

