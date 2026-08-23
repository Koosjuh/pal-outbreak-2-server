FUNCTION FUN_0000985c @ 0x0000985c size=2992
CALLERS (1): FUN_00004550@0x00004550
CALLEES (13): FUN_00010b24@0x00010b24, FUN_00010070@0x00010070, FUN_00009044@0x00009044, FUN_00008f3c@0x00008f3c, FUN_00010c38@0x00010c38, FUN_0000071c@0x0000071c, FUN_000096d8@0x000096d8, FUN_000097c0@0x000097c0, FUN_00008e30@0x00008e30, FUN_000096ac@0x000096ac, FUN_00008ed8@0x00008ed8, FUN_000095dc@0x000095dc, FUN_00009024@0x00009024

void FUN_0000985c(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  short sVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 local_res4 [3];
  undefined1 local_18;
  undefined1 local_17;
  short local_16;
  
  local_res4[0] = param_2;
  sVar2 = FUN_00008f3c(&local_18,local_res4);
  if (sVar2 != 0) {
    if (DAT_00012efc != 0) {
      FUN_00010c38("ave-ppp %s:","PP_fsm_proc");
      FUN_00010c38("ERROR: PP_ntohcnf() failed.\n",0);
    }
    FUN_00010b24(0xffffffff);
    return;
  }
  local_16 = local_16 + -4;
  FUN_0000071c(local_res4,(int)local_16);
  switch(local_18) {
  case 1:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Configure-Request id %d\n",**(undefined4 **)(param_1 + 0x2c),
                   uVar4,local_17);
    }
    switch(*param_1) {
    case 0:
      goto switchD_0000a21c_caseD_0;
    case 3:
      sVar2 = (**(code **)(*(int *)(param_1 + 0x2c) + 0x2c))(param_1,&local_18,local_res4[0]);
      if (sVar2 != 0) {
        FUN_00009024(param_1);
        return;
      }
LAB_00009be8:
      FUN_000097c0(param_1);
      return;
    case 5:
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x20))(param_1);
      FUN_000096d8(param_1);
    case 1:
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x18))(param_1);
      FUN_000095dc(param_1);
    case 2:
    case 4:
      sVar2 = (**(code **)(*(int *)(param_1 + 0x2c) + 0x2c))(param_1,&local_18,local_res4[0]);
      if (sVar2 == 0) {
        if ((DAT_00012efc & 2) != 0) {
          uVar4 = FUN_00008e30(*param_1);
          uVar5 = FUN_00008e30(4);
          FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5)
          ;
        }
        uVar1 = 4;
      }
      else {
        if ((DAT_00012efc & 2) != 0) {
          uVar4 = FUN_00008e30(*param_1);
          uVar5 = FUN_00008e30(2);
          FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5)
          ;
        }
        uVar1 = 2;
      }
      break;
    default:
      goto switchD_0000a39c_caseD_0;
    }
    break;
  case 2:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Configure-Ack id %d\n",**(undefined4 **)(param_1 + 0x2c),
                   uVar4,local_17);
    }
    switch(*param_1) {
    case 0:
    case 1:
      goto switchD_0000a21c_caseD_0;
    case 2:
      sVar2 = (**(code **)(*(int *)(param_1 + 0x2c) + 0x30))(param_1,&local_18,local_res4[0]);
      if (sVar2 != 0) {
        return;
      }
      if ((DAT_00012efc & 2) != 0) {
        uVar4 = FUN_00008e30(*param_1);
        uVar5 = FUN_00008e30(3);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5);
      }
      uVar1 = 3;
      break;
    case 4:
      sVar2 = (**(code **)(*(int *)(param_1 + 0x2c) + 0x30))(param_1,&local_18,local_res4[0]);
      if (sVar2 != 0) {
        return;
      }
      goto LAB_00009be8;
    case 5:
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x20))(param_1);
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x18))(param_1);
      FUN_000096d8(param_1);
    case 3:
      FUN_000095dc(param_1);
      if ((DAT_00012efc & 2) != 0) {
        uVar4 = FUN_00008e30(*param_1);
        uVar5 = FUN_00008e30(2);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5);
      }
      uVar1 = 2;
      break;
    default:
      goto switchD_0000a39c_caseD_0;
    }
    break;
  case 3:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Configure-Nak id %d\n",**(undefined4 **)(param_1 + 0x2c),
                   uVar4,local_17);
    }
    switch(*param_1) {
    case 0:
    case 1:
      goto switchD_0000a21c_caseD_0;
    case 2:
    case 4:
      pcVar3 = *(code **)(*(int *)(param_1 + 0x2c) + 0x34);
LAB_00009e20:
      sVar2 = (*pcVar3)(param_1,&local_18,local_res4[0]);
      if (sVar2 != 0) {
        return;
      }
      FUN_000095dc(param_1);
      return;
    case 5:
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x20))(param_1);
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x18))(param_1);
      FUN_000096d8(param_1);
    case 3:
      FUN_000095dc(param_1);
      if ((DAT_00012efc & 2) != 0) {
        uVar4 = FUN_00008e30(*param_1);
        uVar5 = FUN_00008e30(2);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5);
      }
      uVar1 = 2;
      break;
    default:
      goto switchD_0000a39c_caseD_0;
    }
    break;
  case 4:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Configure-Reject id %d\n",**(undefined4 **)(param_1 + 0x2c),
                   uVar4,local_17);
    }
    switch(*param_1) {
    case 0:
    case 1:
      goto switchD_0000a21c_caseD_0;
    case 2:
    case 4:
      pcVar3 = *(code **)(*(int *)(param_1 + 0x2c) + 0x38);
      goto LAB_00009e20;
    case 5:
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x20))(param_1);
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x18))(param_1);
      FUN_000096d8(param_1);
    case 3:
      FUN_000095dc(param_1);
      if ((DAT_00012efc & 2) != 0) {
        uVar4 = FUN_00008e30(*param_1);
        uVar5 = FUN_00008e30(2);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5);
      }
      uVar1 = 2;
      break;
    default:
      goto switchD_0000a39c_caseD_0;
    }
    break;
  case 5:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Termination-Request id %d\n",
                   **(undefined4 **)(param_1 + 0x2c),uVar4,local_17);
    }
    switch(*param_1) {
    case 3:
    case 4:
      if ((DAT_00012efc & 2) != 0) {
        uVar4 = FUN_00008e30(*param_1);
        uVar5 = FUN_00008e30(2);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5);
      }
      *param_1 = 2;
    case 0:
    case 1:
    case 2:
    case 6:
