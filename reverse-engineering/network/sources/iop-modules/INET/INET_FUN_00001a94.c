FUNCTION FUN_00001a94 @ 0x00001a94 size=788
CALLERS (1): FUN_00002428@0x00002428
CALLEES (2): FUN_00001530@0x00001530, FUN_00011d90@0x00011d90

void FUN_00001a94(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  char *pcVar2;
  ushort uVar3;
  
  FUN_00011d90(&DAT_0001b49c);
  if ((DAT_0001b850 & 2) != 0) {
    FUN_00011d90(&DAT_0001b45c);
    FUN_00001530((uint)*(byte *)(param_1 + 0x10) << 0x18 | (uint)*(byte *)(param_1 + 0x11) << 0x10 |
                 (uint)*(byte *)(param_1 + 0x12) << 8 | (uint)*(byte *)(param_1 + 0x13));
    FUN_00011d90(&DAT_0001b4bc);
    FUN_00001530((uint)*(byte *)(param_1 + 0xc) << 0x18 | (uint)*(byte *)(param_1 + 0xd) << 0x10 |
                 (uint)*(byte *)(param_1 + 0xe) << 8 | (uint)*(byte *)(param_1 + 0xf));
  }
  bVar1 = *param_2;
  if (bVar1 != 3) {
    if (bVar1 < 4) {
      if (bVar1 == 0) {
        pcVar2 = " ECHO_REPLY-0x%04x";
        uVar3 = *(ushort *)(param_2 + 6) << 8 | *(ushort *)(param_2 + 6) >> 8;
      }
      else {
LAB_00001d6c:
        uVar3 = (ushort)*param_2;
        pcVar2 = s_0x_x_0001b4d0;
      }
    }
    else {
      if (bVar1 != 8) {
        if (bVar1 == 0xb) {
          FUN_00011d90(" TIME_EXCEEDED");
          goto LAB_00001d7c;
        }
        goto LAB_00001d6c;
      }
      pcVar2 = " ECHO_REQUEST-0x%04x";
      uVar3 = *(ushort *)(param_2 + 6) << 8 | *(ushort *)(param_2 + 6) >> 8;
    }
    goto LAB_00001d74;
  }
  FUN_00011d90(" DEST_UNREACH,");
  uVar3 = (ushort)param_2[1];
  switch(uVar3) {
  case 0:
    FUN_00011d90("NET_UNREACH");
    break;
  case 1:
    FUN_00011d90("HOST_UNREACH");
    break;
  case 2:
    FUN_00011d90("PROTO_UNREACH");
    break;
  case 3:
    FUN_00011d90("PORT_UNREACH");
    break;
  case 4:
    FUN_00011d90("FRAG_AND_DF");
    pcVar2 = " Next-Hop-MTU=%d\n";
    uVar3 = *(ushort *)(param_2 + 6) << 8 | *(ushort *)(param_2 + 6) >> 8;
    goto LAB_00001d74;
  case 5:
    FUN_00011d90("SRC_HOST_FAILED");
    break;
  case 6:
    FUN_00011d90("DST_NET_UNKNOWN");
    break;
  case 7:
    FUN_00011d90("DST_HOST_UNKNOWN");
    break;
  case 8:
    FUN_00011d90("SRC_HOST_ISOLATED");
    break;
  case 9:
    FUN_00011d90("NET_ADMIN_PROHIBITED");
    break;
  case 10:
    FUN_00011d90("NET_HOST_PROHIBITED");
    break;
  case 0xb:
    FUN_00011d90(s_NET_TOS_0001b4c0);
    break;
  case 0xc:
    FUN_00011d90("HOST_TOS");
    break;
  default:
    pcVar2 = &DAT_0001b4c8;
LAB_00001d74:
    FUN_00011d90(pcVar2,uVar3);
  }
LAB_00001d7c:
  if (0 < param_3 + -8) {
    FUN_00011d90(&DAT_0001b4d8,param_3 + -8);
  }
  return;
}


================================================================