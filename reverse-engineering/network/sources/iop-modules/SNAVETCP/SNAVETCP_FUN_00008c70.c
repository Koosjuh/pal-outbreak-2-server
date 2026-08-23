FUNCTION FUN_00008c70 @ 0x00008c70 size=340
CALLERS (1): FUN_0000dbac@0x0000dbac
CALLEES (5): FUN_00001454@0x00001454, FUN_0000139c@0x0000139c, FUN_0000a79c@0x0000a79c, FUN_00011d00@0x00011d00, FUN_000010c0@0x000010c0

undefined4 FUN_00008c70(undefined4 *param_1,short param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_38;
  undefined1 local_34;
  short local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  undefined1 auStack_28 [4];
  undefined1 local_24;
  undefined1 auStack_20 [4];
  undefined1 local_1c;
  
  local_24 = 1;
  local_1c = 1;
  if (((*(uint *)(param_3 + 0xd8) & 1) == 0) && (iVar1 = FUN_0000a79c(param_3), iVar1 != 0)) {
    return 0xffffffff;
  }
  uVar2 = 0xffffffff;
  if (*(uint *)(param_3 + 8) <= (uint)(int)DAT_0001619e) {
    local_38 = *param_1;
    local_34 = 3;
    local_2e = 0;
    local_30 = param_2;
    local_2c = param_4;
    FUN_0000139c(auStack_28,&local_38);
    FUN_00011d00(auStack_20,param_3,8);
    if (*(int *)(param_3 + 0x10) != 0) {
      FUN_00001454(auStack_20,(*(int *)(param_3 + 0x10) << 0x14) >> 0x10);
    }
    FUN_000010c0(auStack_20,auStack_28,0x10);
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + (int)param_2;
    uVar3 = (uint)DAT_0001619e;
    *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 1;
    if (*(uint *)(param_3 + 0x10) < uVar3) {
      *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) + 1;
    }
    else {
      *(undefined4 *)(param_3 + 0x10) = 0;
    }
    uVar2 = 0;
    *(uint *)(param_3 + 0xd8) = *(uint *)(param_3 + 0xd8) | 1;
  }
  return uVar2;
}


================================================================