FUNCTION FUN_005bbe00 @ 0x005bbe00  size=148
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (3): FUN_005bf230@0x005bf230, FUN_005bf1e0@0x005bf1e0, FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005bbe00(undefined8 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_005bf1e0(2);
  iVar2 = (uVar1 & 0xffff) - 1;
  sRam006d2158 = (short)iVar2 + 1;
  *(ushort *)(iVar2 * 0x144 + 0x6cfb70) = (ushort)*(byte *)(param_2 + 4);
  uRam006cbc84 = 0;
  FUN_005bf230(uRam006fec00);
  uRam006cbc84 = 0;
  uRam006cbc7e = 0x10;
  FUN_005bdfe0(0x21);
  return;
}



================================================================