FUNCTION FUN_000097c0 @ 0x000097c0 size=156
CALLERS (1): FUN_0000985c@0x0000985c
CALLEES (3): FUN_00010070@0x00010070, FUN_00008e30@0x00008e30, FUN_00010c38@0x00010c38

void FUN_000097c0(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_00010070(param_1 + 0x10);
  (**(code **)(*(int *)(param_1 + 0x2c) + 0x1c))(param_1);
  if ((DAT_00012efc & 2) != 0) {
    uVar1 = FUN_00008e30(*param_1);
    uVar2 = FUN_00008e30(5);
    FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar1,uVar2);
  }
  *param_1 = 5;
  return;
}


================================================================