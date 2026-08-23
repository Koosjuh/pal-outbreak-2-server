FUNCTION FUN_000020c4 @ 0x000020c4 size=336
CALLERS (1): FUN_00001cb0@0x00001cb0
CALLEES (2): FUN_00010c38@0x00010c38, FUN_00010bb0@0x00010bb0

undefined4 FUN_000020c4(short param_1,short param_2,short param_3,short param_4,short param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  uint local_14;
  undefined2 local_10;
  
  if (param_1 == 0) {
    local_28 = 0;
  }
  else {
    local_28 = (uint)(param_1 == 1);
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      local_24 = 1;
      goto LAB_00002128;
    }
    if (param_2 == 2) {
      local_24 = 0;
      goto LAB_00002128;
    }
  }
  local_24 = 2;
LAB_00002128:
  if ((param_3 == 0) || (param_3 != 1)) {
    local_20 = 0;
  }
  else {
    local_20 = 2;
  }
  local_18 = (int)param_4;
  local_1c = 1;
  if (local_18 == 0) {
    local_18 = 0;
  }
  else if ((((local_18 != 1) && (local_18 != 2)) && (local_18 != 3)) &&
          (((local_18 != 4 && (local_18 != 5)) && (local_18 != 6)))) {
    local_18 = 2;
  }
  local_14 = (uint)(param_5 != 2);
  local_10 = 0;
  iVar1 = FUN_00010bb0(&local_28);
  if (iVar1 == 0) {
    DAT_00012ebc = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
    if ((DAT_00012efc & 1) != 0) {
      FUN_00010c38("aveppp: PP_ComOpen return (ERROR)\n");
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


================================================================