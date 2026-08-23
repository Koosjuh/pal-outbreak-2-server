FUNCTION FUN_00010130 @ 0x00010130 size=196
CALLERS (1): FUN_0000053c@0x0000053c
CALLEES (2): FUN_00003e40@0x00003e40, FUN_0000d7fc@0x0000d7fc

undefined4 FUN_00010130(ushort *param_1,undefined4 *param_2,undefined2 *param_3,undefined2 *param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined4 local_18;
  undefined2 local_14;
  undefined2 local_12;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x80) == 0) {
    iVar2 = FUN_0000d7fc((int)(short)uVar1,&local_18);
    if (iVar2 << 0x10 < 0) {
      return 0xfffffffc;
    }
    *param_2 = local_18;
    *param_3 = local_14;
    local_1a = local_12;
  }
  else {
    iVar2 = FUN_00003e40(uVar1 & 0x7f,&local_20);
    if (iVar2 << 0x10 < 0) {
      return 0xfffffffc;
    }
    *param_2 = local_20;
    *param_3 = local_1c;
  }
  *param_4 = local_1a;
  return 0;
}


================================================================