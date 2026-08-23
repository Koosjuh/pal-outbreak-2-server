FUNCTION FUN_0000d058 @ 0x0000d058 size=428
CALLERS (1): FUN_00010ce4@0x00010ce4
CALLEES (1): FUN_0000e08c@0x0000e08c

undefined4 FUN_0000d058(short param_1,short param_2,uint *param_3,ushort param_4)

{
  short sVar1;
  int iVar2;
  short local_28;
  
  sVar1 = FUN_0000e08c((int)param_1);
  if (sVar1 != 0) {
    return 0xfffffffc;
  }
  iVar2 = DAT_00016180 + param_1 * 0x17c;
  if (param_2 == 0x2001) {
    if (param_4 != 4) {
      return 0xfffffff3;
    }
    if (1 < *param_3) {
      return 0xfffffff3;
    }
    *(uint *)(iVar2 + 0x178) = *param_3;
  }
  else if (param_2 < 0x2002) {
    if (param_2 != 8) {
      return 0xfffffff3;
    }
    if (param_4 < 4) {
      return 0xfffffff3;
    }
    local_28 = (short)*param_3;
    *(undefined2 *)(iVar2 + 0x110) = 0;
    *(short *)(iVar2 + 0x16c) = local_28 << 1;
    *(short *)(iVar2 + 0x128) = local_28 << 1;
  }
  else {
    if (param_2 != 0x2008) {
      return 0xfffffff3;
    }
    if (param_4 != 4) {
      return 0xfffffff3;
    }
    if (1 < *param_3) {
      return 0xfffffff3;
    }
    if (*param_3 == 1) {
      *(byte *)(iVar2 + 0x13f) = *(byte *)(iVar2 + 0x13f) | 4;
    }
    else {
      *(byte *)(iVar2 + 0x13f) = *(byte *)(iVar2 + 0x13f) & 0xfb;
    }
  }
  return 0;
}


================================================================