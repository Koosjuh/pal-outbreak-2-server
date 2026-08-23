FUNCTION FUN_00001120 @ 0x00001120 size=380
CALLERS (1): FUN_00000a80@0x00000a80
CALLEES (6): FUN_00008234@0x00008234, FUN_0000818c@0x0000818c, FUN_00008184@0x00008184, FUN_00008194@0x00008194, FUN_0000822c@0x0000822c, FUN_000081a4@0x000081a4

undefined4 FUN_00001120(undefined4 param_1)

{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  code *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  DAT_0000d940 = 0x2000;
  DAT_0000d948 = &DAT_00009940;
  DAT_0000d950 = &DAT_00009940;
  DAT_0000d94c = &DAT_00009940;
  DAT_0000d944 = 0;
  DAT_0000d958 = 0x2000;
  DAT_0000d960 = &DAT_0000b940;
  DAT_0000d968 = &DAT_0000b940;
  DAT_0000d964 = &DAT_0000b940;
  DAT_0000d95c = 0;
  if (DAT_0000d978 != 0) {
    FUN_00008234(DAT_0000d97c);
    DAT_0000d978 = 0;
  }
  local_28 = 0;
  local_20 = 1;
  local_1c = 1;
  local_24 = 0;
  iVar1 = FUN_0000822c(&local_28);
  if (-1 < iVar1) {
    DAT_0000d97c = iVar1;
    if (DAT_0000d970 != 0) {
      FUN_000081a4(DAT_0000d974);
      FUN_0000818c(DAT_0000d974);
      DAT_0000d970 = 0;
    }
    local_40 = 0x2000000;
    local_38 = FUN_00001804;
    local_34 = 0x1000;
    local_3c = 0;
    local_30 = DAT_00009704;
    iVar1 = FUN_00008184(&local_40);
    if (-1 < iVar1) {
      DAT_0000d974 = iVar1;
      iVar1 = FUN_00008194(iVar1,param_1);
      if (-1 < iVar1) {
        DAT_0000d970 = 1;
        DAT_0000d978 = 1;
        return 0;
      }
      FUN_0000818c(DAT_0000d974);
    }
    FUN_00008234(DAT_0000d97c);
  }
  return 0xffffffff;
}


================================================================