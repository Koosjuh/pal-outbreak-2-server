FUNCTION FUN_0000f5f8 @ 0x0000f5f8 size=112
CALLERS (1): FUN_000054a8@0x000054a8
CALLEES (1): FUN_00010a84@0x00010a84

int FUN_0000f5f8(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10 [4];
  
  local_20[0] = 0;
  local_14 = 0;
  local_1c = param_1;
  local_18 = param_2;
  sVar1 = FUN_00010a84(0x4105,local_20,local_20);
  iVar2 = 0;
  if (sVar1 != 0) {
    local_10[0] = 0;
    FUN_00010a84(0x4106,local_10,local_10);
    iVar2 = FUN_00010a84(0x4105,local_20,local_20);
    iVar2 = iVar2 << 0x10;
  }
  return iVar2 >> 0x10;
}


================================================================