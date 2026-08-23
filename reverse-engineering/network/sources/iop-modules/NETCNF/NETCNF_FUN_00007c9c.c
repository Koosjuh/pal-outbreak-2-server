FUNCTION FUN_00007c9c @ 0x00007c9c size=104
CALLERS (2): FUN_000032bc@0x000032bc, FUN_000027e4@0x000027e4
CALLEES (1): FUN_00007b40@0x00007b40

undefined4 FUN_00007c9c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x14) == 1) {
    uVar2 = *(undefined4 *)(param_1 + 4);
    uVar3 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x14) != 2) {
      return 0xffffffff;
    }
    uVar2 = *(undefined4 *)(param_1 + 4);
    uVar3 = *(undefined4 *)(param_1 + 0x1c);
  }
  iVar1 = FUN_00007b40(param_1,uVar2,uVar3);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================