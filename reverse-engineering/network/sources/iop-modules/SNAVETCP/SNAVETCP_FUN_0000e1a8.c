FUNCTION FUN_0000e1a8 @ 0x0000e1a8 size=116
CALLERS (1): FUN_00001800@0x00001800
CALLEES (1): FUN_00012e34@0x00012e34

void FUN_0000e1a8(int param_1)

{
  int iVar1;
  
  if ((int)DAT_0001618e == 0) {
    trap(0x1c00);
  }
  iVar1 = param_1 + (*(uint *)(param_1 + 8) % (uint)(int)DAT_0001618e) * 0x10;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  FUN_00012e34(0,*(undefined4 *)(iVar1 + 0x18),0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return;
}


================================================================