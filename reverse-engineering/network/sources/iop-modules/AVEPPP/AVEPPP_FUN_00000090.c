FUNCTION FUN_00000090 @ 0x00000090 size=616
CALLERS (3): FUN_0000f42c@0x0000f42c, FUN_0000e90c@0x0000e90c, FUN_0000efbc@0x0000efbc
CALLEES (3): FUN_00000884@0x00000884, FUN_00010b3c@0x00010b3c, FUN_000005b0@0x000005b0

undefined4 * FUN_00000090(uint *param_1,undefined4 param_2,short param_3)

{
  short sVar1;
  ushort extraout_var;
  undefined4 *puVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined4 uVar6;
  byte local_60;
  undefined1 local_5f;
  ushort local_5e;
  ushort local_5c;
  ushort local_5a;
  undefined1 local_58;
  undefined1 local_57;
  ushort local_56;
  uint local_54;
  uint local_50;
  undefined1 auStack_4c [44];
  
  uVar5 = *(byte *)((int)param_1 + 0x17) + 0x14;
  if (0x40 < uVar5) {
    uVar5 = 0x40;
  }
  puVar2 = (undefined4 *)FUN_00000884(param_2,uVar5);
  uVar6 = *puVar2;
  local_60 = (byte)(uVar5 >> 2) | *(char *)((int)param_1 + 0x13) << 4;
  local_5f = (undefined1)param_1[5];
  local_5e = (ushort)param_1[2] << 8 | (ushort)param_1[2] >> 8;
  local_5c = *(ushort *)((int)param_1 + 10) << 8 | *(ushort *)((int)param_1 + 10) >> 8;
  uVar3 = (uint)(ushort)((ushort)param_1[3] >> 3);
  if (*(char *)((int)param_1 + 0x11) != '\0') {
    uVar3 = uVar3 | 0x4000;
  }
  if (*(char *)((int)param_1 + 0x12) != '\0') {
    uVar3 = uVar3 | 0x2000;
  }
  local_5a = (ushort)(uVar3 << 8) | (ushort)(uVar3 >> 8);
  local_58 = *(undefined1 *)((int)param_1 + 0x15);
  local_57 = *(undefined1 *)((int)param_1 + 0x16);
  if (param_3 == 0) {
    local_56 = 0;
  }
  else {
    local_56 = *(ushort *)((int)param_1 + 0xe) << 8 | *(ushort *)((int)param_1 + 0xe) >> 8;
  }
  uVar3 = *param_1;
  local_54 = uVar3 >> 0x18 | uVar3 >> 8 & 0xff00 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = param_1[1];
  local_50 = uVar3 >> 0x18 | uVar3 >> 8 & 0xff00 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar4 = 0x2c;
  if (*(byte *)((int)param_1 + 0x17) != 0) {
    if (*(byte *)((int)param_1 + 0x17) < 0x2c) {
      uVar4 = *(undefined1 *)((int)param_1 + 0x17);
    }
    FUN_00010b3c(auStack_4c,param_1 + 6,uVar4);
  }
  FUN_00010b3c(uVar6,&local_60,uVar5);
  if (param_3 == 0) {
    sVar1 = FUN_000005b0(0,puVar2,uVar5);
    FUN_000005b0(0,puVar2,uVar5);
    local_56 = sVar1 << 8 | extraout_var & 0xff;
  }
  FUN_00010b3c(uVar6,&local_60,uVar5);
  return puVar2;
}


================================================================