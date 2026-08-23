FUNCTION FUN_0000414c @ 0x0000414c size=52
CALLERS (2): FUN_000047dc@0x000047dc, FUN_000046d4@0x000046d4
CALLEES (1): FUN_0000e944@0x0000e944

undefined4 FUN_0000414c(short param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = FUN_0000e944((int)param_1);
  uVar2 = 0xffffffff;
  if (sVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}


================================================================