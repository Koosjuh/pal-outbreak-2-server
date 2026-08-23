FUNCTION FUN_000027d8 @ 0x000027d8 size=544
CALLERS (1): FUN_000029f8@0x000029f8
CALLEES (3): FUN_00001574@0x00001574, FUN_00001530@0x00001530, FUN_00011d90@0x00011d90

void FUN_000027d8(short param_1,int param_2)

{
  ushort uVar1;
  undefined *puVar2;
  
  puVar2 = &DAT_0001b550;
  if (param_1 == -0x7fcb) {
    puVar2 = &DAT_0001b570;
  }
  FUN_00011d90(s__sARP_0001b568,puVar2);
  uVar1 = *(ushort *)(param_2 + 6) << 8 | *(ushort *)(param_2 + 6) >> 8;
  if (uVar1 == 2) {
    FUN_00011d90(&DAT_0001b578);
    goto LAB_000028cc;
  }
  if (uVar1 < 3) {
    if (uVar1 == 1) {
      FUN_00011d90(&DAT_0001b574);
      goto LAB_000028cc;
    }
  }
  else {
    if (uVar1 == 3) {
      FUN_00011d90(s_REQ_REV_0001b57c);
      goto LAB_000028cc;
    }
    if (uVar1 == 4) {
      FUN_00011d90(s_REP_REV_0001b584);
      goto LAB_000028cc;
    }
  }
  FUN_00011d90(&DAT_0001b4c8,*(ushort *)(param_2 + 6) << 8 | *(ushort *)(param_2 + 6) >> 8);
LAB_000028cc:
  if (((ushort)(*(ushort *)(param_2 + 6) << 8 | *(ushort *)(param_2 + 6) >> 8) == 2) ||
     ((DAT_0001b850 & 2) != 0)) {
    FUN_00011d90(s_src__0001b58c);
    FUN_00001574(param_2 + 8);
    FUN_00011d90(&DAT_0001b4e8);
    FUN_00001530((uint)*(byte *)(param_2 + 0xe) << 0x18 | (uint)*(byte *)(param_2 + 0xf) << 0x10 |
                 (uint)*(byte *)(param_2 + 0x10) << 8 | (uint)*(byte *)(param_2 + 0x11));
  }
  if (((ushort)(*(ushort *)(param_2 + 6) << 8 | *(ushort *)(param_2 + 6) >> 8) == 1) ||
     ((DAT_0001b850 & 2) != 0)) {
    FUN_00011d90(s_targ__0001b594);
    FUN_00001574(param_2 + 0x12);
    FUN_00011d90(&DAT_0001b4e8);
    FUN_00001530((uint)*(byte *)(param_2 + 0x18) << 0x18 | (uint)*(byte *)(param_2 + 0x19) << 0x10 |
                 (uint)*(byte *)(param_2 + 0x1a) << 8 | (uint)*(byte *)(param_2 + 0x1b));
    FUN_00011d90(&DAT_0001b45c);
  }
  return;
}


================================================================