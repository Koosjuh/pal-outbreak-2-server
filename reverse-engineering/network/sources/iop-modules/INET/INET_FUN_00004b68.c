FUNCTION FUN_00004b68 @ 0x00004b68 size=4372
CALLERS (1): FUN_0001866c@0x0001866c
CALLEES (15): FUN_000016ec@0x000016ec, FUN_00004a94@0x00004a94, FUN_0000ae24@0x0000ae24, FUN_00017bf4@0x00017bf4, FUN_00004670@0x00004670, FUN_00009eec@0x00009eec, FUN_00017ad8@0x00017ad8, FUN_0000e148@0x0000e148, FUN_00000994@0x00000994, FUN_00011d90@0x00011d90, FUN_000043a8@0x000043a8, FUN_000048fc@0x000048fc, FUN_00001530@0x00001530, FUN_00003780@0x00003780, FUN_00001574@0x00001574

int FUN_00004b68(int param_1,short param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  undefined *puVar10;
  undefined1 auStack_50 [4];
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  puVar10 = (undefined *)0x0;
  piVar9 = DAT_0001b680;
  if (DAT_0001b680 == (int *)0x0) {
    return param_4;
  }
  do {
    if (param_1 == piVar9[2]) break;
    piVar9 = (int *)*piVar9;
  } while (piVar9 != (int *)0x0);
  if (piVar9 == (int *)0x0) {
    return param_4;
  }
  if (param_2 != 0x44) {
    return param_4;
  }
  puVar4 = *(undefined1 **)(param_4 + 0x10);
  if ((uint)(*(int *)(param_4 + 0x14) - (int)puVar4) < 0xf4) goto LAB_00005c44;
  uVar3 = *(undefined4 *)(puVar4 + 4);
  puVar4[4] = (char)((uint)uVar3 >> 0x18);
  puVar4[5] = (char)((uint)uVar3 >> 0x10);
  puVar4[6] = (char)((uint)uVar3 >> 8);
  puVar4[7] = (char)uVar3;
  *(ushort *)(puVar4 + 8) = *(ushort *)(puVar4 + 8) << 8 | *(ushort *)(puVar4 + 8) >> 8;
  *(ushort *)(puVar4 + 10) = *(ushort *)(puVar4 + 10) << 8 | *(ushort *)(puVar4 + 10) >> 8;
  uVar3 = *(undefined4 *)(puVar4 + 0xc);
  puVar4[0xc] = (char)((uint)uVar3 >> 0x18);
  puVar4[0xd] = (char)((uint)uVar3 >> 0x10);
  puVar4[0xe] = (char)((uint)uVar3 >> 8);
  puVar4[0xf] = (char)uVar3;
  uVar3 = *(undefined4 *)(puVar4 + 0x10);
  puVar4[0x10] = (char)((uint)uVar3 >> 0x18);
  puVar4[0x11] = (char)((uint)uVar3 >> 0x10);
  puVar4[0x12] = (char)((uint)uVar3 >> 8);
  puVar4[0x13] = (char)uVar3;
  uVar3 = *(undefined4 *)(puVar4 + 0x14);
  puVar4[0x14] = (char)((uint)uVar3 >> 0x18);
  puVar4[0x15] = (char)((uint)uVar3 >> 0x10);
  puVar4[0x16] = (char)((uint)uVar3 >> 8);
  puVar4[0x17] = (char)uVar3;
  uVar3 = *(undefined4 *)(puVar4 + 0x18);
  puVar4[0x18] = (char)((uint)uVar3 >> 0x18);
  puVar4[0x19] = (char)((uint)uVar3 >> 0x10);
  puVar4[0x1a] = (char)((uint)uVar3 >> 8);
  puVar4[0x1b] = (char)uVar3;
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: dhcp_rcv\n");
    FUN_00011d90(" op=0x%x",*puVar4);
    FUN_00011d90(" htype=0x%x",puVar4[1]);
    FUN_00011d90(" hlen=0x%x",puVar4[2]);
    FUN_00011d90(" hops=0x%x",puVar4[3]);
    FUN_00011d90(" xid=0x%lx",*(undefined4 *)(puVar4 + 4));
    FUN_00011d90(" secs=0x%x",*(undefined2 *)(puVar4 + 8));
    FUN_00011d90(" flags=0x%x",*(undefined2 *)(puVar4 + 10));
    FUN_00011d90(&DAT_0001b6d0);
    FUN_00011d90(" ciaddr=");
    FUN_00001530(*(undefined4 *)(puVar4 + 0xc));
    FUN_00011d90(" yiaddr=");
    FUN_00001530(*(undefined4 *)(puVar4 + 0x10));
    FUN_00011d90(" siaddr=");
    FUN_00001530(*(undefined4 *)(puVar4 + 0x14));
    FUN_00011d90(" giaddr=");
    FUN_00001530(*(undefined4 *)(puVar4 + 0x18));
    FUN_00011d90(&DAT_0001b6d0);
    FUN_00011d90(" chaddr=");
    FUN_00001574(puVar4 + 0x1c);
    FUN_00011d90(" sname=\"%s\"",puVar4 + 0x2c);
    FUN_00011d90(" file=\"%s\"",puVar4 + 0x6c);
    FUN_00011d90(&DAT_0001b6d0);
    FUN_00011d90(" options:\n");
    FUN_000016ec(0,puVar4 + 0xec,(*(int *)(param_4 + 0x14) + -0xec) - (int)puVar4);
  }
  FUN_0000ae24(auStack_50,0x24);
  pcVar8 = *(char **)(param_4 + 0x14);
  if ((((puVar4[0xec] == DAT_0001b120) && (puVar4[0xed] == DAT_0001b121)) &&
      (puVar4[0xee] == DAT_0001b122)) && (puVar4[0xef] == DAT_0001b123)) {
    pcVar6 = puVar4 + 0xf0;
    while (pcVar6 < pcVar8) {
      if (*pcVar6 == '\0') {
        pcVar6 = pcVar6 + 1;
      }
      else {
        if (((*pcVar6 == -1) || (pcVar8 + -1 <= pcVar6)) || (pcVar8 < pcVar6 + (byte)pcVar6[1] + 2))
        break;
        switch(*pcVar6) {
        case '\x01':
          iVar7 = (byte)pcVar6[1] + 2;
          if ((byte)pcVar6[1] == 4) {
            uVar2 = *(uint *)(pcVar6 + 2);
            local_4c = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
            break;
          }
          goto LAB_000054c0;
        case '\x03':
          if (3 < (byte)pcVar6[1]) {
            uVar2 = *(uint *)(pcVar6 + 2);
            local_48 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
          }
          break;
        case '\x06':
          if (3 < (byte)pcVar6[1]) {
            uVar2 = *(uint *)(pcVar6 + 2);
            local_44 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
          }
          if (7 < (byte)pcVar6[1]) {
            uVar2 = *(uint *)(pcVar6 + 6);
            local_40 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
          }
          break;
        case '3':
          iVar7 = (byte)pcVar6[1] + 2;
          if ((byte)pcVar6[1] != 4) goto LAB_000054c0;
          uVar2 = *(uint *)(pcVar6 + 2);
          local_38 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
          break;
        case '5':
          if (pcVar6[1] == '\x01') {
            puVar10 = (undefined *)(uint)(byte)pcVar6[2];
          }
          break;
        case '6':
          iVar7 = (byte)pcVar6[1] + 2;
          if ((byte)pcVar6[1] != 4) goto LAB_000054c0;
          uVar2 = *(uint *)(pcVar6 + 2);
          local_3c = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
          break;
        case ':':
          iVar7 = (byte)pcVar6[1] + 2;
          if ((byte)pcVar6[1] != 4) goto LAB_000054c0;
          uVar2 = *(uint *)(pcVar6 + 2);
          local_34 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
          break;
        case ';':
          iVar7 = (byte)pcVar6[1] + 2;
          if ((byte)pcVar6[1] != 4) goto LAB_000054c0;
          uVar2 = *(uint *)(pcVar6 + 2);
          local_30 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
        }
        iVar7 = (byte)pcVar6[1] + 2;
LAB_000054c0:
        pcVar6 = pcVar6 + iVar7;
      }
    }
  }
  if (puVar10 == (undefined *)0x0) {
    if (((piVar9[7] == 1) || (piVar9[7] == 3)) && (iVar7 = FUN_00004a94(piVar9,puVar4), iVar7 == 0))
    {
      if (param_1 != 0) {
        if (*(int *)(param_1 + 0x70) == 0) {
          *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(puVar4 + 0x10);
        }
        if ((*(uint *)(param_1 + 0x70) != 0) && (*(int *)(param_1 + 0x74) == 0)) {
          uVar2 = *(uint *)(param_1 + 0x70) >> 0x1e;
          if (local_4c == 0) {
            if (uVar2 == 2) {
              uVar1 = 0xffff0000;
            }
            else {
              uVar1 = 0xff000000;
              if ((1 < uVar2) && (uVar1 = 0xffffff00, uVar2 != 3)) goto LAB_00005ae0;
            }
            local_4c = uVar1;
          }
LAB_00005ae0:
          if (param_1 == 0) goto LAB_00005b50;
          *(uint *)(param_1 + 0x74) = local_4c;
        }
        if (param_1 != 0) {
          if (*(int *)(param_1 + 0x7c) == 0) {
            *(uint *)(param_1 + 0x7c) = local_48;
          }
          if (*(int *)(param_1 + 0x80) == 0) {
            *(uint *)(param_1 + 0x80) = local_44;
          }
          if (*(int *)(param_1 + 0x1b0) == 0) {
            *(uint *)(param_1 + 0x1b0) = local_40;
          }
        }
      }
LAB_00005b50:
      if ((DAT_0001b850 & 0x20) != 0) {
        FUN_00011d90("bootp: the following addresses are updated for %s\n",param_1 + 8);
        FUN_00011d90(s_ipadr__0001b6b8);
        uVar3 = 0;
        if (param_1 != 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x70);
        }
        FUN_00001530(uVar3);
        FUN_00011d90(s_ipmsk__0001b6c0);
        uVar3 = 0;
        if (param_1 != 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x74);
        }
        FUN_00001530(uVar3);
        FUN_00011d90(s_gwadr__0001b6c8);
        uVar3 = 0;
        if (param_1 != 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x7c);
        }
        FUN_00001530(uVar3);
        FUN_00011d90(" nsadr1=");
        uVar3 = 0;
        if (param_1 != 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x80);
        }
        FUN_00001530(uVar3);
        FUN_00011d90(" nsadr2=");
        uVar3 = 0;
        if (param_1 != 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x1b0);
        }
        FUN_00001530(uVar3);
        FUN_00011d90(&DAT_0001b6d0);
      }
      iVar7 = FUN_00017bf4(piVar9[3]);
      piVar9[3] = iVar7;
      piVar9[7] = 3;
      FUN_0000e148(param_1);
    }
  }
  else {
    if ((DAT_0001b850 & 0x20) != 0) {
      if (puVar10 + -1 < (undefined *)0x8) {
        iVar7 = piVar9[7];
        pcVar8 = "DHCP: Rcv DHCP%s state=%d\n";
        puVar5 = (&PTR_s_DISCOVER_0001b13c)[(int)(puVar10 + -1)];
      }
      else {
        pcVar8 = "DHCP: Rcv msgtype=%d state=%d\n";
        iVar7 = piVar9[7];
        puVar5 = puVar10;
      }
      FUN_00011d90(pcVar8,puVar5,iVar7);
    }
    switch(piVar9[7]) {
    case 1:
      if (((puVar10 == (undefined *)0x2) && (iVar7 = FUN_00004a94(piVar9,puVar4), iVar7 == 0)) &&
         (piVar9[8] == 0)) {
        piVar9[8] = *(int *)(puVar4 + 0x10);
        piVar9[9] = local_4c;
        piVar9[10] = local_48;
        piVar9[0xb] = local_44;
        piVar9[0xc] = local_40;
        piVar9[0xd] = local_3c;
        piVar9[0x20] = 0;
        piVar9[0xe] = local_38;
        iVar7 = FUN_00017bf4(piVar9[3]);
        piVar9[3] = iVar7;
        piVar9[0x16] = (int)FUN_00003f0c;
        piVar9[0x17] = 0;
        piVar9[0x19] = piVar9[0xd];
        piVar9[0x18] = piVar9[8];
        piVar9[0x1a] = *(int *)(puVar4 + 4);
        FUN_00003780(piVar9);
        piVar9[7] = 2;
      }
      break;
    case 2:
      if (puVar10 == (undefined *)0x5) {
        if ((((piVar9[6] == 0) && (iVar7 = FUN_00004a94(piVar9,puVar4), iVar7 == 0)) &&
            (local_3c != 0)) && (iVar7 = FUN_000048fc(auStack_50,piVar9 + 8), iVar7 == 0)) {
          if ((piVar9[9] == 0) && (piVar9[9] = local_4c, local_4c == 0)) {
            uVar2 = (uint)piVar9[8] >> 0x1e;
            if (uVar2 == 2) {
              iVar7 = -0x10000;
            }
            else {
              iVar7 = -0x1000000;
              if ((1 < uVar2) && (iVar7 = -0x100, uVar2 != 3)) goto LAB_00005728;
            }
            piVar9[9] = iVar7;
          }
LAB_00005728:
          if (piVar9[10] == 0) {
            piVar9[10] = local_48;
          }
          if (piVar9[0xb] == 0) {
            piVar9[0xb] = local_44;
          }
          if (piVar9[0xc] == 0) {
            piVar9[0xc] = local_40;
          }
          piVar9[0xd] = local_3c;
          iVar7 = FUN_00017ad8(FUN_00004754,piVar9,piVar9[0x1f]);
          piVar9[6] = iVar7;
          FUN_00000994(piVar9[2],piVar9[8]);
        }
      }
      else if ((((undefined *)0x5 < puVar10) && (puVar10 == (undefined *)0x6)) &&
              (iVar7 = FUN_00004a94(piVar9,puVar4), iVar7 == 0)) {
        if (local_3c == 0) {
          if (*(int *)(puVar4 + 0x14) == piVar9[0xd]) {
            piVar9[7] = 0;
LAB_00005a00:
            FUN_000043a8(piVar9);
          }
        }
        else if (local_3c == piVar9[0xd]) {
          piVar9[7] = 0;
          goto LAB_00005a00;
        }
      }
      break;
    case 4:
      if (puVar10 == (undefined *)0x5) {
        iVar7 = FUN_00004a94(piVar9,puVar4);
        if ((iVar7 == 0) && (iVar7 = FUN_000048fc(auStack_50,piVar9 + 8), iVar7 == 0)) {
          piVar9[0x13] = piVar9[0xe];
          piVar9[0x14] = piVar9[0xf];
          piVar9[0x15] = piVar9[0x10];
          FUN_00004670(piVar9);
          uVar2 = DAT_0001b850 & 0x20;
          piVar9[7] = 3;
          if (uVar2 != 0) {
            pcVar8 = "DHCP: renewing %s";
LAB_00005958:
            FUN_00011d90(pcVar8,param_1 + 8);
            FUN_00011d90(s_ipadr__0001b6b8);
            uVar3 = 0;
            if (param_1 != 0) {
              uVar3 = *(undefined4 *)(param_1 + 0x70);
            }
            FUN_00001530(uVar3);
            FUN_00011d90(&DAT_0001b6d0);
          }
        }
      }
      else if ((puVar10 == (undefined *)0x6) && (iVar7 = FUN_00004a94(piVar9,puVar4), iVar7 == 0)) {
        if (local_3c != 0) goto LAB_000059f0;
LAB_000059b4:
        if (*(int *)(puVar4 + 0x14) == piVar9[0xd]) goto LAB_00005a00;
      }
      break;
    case 5:
      if (puVar10 == (undefined *)0x5) {
        iVar7 = FUN_00004a94(piVar9,puVar4);
        if (((iVar7 == 0) && (local_3c != 0)) &&
           (iVar7 = FUN_000048fc(auStack_50,piVar9 + 8), iVar7 == 0)) {
          piVar9[0xd] = local_3c;
          piVar9[0x13] = piVar9[0xe];
          piVar9[0x14] = piVar9[0xf];
          piVar9[0x15] = piVar9[0x10];
          FUN_00004670(piVar9);
          uVar2 = DAT_0001b850 & 0x20;
          piVar9[7] = 3;
          if (uVar2 != 0) {
            pcVar8 = "DHCP: rebinding %s";
            goto LAB_00005958;
          }
        }
      }
      else if ((puVar10 == (undefined *)0x6) && (iVar7 = FUN_00004a94(piVar9,puVar4), iVar7 == 0)) {
        if (local_3c == 0) goto LAB_000059b4;
LAB_000059f0:
        if (local_3c == piVar9[0xd]) goto LAB_00005a00;
      }
    }
  }
LAB_00005c44:
  iVar7 = FUN_00009eec(param_4);
  return iVar7;
}


================================================================