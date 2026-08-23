FUNCTION FUN_00616150 @ 0x00616150  size=136
CALLERS (1): FUN_0060ee80@0x0060ee80
CALLEES (2): FUN_00616ab0@0x00616ab0, FUN_00615670@0x00615670
----------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00616150(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  FUN_00615670();
  func_0x00109eb8(0x70d250,param_1);
  uRam0070d248 = param_2;
  func_0x00109eb8(0x70d350,param_3);
  uRam0070d244 = ram0x00654200;
  FUN_00616ab0(0x70d200,0x70d240,10);
  return;
}



================================================================