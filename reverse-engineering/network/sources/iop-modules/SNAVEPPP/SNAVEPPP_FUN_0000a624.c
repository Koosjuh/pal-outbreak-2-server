FUNCTION FUN_0000a624 @ 0x0000a624 size=252
CALLERS (4): FUN_0000d698@0x0000d698, FUN_0000bc4c@0x0000bc4c, FUN_00004f20@0x00004f20, FUN_0000d5a8@0x0000d5a8
CALLEES (4): FUN_00008e30@0x00008e30, FUN_00010c38@0x00010c38, FUN_000096d8@0x000096d8, FUN_000095dc@0x000095dc

void FUN_0000a624(byte *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (((*(int *)(param_1 + 0x30) != 0) && ((param_1[2] & 0xc0) != 0)) &&
     ((*param_1 < 2 || (*param_1 == 6)))) {
    (**(code **)(*(int *)(param_1 + 0x2c) + 0x18))(param_1);
    FUN_000096d8(param_1);
    if ((param_1[2] & 0x80) != 0) {
      FUN_000095dc(param_1);
      if ((DAT_00012efc & 2) != 0) {
        uVar1 = FUN_00008e30(*param_1);
        uVar2 = FUN_00008e30(2);
        FUN_00010c38("  FSM(%s:%s): state ==> %s\n",**(undefined4 **)(param_1 + 0x2c),uVar1,uVar2);
      }
      *param_1 = 2;
    }
  }
  return;
}


================================================================