FUNCTION FUN_00001938 @ 0x00001938 size=300
CALLERS (1): FUN_00000318@0x00000318
CALLEES (8): FUN_00000b9c@0x00000b9c, FUN_00000c9c@0x00000c9c, FUN_000022a8@0x000022a8, FUN_00002164@0x00002164, FUN_000021b4@0x000021b4, FUN_00002290@0x00002290, FUN_00002298@0x00002298, FUN_000022b0@0x000022b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00001938(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10 [2];
  
  _DAT_bf801420 = 0x51011;
  _DAT_bf801418 = 0xe01a3043;
  _DAT_bf80141c = 0xef1a3043;
  if ((_DAT_bf80146c & 4) == 0) {
    _DAT_bf801466 = 1;
    _DAT_bf801464 = 0;
    _DAT_bf801460 = 0;
    iVar1 = FUN_00000c9c();
    if (iVar1 != 0) {
      return 1;
    }
  }
  iVar1 = FUN_00000b9c(param_1);
  uVar2 = 1;
  if (iVar1 == 0) {
    FUN_000022a8(local_10);
    FUN_00002290(0xd,1,FUN_000018f4,0);
    FUN_00002298(0xd);
    FUN_000022b0(local_10[0]);
    _DAT_bf801466 = 0;
    iVar1 = FUN_000021b4(0x500);
    uVar2 = 1;
    if (iVar1 == 0) {
      FUN_00002164("dev9: CXD9611(ssbus buffer) driver start\n");
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================