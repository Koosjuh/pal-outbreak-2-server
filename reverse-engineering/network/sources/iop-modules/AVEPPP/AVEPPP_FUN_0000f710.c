FUNCTION FUN_0000f710 @ 0x0000f710 size=740
CALLERS (3): FUN_0000efbc@0x0000efbc, FUN_0000e90c@0x0000e90c, FUN_0000f42c@0x0000f42c
CALLEES (3): FUN_00000884@0x00000884, FUN_000005b0@0x000005b0, FUN_00010b3c@0x00010b3c

undefined4 * FUN_0000f710(ushort *param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  ushort extraout_var;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort local_60;
  ushort local_5e;
  uint local_5c;
  uint local_58;
  char local_54;
  byte local_53;
  ushort local_52;
  ushort local_50;
  ushort local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  
  uVar4 = 0;
  if (*(byte *)((int)param_1 + 0x1b) - 1 < 0x28) {
    uVar4 = (uint)*(byte *)((int)param_1 + 0x1b);
  }
  else if (param_1[9] != 0) {
    uVar4 = 4;
  }
  uVar4 = uVar4 + 0x14;
  puVar2 = (undefined4 *)FUN_00000884(param_2,(int)(uVar4 * 0x10000) >> 0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar5 = *puVar2;
    local_60 = *param_1 << 8 | *param_1 >> 8;
    local_5e = param_1[1] << 8 | param_1[1] >> 8;
    uVar3 = *(uint *)(param_1 + 2);
    local_5c = uVar3 >> 0x18 | uVar3 >> 8 & 0xff00 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = *(uint *)(param_1 + 4);
    local_54 = (char)uVar4 * '\x04';
    local_58 = uVar3 >> 0x18 | uVar3 >> 8 & 0xff00 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    local_53 = (*(char *)((int)param_1 + 0x15) != '\0') << 5;
    if ((char)param_1[0xb] != '\0') {
      local_53 = local_53 | 0x10;
    }
    if (*(char *)((int)param_1 + 0x17) != '\0') {
      local_53 = local_53 | 8;
    }
    if ((char)param_1[0xc] != '\0') {
      local_53 = local_53 | 4;
    }
    if (*(char *)((int)param_1 + 0x19) != '\0') {
      local_53 = local_53 | 2;
    }
    if ((char)param_1[0xd] != '\0') {
      local_53 = local_53 | 1;
    }
    local_52 = param_1[6] << 8 | param_1[6] >> 8;
    if (param_3 == 0) {
      local_50 = param_1[7] << 8 | param_1[7] >> 8;
    }
    else {
      local_50 = 0;
    }
    local_4e = param_1[8] << 8 | param_1[8] >> 8;
    if (0x14 < uVar4) {
      if (param_1[9] == 0) {
        FUN_00010b3c(&local_4a,param_1 + 0xe,*(undefined1 *)((int)param_1 + 0x1b));
      }
      else {
        local_4c = 2;
        local_4b = 4;
        local_4a = (undefined1)(param_1[9] >> 8);
        local_49 = (undefined1)param_1[9];
      }
    }
    FUN_00010b3c(uVar5,&local_60,uVar4);
    if (param_3 != 0) {
      sVar1 = FUN_000005b0(param_3,puVar2,*(undefined2 *)(param_3 + 10));
      FUN_000005b0(param_3,puVar2,*(undefined2 *)(param_3 + 10));
      local_50 = sVar1 << 8 | extraout_var & 0xff;
    }
    FUN_00010b3c(uVar5,&local_60,uVar4);
  }
  return puVar2;
}


================================================================