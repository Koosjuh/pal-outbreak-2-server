FUNCTION FUN_00000288 @ 0x00000288 size=80
CALLERS (0): 
CALLEES (1): FUN_00000168@0x00000168

undefined4 FUN_00000288(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_000025c8;
  if ((param_3 != 0x4401) && (uVar1 = 0, param_3 == 0x4402)) {
    FUN_00000168();
    uVar1 = 0;
  }
  return uVar1;
}


================================================================