FUNCTION FUN_00009044 @ 0x00009044 size=1432
CALLERS (10): FUN_0000985c@0x0000985c, FUN_0000dcfc@0x0000dcfc, FUN_0000b3d8@0x0000b3d8, FUN_00006aec@0x00006aec, FUN_00004550@0x00004550, FUN_000095dc@0x000095dc, FUN_000096ac@0x000096ac, FUN_000067bc@0x000067bc, FUN_00009650@0x00009650, FUN_0000cc4c@0x0000cc4c
CALLEES (7): FUN_00001c20@0x00001c20, FUN_00000710@0x00000710, FUN_00008e30@0x00008e30, FUN_00008ed8@0x00008ed8, FUN_00010c38@0x00010c38, FUN_00010ae4@0x00010ae4, FUN_00004110@0x00004110

int FUN_00009044(undefined1 *param_1,int param_2,char param_3,undefined4 *param_4)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  undefined1 local_20;
  char local_1f;
  short local_1e;
  
  iVar7 = *(int *)(param_1 + 0xc);
  if (param_4 == (undefined4 *)0x0) {
    param_4 = &DAT_0001a354;
    DAT_0001a358 = 0;
    DAT_0001a354 = (int)&DAT_0001a354 + (DAT_00016fc0 + 0x83U & 0xfffffffc);
  }
  local_20 = (undefined1)param_2;
  switch(param_2) {
  case 1:
  case 5:
  case 9:
    param_1[1] = *(undefined1 *)(iVar7 + 1);
  case 8:
  case 0xb:
    local_1f = *(char *)(iVar7 + 1);
    *(char *)(iVar7 + 1) = local_1f + '\x01';
    break;
  case 2:
  case 3:
  case 4:
  case 6:
  case 7:
  case 10:
    local_1f = param_3;
    break;
  default:
    goto switchD_000090b8_default;
  }
  if ((param_2 < 0xc) && (8 < param_2)) {
    FUN_00001c20(*param_4,*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x28));
  }
  local_1e = FUN_00000710(param_4);
  local_1e = local_1e + 4;
  piVar3 = (int *)FUN_00008ed8(&local_20,param_4);
  if (piVar3 == (int *)0x0) {
switchD_000090b8_default:
    return -1;
  }
  iVar7 = iVar7 + (uint)*(byte *)(*(int *)(param_1 + 0x2c) + 8) * 2;
  *(short *)(iVar7 + 0xe4) = *(short *)(iVar7 + 0xe4) + 1;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x2c) + 4);
  switch(param_2) {
  case 1:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Configure-Request id %d\n";
LAB_000093a0:
      FUN_00010c38(pcVar6,**(undefined4 **)(param_1 + 0x2c),uVar4,local_1f);
      goto switchD_0000918c_default;
    }
    break;
  case 2:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Configure-Ack id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 3:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Configure-Nak id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 4:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Configure-Reject id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 5:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Termination-Request id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 6:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Termination-Ack id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 7:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Code-Reject id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 8:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Protocol-Reject id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 9:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Echo-Request id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 10:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Echo-Reply id %d\n";
      goto LAB_000093a0;
    }
    break;
  case 0xb:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      pcVar6 = "  FSM(%s:%s): send Discard-Request id %d\n";
      goto LAB_000093a0;
    }
    break;
  default:
switchD_0000918c_default:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00010ae4();
      FUN_00010c38("%010u ",uVar4);
    }
  }
  if (uVar1 == 0xc021) {
    if ((DAT_00012efc & 2) == 0) goto LAB_000095a4;
    FUN_00010c38("PPP SEND [LCP]\n");
  }
  else if (uVar1 < 0xc022) {
    if (uVar1 == 0x8021) {
      if ((DAT_00012efc & 2) == 0) goto LAB_000095a4;
      FUN_00010c38("PPP SEND [IPCP]\n");
    }
    else {
LAB_000094d8:
      if ((DAT_00012efc & 2) == 0) goto LAB_000095a4;
      FUN_00010c38("PPP SEND [unknown protocol = %04x]\n",uVar1);
    }
  }
  else if (uVar1 == 0xc023) {
    if ((DAT_00012efc & 2) == 0) goto LAB_000095a4;
    FUN_00010c38("PPP SEND [PAP]\n");
  }
  else {
    if (uVar1 != 0xc223) goto LAB_000094d8;
    if ((DAT_00012efc & 2) == 0) goto LAB_000095a4;
    FUN_00010c38("PPP SEND [CHAP]\n");
  }
  if ((DAT_00012efc & 2) != 0) {
    uVar8 = 0;
    if ((short)piVar3[1] != 0) {
      do {
        FUN_00010c38("%02x ",*(undefined1 *)(*piVar3 + uVar8));
        uVar5 = uVar8;
        if ((int)uVar8 < 0) {
          uVar5 = uVar8 + 0xf;
        }
        if (uVar8 + ((int)uVar5 >> 4) * -0x10 == 0xf) {
          FUN_00010c38(&DAT_0001224c);
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)(uint)*(ushort *)(piVar3 + 1));
    }
    if ((uVar8 & 0xf) != 0) {
      FUN_00010c38(&DAT_0001224c);
    }
  }
LAB_000095a4:
  sVar2 = FUN_00004110(0,0,*(undefined2 *)(*(int *)(param_1 + 0x2c) + 4),piVar3);
  return (int)sVar2;
}


================================================================