switchD_0000a21c_caseD_0:
      FUN_000096ac(param_1,local_17);
      return;
    case 5:
      FUN_000096ac(param_1,local_17);
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x20))(param_1);
      break;
    default:
      return;
    }
    goto LAB_0000a160;
  case 6:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Termination-Ack id %d\n",**(undefined4 **)(param_1 + 0x2c),
                   uVar4,local_17);
    }
    switch(*param_1) {
    default:
      goto switchD_0000a39c_caseD_0;
    case 3:
    case 4:
      if ((DAT_00012efc & 2) != 0) {
        uVar4 = FUN_00008e30(*param_1);
        uVar5 = FUN_00008e30(2);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5);
      }
      uVar1 = 2;
      break;
    case 5:
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x20))(param_1);
      FUN_000096d8(param_1);
      sVar2 = FUN_000095dc(param_1);
      if (sVar2 != 0) {
        return;
      }
      if ((DAT_00012efc & 2) != 0) {
        uVar4 = FUN_00008e30(*param_1);
        uVar5 = FUN_00008e30(2);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5);
      }
      uVar1 = 2;
      break;
    case 6:
      FUN_00010070(param_1 + 0x10);
      goto LAB_0000a160;
    }
    break;
  case 7:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Code-Reject id %d\n",**(undefined4 **)(param_1 + 0x2c),uVar4,
                   local_17);
    }
LAB_0000a160:
    (**(code **)(*(int *)(param_1 + 0x2c) + 0x24))(param_1);
    FUN_000096d8(param_1);
    return;
  case 8:
    if ((DAT_00012efc & 2) == 0) {
      return;
    }
    uVar4 = FUN_00008e30(*param_1);
    pcVar6 = "  FSM(%s:%s): recv Protocol-Reject id %d\n";
    goto LAB_0000a2e0;
  case 9:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Echo-Request id %d\n",**(undefined4 **)(param_1 + 0x2c),uVar4
                   ,local_17);
    }
    switch(*param_1) {
    case 0:
    case 1:
      goto switchD_0000a21c_caseD_0;
    default:
      return;
    case 5:
      FUN_00009044(param_1,10,local_17,local_res4[0]);
      return;
    }
  case 10:
    if ((DAT_00012efc & 2) == 0) {
      return;
    }
    uVar4 = FUN_00008e30(*param_1);
    pcVar6 = "  FSM(%s:%s): recv Echo-Reply id %d\n";
    goto LAB_0000a2e0;
  case 0xb:
    if ((DAT_00012efc & 2) == 0) {
      return;
    }
    uVar4 = FUN_00008e30(*param_1);
    pcVar6 = "  FSM(%s:%s): recv Discard-Request id %d\n";
    goto LAB_0000a2e0;
  case 0xc:
    if ((DAT_00012efc & 2) == 0) {
      return;
    }
    uVar4 = FUN_00008e30(*param_1);
    pcVar6 = "  FSM(%s:%s): recv Quality-Report id %d\n";
LAB_0000a2e0:
    FUN_00010c38(pcVar6,**(undefined4 **)(param_1 + 0x2c),uVar4,local_17);
    return;
  default:
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): recv Unknown-code(%d) id %d\n",**(undefined4 **)(param_1 + 0x2c),
                   uVar4,local_18,local_17);
    }
    local_16 = local_16 + 4;
    local_res4[0] = FUN_00008ed8(&local_18,local_res4[0]);
    FUN_00009044(param_1,7,local_17,local_res4[0]);
    switch(*param_1) {
    default:
      goto switchD_0000a39c_caseD_0;
    case 2:
    case 3:
    case 4:
    case 5:
      uVar1 = 1;
      if ((DAT_00012efc & 2) != 0) {
        uVar4 = FUN_00008e30(*param_1);
        uVar5 = FUN_00008e30(1);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar4,uVar5);
        uVar1 = 1;
      }
    }
  }
  *param_1 = uVar1;
switchD_0000a39c_caseD_0:
  return;
}


================================================================