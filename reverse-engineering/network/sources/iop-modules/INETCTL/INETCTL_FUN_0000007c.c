FUNCTION FUN_0000007c @ 0x0000007c size=72
CALLERS (3): FUN_0000332c@0x0000332c, FUN_00002540@0x00002540, FUN_00000a4c@0x00000a4c
CALLEES (3): FUN_00003ed0@0x00003ed0, FUN_00003ed8@0x00003ed8, FUN_00003ea4@0x00003ea4

undefined4 FUN_0000007c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_10 [2];
  
  FUN_00003ed0(local_10);
  uVar1 = FUN_00003ea4(0,param_1,0);
  FUN_00003ed8(local_10[0]);
  return uVar1;
}


================================================================