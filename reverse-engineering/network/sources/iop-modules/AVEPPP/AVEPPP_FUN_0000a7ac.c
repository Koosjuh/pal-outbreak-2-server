FUNCTION FUN_0000a7ac @ 0x0000a7ac size=320
CALLERS (6): FUN_0000d8c0@0x0000d8c0, FUN_0000dc38@0x0000dc38, FUN_000075b0@0x000075b0, FUN_000066dc@0x000066dc, FUN_00005e78@0x00005e78, FUN_0000d9a8@0x0000d9a8
CALLEES (3): FUN_00009650@0x00009650, FUN_00010c38@0x00010c38, FUN_00008e30@0x00008e30

void FUN_0000a7ac(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x30) == 0) {
    return;
  }
  switch(*param_1) {
  default:
    goto switchD_0000a7f4_caseD_0;
  case 1:
    if ((DAT_00012efc & 2) != 0) {
      uVar1 = FUN_00008e30(*param_1);
      uVar2 = FUN_00008e30(0);
      FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar1,uVar2);
    }
    *param_1 = 0;
    return;
  case 2:
  case 3:
    param_1[3] = 0;
    break;
  case 5:
    (**(code **)(*(int *)(param_1 + 0x2c) + 0x20))(param_1);
  case 4:
    param_1[3] = param_1[5];
    FUN_00009650(param_1);
  }
  if ((DAT_00012efc & 2) != 0) {
    uVar1 = FUN_00008e30(*param_1);
    uVar2 = FUN_00008e30(6);
    FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar1,uVar2);
  }
  *param_1 = 6;
switchD_0000a7f4_caseD_0:
  return;
}


================================================================