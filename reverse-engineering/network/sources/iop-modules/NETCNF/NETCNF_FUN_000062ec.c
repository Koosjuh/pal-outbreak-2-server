FUNCTION FUN_000062ec @ 0x000062ec size=100
CALLERS (1): FUN_00006740@0x00006740
CALLEES (3): FUN_00004150@0x00004150, FUN_00005f2c@0x00005f2c, FUN_00004dd0@0x00004dd0

undefined4 FUN_000062ec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00004150(param_1,0x160,2);
  *(int *)(param_1 + 0x1c) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0xfffffffe;
  }
  else {
    FUN_00004dd0(iVar1);
    uVar2 = FUN_00005f2c(param_1,*(undefined4 *)(param_1 + 4),FUN_000058d0,
                         *(undefined4 *)(param_1 + 0x1c));
  }
  return uVar2;
}


================================================================