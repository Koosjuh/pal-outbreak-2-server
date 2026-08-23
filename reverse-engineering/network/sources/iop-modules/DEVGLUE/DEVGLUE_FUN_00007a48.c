FUNCTION FUN_00007a48 @ 0x00007a48 size=156
CALLERS (1): FUN_0000560c@0x0000560c
CALLEES (4): FUN_000043f8@0x000043f8, FUN_0000806c@0x0000806c, FUN_00008140@0x00008140, FUN_00004ffc@0x00004ffc

undefined4 FUN_00007a48(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *local_10 [2];
  
  iVar3 = FUN_0000806c();
  DAT_0000ecc0 = *(undefined4 *)(iVar3 + 8);
  iVar3 = FUN_000043f8(DAT_0000970c);
  uVar4 = 0xffffffff;
  if (-1 < iVar3) {
    iVar3 = FUN_00004ffc(DAT_0000970c,local_10);
    if (iVar3 < 0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar1 = *(undefined1 *)(local_10[0] + 1);
      uVar2 = *(undefined1 *)((int)local_10[0] + 5);
      *param_1 = *local_10[0];
      *(undefined1 *)(param_1 + 1) = uVar1;
      *(undefined1 *)((int)param_1 + 5) = uVar2;
      FUN_00008140((int)param_1 + 6,0xff,6);
      uVar4 = 0;
    }
  }
  return uVar4;
}


================================================================