FUNCTION FUN_000016c8 @ 0x000016c8 size=116
CALLERS (1): FUN_000003c0@0x000003c0
CALLEES (3): FUN_0000161c@0x0000161c, FUN_000028bc@0x000028bc, FUN_00001320@0x00001320

undefined4 FUN_000016c8(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_3 == 0) {
    uVar1 = FUN_0000161c(param_1,*(undefined4 *)(param_2 + 0x18));
  }
  else if ((param_3 < 0) || (2 < param_3)) {
    FUN_000028bc("[%s] unknown type (%d)\n","sceNetcnfifReadEnv");
  }
  else {
    uVar1 = FUN_00001320(param_1,*(undefined4 *)(param_2 + 0x1c));
  }
  return uVar1;
}


================================================================