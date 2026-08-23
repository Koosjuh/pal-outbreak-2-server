FUNCTION FUN_0000031c @ 0x0000031c size=292
CALLERS (2): FUN_00000850@0x00000850, FUN_0000056c@0x0000056c
CALLEES (1): FUN_00008158@0x00008158

void FUN_0000031c(int param_1,int *param_2)

{
  *param_2 = (int)(short)param_1;
  if (*(char *)((&DAT_00009718)[param_1] + 0x14) == '\x01') {
    param_2[1] = 0;
  }
  else if (*(char *)((&DAT_00009718)[param_1] + 0x14) == '\x05') {
    param_2[1] = 1;
  }
  else {
    param_2[1] = 2;
  }
  param_2[2] = 0;
  if (*(int *)((&DAT_00009718)[param_1] + 0xc) == 0) {
    *(undefined1 *)(param_2 + 3) = 0;
  }
  else {
    FUN_00008158(param_2 + 3,*(int *)((&DAT_00009718)[param_1] + 0xc),0x100);
    *(undefined1 *)((int)param_2 + 0x10b) = 0;
  }
  if (*(int *)((&DAT_00009718)[param_1] + 0x10) == 0) {
    *(undefined1 *)(param_2 + 0x43) = 0;
  }
  else {
    FUN_00008158(param_2 + 0x43,*(int *)((&DAT_00009718)[param_1] + 0x10),0x100);
    *(undefined1 *)((int)param_2 + 0x20b) = 0;
  }
  if (*(int *)((&DAT_00009718)[param_1] + 8) == 0) {
    *(undefined1 *)(param_2 + 0x83) = 0;
  }
  else {
    FUN_00008158(param_2 + 0x83,*(int *)((&DAT_00009718)[param_1] + 8),0x100);
    *(undefined1 *)((int)param_2 + 0x30b) = 0;
  }
  return;
}


================================================================