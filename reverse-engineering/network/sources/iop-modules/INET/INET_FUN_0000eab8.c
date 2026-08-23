FUNCTION FUN_0000eab8 @ 0x0000eab8 size=296
CALLERS (1): FUN_0000ec64@0x0000ec64
CALLEES (8): FUN_00005e44@0x00005e44, FUN_0000e848@0x0000e848, FUN_000199b4@0x000199b4, FUN_00019778@0x00019778, FUN_000014dc@0x000014dc, FUN_0000bc98@0x0000bc98, FUN_0001748c@0x0001748c, FUN_0000e770@0x0000e770

void FUN_0000eab8(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)DAT_0001b868;
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffff8;
  for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    iVar1 = FUN_000199b4(param_1 + 8,piVar2 + 8);
    if (iVar1 == 0) {
      piVar2[0xb] = 0;
      piVar2[5] = piVar2[5] & 0xfffffffe;
    }
  }
  if (*(int *)(param_1 + 0x80) != 0) {
    FUN_0000e770();
  }
  if ((1 < *(ushort *)(param_1 + 0x40)) && (*(int *)(param_1 + 0x1b0) != 0)) {
    FUN_0000e770();
  }
  FUN_0001748c(param_1);
  FUN_00019778(param_1);
  FUN_0000bc98(param_1);
  FUN_000014dc(param_1);
  FUN_00005e44(param_1);
  FUN_0000e848();
  if (((*(uint *)(param_1 + 0x48) & 0x200) != 0) && (DAT_0001b880 != 0)) {
    (**(code **)(DAT_0001b880 + 0xc))(param_1);
  }
  return;
}


================================================================