FUNCTION FUN_000096d8 @ 0x000096d8 size=232
CALLERS (6): FUN_0000a624@0x0000a624, FUN_0000a8ec@0x0000a8ec, FUN_0000a720@0x0000a720, FUN_0000a40c@0x0000a40c, FUN_0000d5a8@0x0000d5a8, FUN_0000985c@0x0000985c
CALLEES (2): FUN_00010c38@0x00010c38, FUN_00008e30@0x00008e30

void FUN_000096d8(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_1[2] & 0xc0) == 0) {
    if ((DAT_00012efc & 2) == 0) goto LAB_00009778;
    uVar1 = FUN_00008e30(*param_1);
    uVar2 = 0;
  }
  else {
    if ((DAT_00012efc & 2) == 0) goto LAB_00009778;
    uVar1 = FUN_00008e30(*param_1);
    uVar2 = 1;
  }
  uVar2 = FUN_00008e30(uVar2);
  FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar1,uVar2);
LAB_00009778:
  *param_1 = (param_1[2] & 0xc0) != 0;
  param_1[3] = param_1[4];
  param_1[6] = param_1[7];
  (**(code **)(*(int *)(param_1 + 0x2c) + 0x14))(param_1);
  return;
}


================================================================