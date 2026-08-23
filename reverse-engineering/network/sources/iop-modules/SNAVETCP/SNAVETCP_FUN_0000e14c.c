FUNCTION FUN_0000e14c @ 0x0000e14c size=92
CALLERS (1): FUN_0000e694@0x0000e694
CALLEES (0): 

void FUN_0000e14c(int param_1,short param_2,short param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((int)DAT_0001618e == 0) {
    trap(0x1c00);
  }
  iVar1 = param_1 + (*(uint *)(param_1 + 4) % (uint)(int)DAT_0001618e) * 0x10;
  *(undefined4 *)(iVar1 + 0xc) = 1;
  *(int *)(iVar1 + 0x10) = (int)param_3;
  *(int *)(iVar1 + 0x14) = (int)param_2;
  *(undefined4 *)(iVar1 + 0x18) = param_4;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return;
}


================================================================