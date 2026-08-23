FUNCTION FUN_006159c0 @ 0x006159c0  size=152
CALLERS (3): FUN_0060ed40@0x0060ed40, FUN_0060eff0@0x0060eff0, FUN_00615a58@0x00615a58
CALLEES (2): FUN_00616ab0@0x00616ab0, FUN_00615670@0x00615670
----------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006159c0(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  FUN_00615670();
  func_0x00109eb8(0x70d250,param_1);
  uRam0070d248 = param_2;
  func_0x00109eb8(0x70d350,param_3);
  uRam0070d244 = ram0x00654200;
  uRam0070d24c = param_4;
  FUN_00616ab0(0x70d200,0x70d240,2);
  return;
}



================================================================