FUNCTION FUN_00000b9c @ 0x00000b9c size=256
CALLERS (2): FUN_00001938@0x00001938, FUN_0000159c@0x0000159c
CALLEES (11): FUN_0000070c@0x0000070c, FUN_00002204@0x00002204, FUN_0000226c@0x0000226c, FUN_000022a8@0x000022a8, FUN_000008e8@0x000008e8, FUN_00000b84@0x00000b84, FUN_00002264@0x00002264, FUN_0000002c@0x0000002c, FUN_00000250@0x00000250, FUN_000022a0@0x000022a0, FUN_000022b0@0x000022b0

undefined4 FUN_00000b9c(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  local_20 = *param_1;
  local_18 = 1;
  local_14 = 1;
  local_1c = 0;
  DAT_000026b0 = FUN_00002204(&local_20);
  if (DAT_000026b0 < 1) {
    uVar1 = 0xffffffff;
  }
  else {
    FUN_000022a0(0x29,auStack_10);
    FUN_000022a8(&local_c);
    uVar2 = FUN_0000226c();
    FUN_00002264(uVar2 | 0x80);
    FUN_000022b0(local_c);
    FUN_0000002c(0x103);
    FUN_0000070c(0xffff);
    FUN_00000250(0x5a8);
    iVar4 = 0xf;
    iVar3 = 0x3c;
    do {
      *(undefined4 *)((int)&DAT_000026b8 + iVar3) = 0;
      iVar4 = iVar4 + -1;
      iVar3 = iVar3 + -4;
    } while (-1 < iVar4);
    iVar4 = 0;
    iVar3 = 0;
    do {
      iVar4 = iVar4 + 1;
      *(undefined4 *)((int)&DAT_00002708 + iVar3) = 0;
      *(undefined4 *)((int)&DAT_00002718 + iVar3) = 0;
      iVar3 = iVar4 * 4;
    } while (iVar4 < 4);
    FUN_000008e8();
    FUN_00000b84(0);
    uVar1 = 0;
  }
  return uVar1;
}


================================================================