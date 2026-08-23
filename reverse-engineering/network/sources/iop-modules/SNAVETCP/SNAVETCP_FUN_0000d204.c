FUNCTION FUN_0000d204 @ 0x0000d204 size=408
CALLERS (1): FUN_00010d2c@0x00010d2c
CALLEES (1): FUN_0000e08c@0x0000e08c

undefined4 FUN_0000d204(short param_1,short param_2,uint *param_3,ushort *param_4)

{
  short sVar1;
  int iVar2;
  uint local_20;
  
  sVar1 = FUN_0000e08c((int)param_1);
  if (sVar1 != 0) {
    return 0xfffffffc;
  }
  iVar2 = DAT_00016180 + param_1 * 0x17c;
  if (param_2 == 0x2001) {
    if (*param_4 < 4) {
      return 0xfffffff3;
    }
    *param_3 = *(uint *)(iVar2 + 0x178);
  }
  else if (param_2 < 0x2002) {
    if (param_2 != 8) {
      return 0xfffffff3;
    }
    if (*param_4 < 4) {
      return 0xfffffff3;
    }
    *param_3 = (int)((uint)*(ushort *)(iVar2 + 0x16c) << 0x10) >> 0x11;
  }
  else {
    if (param_2 != 0x2008) {
      return 0xfffffff3;
    }
    if (*param_4 < 4) {
      return 0xfffffff3;
    }
    local_20 = (uint)((*(byte *)(iVar2 + 0x13f) & 4) != 0);
    *param_3 = local_20;
  }
  *param_4 = 4;
  return 0;
}


================================================================