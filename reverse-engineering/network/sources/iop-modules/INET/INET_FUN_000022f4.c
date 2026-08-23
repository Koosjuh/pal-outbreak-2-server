FUNCTION FUN_000022f4 @ 0x000022f4 size=308
CALLERS (1): FUN_00002428@0x00002428
CALLEES (3): FUN_00001530@0x00001530, FUN_000015c0@0x000015c0, FUN_00011d90@0x00011d90

void FUN_000022f4(int param_1,ushort *param_2,int param_3)

{
  FUN_00011d90(&PTR_DAT_0001b4ac);
  if ((DAT_0001b850 & 2) != 0) {
    FUN_00001530((uint)*(byte *)(param_1 + 0x10) << 0x18 | (uint)*(byte *)(param_1 + 0x11) << 0x10 |
                 (uint)*(byte *)(param_1 + 0x12) << 8 | (uint)*(byte *)(param_1 + 0x13));
    FUN_00011d90(&DAT_0001b4e8);
  }
  FUN_000015c0(param_2[1] << 8 | param_2[1] >> 8);
  FUN_00011d90(&DAT_0001b4bc);
  if ((DAT_0001b850 & 2) != 0) {
    FUN_00001530((uint)*(byte *)(param_1 + 0xc) << 0x18 | (uint)*(byte *)(param_1 + 0xd) << 0x10 |
                 (uint)*(byte *)(param_1 + 0xe) << 8 | (uint)*(byte *)(param_1 + 0xf));
    FUN_00011d90(&DAT_0001b4e8);
  }
  FUN_000015c0(*param_2 << 8 | *param_2 >> 8);
  if (0 < param_3 + -8) {
    FUN_00011d90(&DAT_0001b4d8,param_3 + -8);
  }
  return;
}


================================================================