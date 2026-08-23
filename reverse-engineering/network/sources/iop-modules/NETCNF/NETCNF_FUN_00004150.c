FUNCTION FUN_00004150 @ 0x00004150 size=120
CALLERS (10): FUN_000065bc@0x000065bc, FUN_000068e4@0x000068e4, FUN_000007a0@0x000007a0, FUN_00004b5c@0x00004b5c, FUN_0000497c@0x0000497c, FUN_0000626c@0x0000626c, FUN_000062ec@0x000062ec, FUN_00004e64@0x00004e64, FUN_00004558@0x00004558, FUN_00004a68@0x00004a68
CALLEES (1): FUN_00009618@0x00009618

uint FUN_00004150(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (1 << (param_3 & 0x1f)) - 1;
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar1 = *(int *)(param_1 + 0xc) + uVar1 & ~uVar1;
    if (uVar1 + param_2 < *(uint *)(param_1 + 0x10)) {
      *(uint *)(param_1 + 0xc) = uVar1 + param_2;
      FUN_00009618(uVar1);
      return uVar1;
    }
  }
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  return 0;
}


================================================================