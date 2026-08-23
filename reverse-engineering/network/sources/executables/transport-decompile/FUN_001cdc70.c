
void FUN_001cdc70(undefined4 *param_1,undefined4 *param_2,long param_3)

{
  if (param_3 == 0) {
    FUN_001069a8(*param_2,*param_1,0x200);
    if (*(char *)(param_1 + 0x207) == '\0') {
      FUN_001069a8(param_2[1],param_1[1],0x200);
    }
    FUN_001069a8(param_2 + 2,param_1 + 2,0x800);
    FUN_001069a8(param_2[0x206],param_1[0x206],0x840);
  }
  FUN_001069a8(param_2[0x202],param_1[0x202],0x1300);
  param_2[0x203] = param_1[0x203];
  *(undefined2 *)(param_2 + 0x204) = *(undefined2 *)(param_1 + 0x204);
  *(undefined2 *)((int)param_2 + 0x812) = *(undefined2 *)((int)param_1 + 0x812);
  *(undefined2 *)(param_2 + 0x205) = *(undefined2 *)(param_1 + 0x205);
  *(undefined2 *)((int)param_2 + 0x816) = *(undefined2 *)((int)param_1 + 0x816);
  *(undefined1 *)(param_2 + 0x207) = *(undefined1 *)(param_1 + 0x207);
  param_1[0x203] = 0;
  return;
}

