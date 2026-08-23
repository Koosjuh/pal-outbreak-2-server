FUNCTION FUN_00001da8 @ 0x00001da8 size=480
CALLERS (1): FUN_00002428@0x00002428
CALLEES (2): FUN_00001530@0x00001530, FUN_00011d90@0x00011d90

void FUN_00001da8(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  
  FUN_00011d90(&DAT_0001b4e0);
  if ((DAT_0001b850 & 2) != 0) {
    FUN_00011d90(&DAT_0001b45c);
    FUN_00001530((uint)*(byte *)(param_1 + 0x10) << 0x18 | (uint)*(byte *)(param_1 + 0x11) << 0x10 |
                 (uint)*(byte *)(param_1 + 0x12) << 8 | (uint)*(byte *)(param_1 + 0x13));
    FUN_00011d90(&DAT_0001b4bc);
    FUN_00001530((uint)*(byte *)(param_1 + 0xc) << 0x18 | (uint)*(byte *)(param_1 + 0xd) << 0x10 |
                 (uint)*(byte *)(param_1 + 0xe) << 8 | (uint)*(byte *)(param_1 + 0xf));
  }
  bVar1 = *param_2;
  if (bVar1 == 0x12) {
    FUN_00011d90(" V1_MEMBERSHIP_REPORT");
    goto LAB_00001f00;
  }
  if (bVar1 < 0x13) {
    if (bVar1 == 0x11) {
      FUN_00011d90(" MEMBERSHIP_QUERY");
      goto LAB_00001f00;
    }
  }
  else {
    if (bVar1 == 0x16) {
      FUN_00011d90(" V2_MEMBERSHIP_REPORT");
      goto LAB_00001f00;
    }
    if (bVar1 == 0x17) {
      FUN_00011d90(" LEAVE_GROUP");
      goto LAB_00001f00;
    }
  }
  FUN_00011d90(s_0x_x_0001b4d0,*param_2);
LAB_00001f00:
  if (param_2[1] != 0) {
    FUN_00011d90(" code=%d",param_2[1]);
  }
  FUN_00011d90(" group=%<IADR>",
               (uint)param_2[4] << 0x18 | (uint)param_2[5] << 0x10 | (uint)param_2[6] << 8 |
               (uint)param_2[7]);
  if (0 < param_3 + -8) {
    FUN_00011d90(&DAT_0001b4d8,param_3 + -8);
  }
  return;
}


================================================================