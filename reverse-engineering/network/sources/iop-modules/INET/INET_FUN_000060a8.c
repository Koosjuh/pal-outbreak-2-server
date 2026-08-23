FUNCTION FUN_000060a8 @ 0x000060a8 size=344
CALLERS (6): FUN_0000709c@0x0000709c, FUN_00009f28@0x00009f28, FUN_0000db2c@0x0000db2c, FUN_00007e28@0x00007e28, FUN_00006478@0x00006478, FUN_000067c4@0x000067c4
CALLEES (1): FUN_00006040@0x00006040

uint FUN_000060a8(uint param_1,ushort *param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  
  if (((uint)param_2 & 1) == 0) {
    if (0x1f < (int)param_3) {
      switch((int)param_2 >> 1 & 7) {
      case 1:
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 - 2;
        param_1 = param_1 + uVar1;
      case 2:
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 - 2;
        param_1 = param_1 + uVar1;
      case 3:
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 - 2;
        param_1 = param_1 + uVar1;
      case 4:
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 - 2;
        param_1 = param_1 + uVar1;
      case 5:
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 - 2;
        param_1 = param_1 + uVar1;
      case 6:
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 - 2;
        param_1 = param_1 + uVar1;
      case 7:
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 - 2;
        param_1 = param_1 + uVar1;
      default:
        param_1 = FUN_00006040(param_1,param_2,param_3 & 0xfffffff0);
        param_2 = (ushort *)((int)param_2 + (param_3 & 0xfffffff0));
        param_3 = param_3 & 0xf;
      }
    }
    for (; 1 < (int)param_3; param_3 = param_3 - 2) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + uVar1;
    }
    if ((param_3 & 1) != 0) {
      param_1 = param_1 + (byte)*param_2;
    }
    for (; uVar2 = param_1 & 0xffff, param_1 >> 0x10 != 0; param_1 = uVar2 + (param_1 >> 0x10)) {
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


================================================================