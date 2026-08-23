FUNCTION FUN_00004728 @ 0x00004728 size=148
CALLERS (2): FUN_00004b5c@0x00004b5c, FUN_00004a68@0x00004a68
CALLEES (2): FUN_00009720@0x00009720, FUN_000008c4@0x000008c4

undefined4 FUN_00004728(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000008c4(param_3);
  uVar2 = 0;
  if (iVar1 < 0) {
    FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                 *(undefined4 *)(param_1 + 0x3c));
    FUN_00009720("sceNetCnfName2Address(%s) -> %d\n",param_2,iVar1);
    FUN_00009720(&DAT_00009a7c);
    uVar2 = 0xffffffff;
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  }
  return uVar2;
}


================================================================