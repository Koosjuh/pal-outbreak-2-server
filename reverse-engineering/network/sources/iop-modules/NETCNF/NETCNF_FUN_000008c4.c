FUNCTION FUN_000008c4 @ 0x000008c4 size=128
CALLERS (1): FUN_00004728@0x00004728
CALLEES (3): FUN_00009618@0x00009618, FUN_00007e20@0x00007e20, FUN_00009610@0x00009610

undefined4 FUN_000008c4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18 [2];
  
  uVar2 = 0xffffffff;
  local_18[0] = 0;
  if ((param_2 == 0) || (iVar1 = FUN_00007e20(local_18), iVar1 != 0)) {
    FUN_00009618(param_1,0x14);
    FUN_00009610(local_18,param_1 + 4,4);
    uVar2 = 0;
  }
  return uVar2;
}


================================================================