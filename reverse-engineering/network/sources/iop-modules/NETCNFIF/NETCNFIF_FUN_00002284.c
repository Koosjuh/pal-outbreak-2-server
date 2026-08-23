FUNCTION FUN_00002284 @ 0x00002284 size=188
CALLERS (1): FUN_000003c0@0x000003c0
CALLEES (4): FUN_000020bc@0x000020bc, FUN_00001c64@0x00001c64, FUN_000028bc@0x000028bc, FUN_00001b0c@0x00001b0c

int FUN_00002284(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_3 == 0) {
    iVar2 = FUN_000020bc();
  }
  else if ((param_3 < 0) || (2 < param_3)) {
    FUN_000028bc("[%s] unknown type (%d)\n","sceNetcnfifWriteEnv",param_3);
  }
  else {
    iVar2 = FUN_00001c64(param_1,param_2,param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_00001b0c(param_1,param_3);
  }
  if (-1 < iVar2) {
    uVar1 = *(int *)(param_1 + 0xc) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0xc) = uVar1;
    *(uint *)(param_1 + 8) = uVar1;
  }
  return iVar2;
}


================================================================