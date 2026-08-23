FUNCTION FUN_00002e18 @ 0x00002e18 size=172
CALLERS (1): FUN_00003a9c@0x00003a9c
CALLEES (2): FUN_0000507c@0x0000507c, FUN_00004ffc@0x00004ffc

undefined4 FUN_00002e18(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *local_10 [2];
  
  if (param_1 != 0) {
    iVar4 = FUN_00004ffc(DAT_0000970c,local_10);
    if (iVar4 < 0) {
      return 0xffffffff;
    }
    iVar4 = FUN_0000507c(DAT_0000970c);
    if (-1 < iVar4) {
      uVar1 = *(undefined1 *)(local_10[0] + 1);
      uVar2 = *(undefined1 *)((int)local_10[0] + 5);
      *(undefined4 *)(param_1 + 4) = *local_10[0];
      *(undefined1 *)(param_1 + 8) = uVar1;
      *(undefined1 *)(param_1 + 9) = uVar2;
      uVar3 = DAT_0000de36;
      *(undefined4 *)(param_1 + 10) = DAT_0000de32;
      *(undefined2 *)(param_1 + 0xe) = uVar3;
      *(int *)(param_1 + 0x10) = iVar4;
      return 0;
    }
  }
  return 0xffffffff;
}


================================================================