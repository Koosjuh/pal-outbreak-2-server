FUNCTION FUN_00002340 @ 0x00002340 size=116
CALLERS (1): FUN_000003c0@0x000003c0
CALLEES (3): FUN_000027d4@0x000027d4, FUN_000027dc@0x000027dc, FUN_00002890@0x00002890

int FUN_00002340(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  
  local_10 = param_3 & 0xffffffc0;
  if ((param_3 & 0x3f) != 0) {
    local_10 = local_10 + 0x40;
  }
  local_c = 0;
  local_18 = param_1;
  local_14 = param_2;
  do {
    FUN_000027d4(&DAT_00006410);
    iVar1 = FUN_00002890(&local_18,1);
    FUN_000027dc(DAT_00006410);
  } while (iVar1 == 0);
  return iVar1;
}


================================================================