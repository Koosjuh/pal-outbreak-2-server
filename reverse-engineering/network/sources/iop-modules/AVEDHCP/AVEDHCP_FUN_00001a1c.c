FUNCTION FUN_00001a1c @ 0x00001a1c size=120
CALLERS (1): FUN_00000164@0x00000164
CALLEES (2): FUN_0000046c@0x0000046c, FUN_00002da0@0x00002da0

undefined4 FUN_00001a1c(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  DAT_00002f50 = 0;
  if ((param_1 == 0) || (sVar1 = FUN_00002da0(param_1), 0x1e < (ushort)(sVar1 - 1U))) {
    DAT_00002f50 = 1;
    uVar2 = 0xffffffff;
  }
  else {
    FUN_0000046c(0x10,(int)sVar1,param_1);
    uVar2 = 0;
  }
  return uVar2;
}


================================================================