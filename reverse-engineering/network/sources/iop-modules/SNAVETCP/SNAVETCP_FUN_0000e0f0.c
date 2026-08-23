FUNCTION FUN_0000e0f0 @ 0x0000e0f0 size=92
CALLERS (1): FUN_00001800@0x00001800
CALLEES (0): 

void FUN_0000e0f0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = (int)DAT_0001618e;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  if (0 < iVar1) {
    do {
      iVar2 = iVar4 << 0x10;
      iVar4 = iVar4 + 1;
      puVar3 = (undefined4 *)(param_1 + (iVar2 >> 0xc) + 0xc);
      *puVar3 = 0;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0;
    } while (iVar4 * 0x10000 >> 0x10 < iVar1);
  }
  return;
}


================================================================