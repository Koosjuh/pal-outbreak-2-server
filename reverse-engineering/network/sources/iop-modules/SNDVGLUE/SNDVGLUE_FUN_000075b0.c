FUNCTION FUN_000075b0 @ 0x000075b0 size=324
CALLERS (2): FUN_000076f4@0x000076f4, FUN_000074ac@0x000074ac
CALLEES (1): FUN_00008044@0x00008044

int FUN_000075b0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined1 param_5,
                uint param_6,uint param_7)

{
  int iVar1;
  ushort local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  ushort local_1c;
  ushort local_1a;
  
  local_1d = param_5;
  FUN_00008044(param_1,param_2,6);
  FUN_00008044(param_1 + 6,param_3,6);
  local_20 = (ushort)((param_4 & 0xff) << 8) | (ushort)(param_4 >> 8) & 0xff;
  FUN_00008044(param_1 + 0xc,&local_20,2);
  local_1e = 0x11;
  FUN_00008044(param_1 + 0xe,&local_1e,1);
  FUN_00008044(param_1 + 0xf,&local_1d,1);
  local_1c = (ushort)((param_6 & 0xff) << 8) | (ushort)(param_6 >> 8) & 0xff;
  FUN_00008044(param_1 + 0x10,&local_1c,2);
  local_1a = (ushort)((param_7 & 0xff) << 8) | (ushort)(param_7 >> 8) & 0xff;
  FUN_00008044(param_1 + 0x12,&local_1a,2);
  iVar1 = (param_7 + 0x14) * 0x10000;
  if ((int)((param_7 + 0x14) * 0x10000) >> 0x10 < 0x3c) {
    iVar1 = 0x3c0000;
  }
  return iVar1 >> 0x10;
}


================================================================