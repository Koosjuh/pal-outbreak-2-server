FUNCTION FUN_00005888 @ 0x00005888 size=328
CALLERS (1): FUN_00000bf0@0x00000bf0
CALLEES (2): FUN_00008044@0x00008044, FUN_00006b50@0x00006b50

/* WARNING: Type propagation algorithm not settling */

int FUN_00005888(short param_1,int param_2,uint param_3)

{
  short sVar1;
  int iVar2;
  undefined1 local_20;
  undefined1 local_1f;
  ushort local_1e;
  ushort local_1c [2];
  
  if ((param_1 == 0) && (DAT_0000de90 == 4)) {
    local_20 = 0x11;
    FUN_00008044(param_2 + 0xe,&local_20,1);
    local_1f = 0;
    FUN_00008044(param_2 + 0xf,&local_1f,1);
    local_1e = DAT_0000de92 << 8 | DAT_0000de92 >> 8;
    FUN_00008044(param_2 + 0x10,&local_1e,2);
    local_1c[0] = (ushort)((param_3 & 0xff) << 8) | (ushort)(param_3 >> 8) & 0xff;
    FUN_00008044(param_2 + 0x12,local_1c,2);
    local_1c[1] = 0x6488;
    FUN_00008044(param_2,DAT_0000deb0,6);
    FUN_00008044(param_2 + 6,&DAT_0000dea0,6);
    FUN_00008044(param_2 + 0xc,local_1c + 1,2);
    DAT_0000e6b4 = (undefined2)(param_3 + 0x14);
    if ((param_3 + 0x14 & 0xffff) < 0x3c) {
      DAT_0000e6b4 = 0x3c;
    }
    sVar1 = FUN_00006b50(param_2,DAT_0000e6b4);
    iVar2 = (int)sVar1;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


================================================================