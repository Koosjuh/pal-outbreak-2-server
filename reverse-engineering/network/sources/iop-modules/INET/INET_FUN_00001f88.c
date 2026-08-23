FUNCTION FUN_00001f88 @ 0x00001f88 size=876
CALLERS (1): FUN_00002428@0x00002428
CALLEES (3): FUN_00001530@0x00001530, FUN_000015c0@0x000015c0, FUN_00011d90@0x00011d90

void FUN_00001f88(int param_1,ushort *param_2,int param_3)

{
  char cVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  FUN_00011d90(&PTR_DAT_0001b4a4);
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
  FUN_00011d90(s_s__08x_0001b4ec,
               (uint)(byte)param_2[2] << 0x18 | (uint)*(byte *)((int)param_2 + 5) << 0x10 |
               (uint)(byte)param_2[3] << 8 | (uint)*(byte *)((int)param_2 + 7));
  if ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0) {
    FUN_00011d90(s_a__08x_0001b4f4,
                 (uint)(byte)param_2[4] << 0x18 | (uint)*(byte *)((int)param_2 + 9) << 0x10 |
                 (uint)(byte)param_2[5] << 8 | (uint)*(byte *)((int)param_2 + 0xb));
  }
  if ((*(byte *)((int)param_2 + 0xd) & 0x20) != 0) {
    FUN_00011d90(s_u__d_0001b4fc,param_2[9] << 8 | param_2[9] >> 8);
  }
  if ((*(byte *)((int)param_2 + 0xd) & 8) != 0) {
    FUN_00011d90(&DAT_0001b504);
  }
  if ((*(byte *)((int)param_2 + 0xd) & 4) != 0) {
    FUN_00011d90(&DAT_0001b50c);
  }
  if ((*(byte *)((int)param_2 + 0xd) & 2) != 0) {
    FUN_00011d90(&DAT_0001b514);
  }
  if ((*(byte *)((int)param_2 + 0xd) & 1) != 0) {
    FUN_00011d90(&DAT_0001b51c);
  }
  FUN_00011d90(s_w__04x_0001b524,param_2[7] << 8 | param_2[7] >> 8);
  puVar2 = param_2 + 10;
  puVar3 = puVar2 + (uint)(byte)((byte)param_2[6] >> 4) * 2;
  if (puVar2 < puVar3) {
    while (cVar1 = (char)*puVar2, cVar1 != '\0') {
      if (cVar1 == '\x01') {
        puVar2 = (ushort *)((int)puVar2 + 1);
      }
      else {
        if ((((int)puVar3 - (int)puVar2 < 2) || (*(byte *)((int)puVar2 + 1) < 2)) ||
           ((int)puVar3 - (int)puVar2 < (int)(uint)*(byte *)((int)puVar2 + 1))) break;
        if ((cVar1 == '\x02') && (*(byte *)((int)puVar2 + 1) == 4)) {
          FUN_00011d90(s_m__04x_0001b52c,CONCAT11((char)puVar2[1],*(char *)((int)puVar2 + 3)));
        }
        puVar2 = (ushort *)((int)puVar2 + (uint)*(byte *)((int)puVar2 + 1));
      }
      if (puVar3 <= puVar2) break;
    }
  }
  param_3 = param_3 + (uint)(byte)((byte)param_2[6] >> 4) * -4;
  if (0 < param_3) {
    FUN_00011d90(&DAT_0001b4d8,param_3);
  }
  return;
}


================================================================