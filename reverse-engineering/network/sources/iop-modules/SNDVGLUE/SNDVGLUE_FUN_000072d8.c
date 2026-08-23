FUNCTION FUN_000072d8 @ 0x000072d8 size=188
CALLERS (1): FUN_000074ac@0x000074ac
CALLEES (4): FUN_00007270@0x00007270, FUN_00006ea0@0x00006ea0, FUN_00007044@0x00007044, FUN_00006f68@0x00006f68

int FUN_000072d8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_18 [2];
  
  local_18[0] = param_1 + 0x24e;
  iVar1 = FUN_00006ea0(local_18,param_1);
  if ((-1 < iVar1 << 0x10) && (iVar2 = FUN_00006f68(local_18,param_1), -1 < iVar2 << 0x10)) {
    iVar3 = FUN_00007044(local_18,param_1);
    if (-1 < iVar3 << 0x10) {
      iVar4 = FUN_00007270(local_18,param_1);
      if (-1 < iVar4 << 0x10) {
        return (iVar1 + iVar2 + iVar3 + iVar4) * 0x10000 >> 0x10;
      }
    }
  }
  return -1;
}


================================================================