FUNCTION FUN_000000c4 @ 0x000000c4 size=156
CALLERS (0): 
CALLEES (3): FUN_00000000@0x00000000, FUN_00000994@0x00000994, FUN_00017ad8@0x00017ad8

void FUN_000000c4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (((*(uint *)(param_1 + 8) & 1) == 0) && (*(int *)(param_1 + 0xc) < 5)) {
    FUN_00000994(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x10));
    iVar1 = *(int *)(param_1 + 0xc) + 1;
    *(int *)(param_1 + 0xc) = iVar1;
    uVar2 = 20000;
    if (iVar1 < 5) {
      uVar2 = 1000;
    }
    uVar2 = FUN_00017ad8(0xc4,param_1,uVar2);
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
  }
  else {
    FUN_00000000(param_1);
  }
  return;
}


================================================================