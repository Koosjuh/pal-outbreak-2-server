FUNCTION FUN_0000a40c @ 0x0000a40c size=536
CALLERS (0): 
CALLEES (5): FUN_00009650@0x00009650, FUN_00010c38@0x00010c38, FUN_000096d8@0x000096d8, FUN_000095dc@0x000095dc, FUN_00008e30@0x00008e30

void FUN_0000a40c(char *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  switch(*param_1) {
  default:
    goto switchD_0000a444_caseD_0;
  case '\x02':
  case '\x03':
  case '\x04':
    if (param_1[3] != '\0') {
      if ((DAT_00012efc & 2) != 0) {
        uVar2 = FUN_00008e30(*param_1);
        FUN_00010c38("  FSM(%s:%s): rexmt(retry %d)\n",**(undefined4 **)(param_1 + 0x2c),uVar2,
                     param_1[3]);
      }
      FUN_000095dc(param_1);
      if (*param_1 != '\x03') {
        return;
      }
      if ((DAT_00012efc & 2) != 0) {
        uVar2 = FUN_00008e30(3);
        uVar1 = FUN_00008e30(2);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar2,uVar1);
      }
      *param_1 = '\x02';
      return;
    }
    if ((DAT_00012efc & 2) != 0) {
      uVar2 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): timeout ==> fsm reset\n",**(undefined4 **)(param_1 + 0x2c),uVar2);
    }
    break;
  case '\x06':
    if (param_1[3] != '\0') {
      if ((DAT_00012efc & 2) != 0) {
        uVar2 = FUN_00008e30(*param_1);
        FUN_00010c38("  FSM(%s:%s): rexmt(retry %d)\n",**(undefined4 **)(param_1 + 0x2c),uVar2,
                     param_1[3]);
      }
      FUN_00009650(param_1);
      return;
    }
    if ((DAT_00012efc & 2) != 0) {
      uVar2 = FUN_00008e30(*param_1);
      FUN_00010c38("  FSM(%s:%s): timeout ==> fsm reset\n",**(undefined4 **)(param_1 + 0x2c),uVar2);
    }
    (**(code **)(*(int *)(param_1 + 0x2c) + 0x24))(param_1);
  }
  FUN_000096d8(param_1);
  param_1[8] = '\x01';
  param_1[9] = '\0';
switchD_0000a444_caseD_0:
  return;
}


================================================================