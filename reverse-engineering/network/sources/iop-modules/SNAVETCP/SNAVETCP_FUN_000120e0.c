FUNCTION FUN_000120e0 @ 0x000120e0 size=108
CALLERS (6): FUN_0000ff18@0x0000ff18, FUN_00010bc0@0x00010bc0, FUN_000125c0@0x000125c0, FUN_000105ec@0x000105ec, FUN_00010880@0x00010880, FUN_0001168c@0x0001168c
CALLEES (4): FUN_00011e30@0x00011e30, FUN_00014f54@0x00014f54, FUN_00014e24@0x00014e24, FUN_00014f4c@0x00014f4c

int FUN_000120e0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_00011e30();
  iVar2 = FUN_00014f4c(uVar1);
  if (iVar2 == -100) {
    FUN_00014e24("    KE_ILLEGAL_CONTEXT\n");
    uVar1 = FUN_00011e30(param_1);
    iVar2 = FUN_00014f54(uVar1);
  }
  iVar3 = 0;
  if (iVar2 != -0x196) {
    iVar3 = iVar2;
  }
  return iVar3;
}


================================================================