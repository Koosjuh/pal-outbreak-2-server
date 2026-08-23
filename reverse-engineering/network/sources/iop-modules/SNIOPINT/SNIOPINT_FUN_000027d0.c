FUNCTION FUN_000027d0 @ 0x000027d0 size=68
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003668@0x00003668

void FUN_000027d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10 [2];
  
  iVar1 = FUN_00003668(8,local_10,4);
  uVar2 = 0xffffffff;
  if (-1 < iVar1) {
    uVar2 = local_10[0];
  }
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  return;
}


================================================================