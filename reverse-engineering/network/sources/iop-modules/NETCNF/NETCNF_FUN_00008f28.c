FUNCTION FUN_00008f28 @ 0x00008f28 size=256
CALLERS (1): FUN_00009028@0x00009028
CALLEES (3): FUN_00009600@0x00009600, FUN_00009470@0x00009470, FUN_000094b8@0x000094b8

int FUN_00008f28(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 * 0x124;
  if (*(int *)(&DAT_0000c33c + iVar1) == 0) {
    iVar2 = FUN_00009470((&DAT_0000c338)[param_1 * 0x49]);
    *(int *)(&DAT_0000c334 + iVar1) = iVar2;
    if (iVar2 == 0) {
      return -1;
    }
    iVar2 = (*DAT_0000c218)(param_2,iVar1 + 0xc224,iVar1 + 0xc234,
                            *(undefined4 *)(&DAT_0000c334 + iVar1),0,(&DAT_0000c338)[param_1 * 0x49]
                           );
    if (iVar2 != (&DAT_0000c338)[param_1 * 0x49]) {
      FUN_000094b8(*(undefined4 *)(&DAT_0000c334 + iVar1));
      *(undefined4 *)(&DAT_0000c334 + iVar1) = 0;
      return -1;
    }
  }
  FUN_00009600(param_3,*(int *)(&DAT_0000c334 + iVar1) + *(int *)(&DAT_0000c33c + iVar1),param_4);
  *(int *)(&DAT_0000c33c + iVar1) = *(int *)(&DAT_0000c33c + iVar1) + param_4;
  return param_4;
}


================================================================