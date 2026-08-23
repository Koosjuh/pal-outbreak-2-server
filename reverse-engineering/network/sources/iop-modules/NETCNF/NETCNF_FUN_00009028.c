FUNCTION FUN_00009028 @ 0x00009028 size=128
CALLERS (3): FUN_000018b0@0x000018b0, FUN_00001198@0x00001198, FUN_00000da8@0x00000da8
CALLEES (3): FUN_00009694@0x00009694, FUN_00008f28@0x00008f28, FUN_00008c68@0x00008c68

void FUN_00009028(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((DAT_0000c218 == 0) || (iVar1 = FUN_00008c68(param_1,1), iVar1 == -1)) {
    FUN_00009694(param_1,param_2,param_3);
  }
  else {
    FUN_00008f28(iVar1,param_1,param_2,param_3);
  }
  return;
}


================================================================