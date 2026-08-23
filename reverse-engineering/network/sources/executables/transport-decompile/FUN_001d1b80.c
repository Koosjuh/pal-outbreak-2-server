
void FUN_001d1b80(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  FUN_001a7b70(0x15,*(undefined4 *)(&DAT_0024cf68 + *(int *)(param_1 + 4) * 4));
  if (*(int *)(&DAT_0024cf68 + *(int *)(param_1 + 4) * 4) == 2) {
    FUN_001a7b70(2,*(undefined4 *)(*(int *)(param_1 + 8) * 4 + 0x24cfb0));
    *(undefined1 *)(param_2 + 0x8d) = 0;
    *(char *)(param_2 + 0x90) = (char)*(undefined4 *)(param_1 + 0x14);
  }
  else {
    FUN_001a7b70(2,0);
    *(undefined1 *)(param_2 + 0x90) = 0;
    if ((*(uint *)(param_1 + 8) & 1) == 0) {
      *(undefined1 *)(param_2 + 0x8d) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x8d) = 1;
    }
  }
  FUN_001a7b70(0x12,*(undefined4 *)(&DAT_0024cf70 + *(int *)(param_1 + 0x20) * 4));
  FUN_001a7b70(1,*(undefined4 *)(&LAB_0024cf80 + *(int *)(param_1 + 0x14) * 4));
  FUN_001a7b70(0x66,*(undefined4 *)(&DAT_0024cfd0 + *(int *)(param_1 + 0x24) * 4));
  FUN_001a7b70(0x62,*(undefined4 *)(&DAT_0024cfd8 + *(int *)(param_1 + 0x1c) * 4));
  FUN_001a7b70(0xc,*(undefined4 *)(&DAT_0024cfe0 + *(int *)(param_1 + 0x10) * 4));
  FUN_001a7b70(0,*(undefined4 *)(&DAT_0024cff0 + *(int *)(param_1 + 0xc) * 4));
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 == 0) {
LAB_001d1d40:
    FUN_001a7b70(0x5d,0);
  }
  else {
    if (iVar1 != 5) {
      if (iVar1 == 6) {
        FUN_001a7b70(0x5d,0x6000000);
        uVar2 = (undefined1)*(undefined4 *)(param_1 + 0x2c);
        goto LAB_001d1d4c;
      }
      goto LAB_001d1d40;
    }
    FUN_001a7b70(0x5d,0x5000000);
  }
  uVar2 = (undefined1)*(undefined4 *)(param_1 + 0x2c);
LAB_001d1d4c:
  *(undefined1 *)(param_2 + 0x89) = uVar2;
  *(char *)(param_2 + 0x8a) = (char)*(undefined4 *)(param_1 + 0x30);
  *(char *)(param_2 + 0x8b) = (char)*(undefined4 *)(param_1 + 0x34);
  *(char *)(param_2 + 0x8c) = (char)((uint)*(undefined4 *)(param_1 + 0x40) >> 0x10);
  *(char *)(param_2 + 0x8f) = (char)*(undefined4 *)(param_1 + 0x3c);
  return;
}

