FUNCTION FUN_0000402c @ 0x0000402c size=228
CALLERS (1): FUN_000030cc@0x000030cc
CALLEES (2): FUN_0000e90c@0x0000e90c, FUN_00004110@0x00004110

int FUN_0000402c(undefined4 param_1)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 local_18 [2];
  
  uVar2 = 0x21;
  if (DAT_000149fc != '\x05') goto LAB_000040cc;
  local_18[0] = param_1;
  if ((*(ushort *)(DAT_00014a2c + 0x74) & 4) != 0) {
    sVar1 = FUN_0000e90c(*(undefined4 *)(DAT_00014a2c + 0x98),local_18,
                         *(undefined1 *)(DAT_00014a2c + 0x84));
    if (sVar1 == 0x70) {
      uVar2 = 0x2f;
    }
    else if (sVar1 < 0x71) {
      if (sVar1 != 0x40) {
LAB_000040cc:
        DAT_00014a7c = DAT_00014a7c + 1;
        return -1;
      }
    }
    else {
      uVar2 = 0x2d;
      if (sVar1 != 0x80) goto LAB_000040cc;
    }
  }
  sVar1 = FUN_00004110(0,0,uVar2,local_18[0]);
  return (int)sVar1;
}


================================================================