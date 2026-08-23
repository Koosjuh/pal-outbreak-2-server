FUNCTION FUN_00010060 @ 0x00010060 size=116
CALLERS (1): FUN_000004d0@0x000004d0
CALLEES (3): FUN_00004c24@0x00004c24, FUN_000034a8@0x000034a8, FUN_0000d39c@0x0000d39c

int FUN_00010060(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *param_1;
  if ((uVar1 & 0xc0) == 0x80) {
    iVar2 = FUN_000034a8(uVar1 & 0x3f);
    iVar2 = iVar2 << 0x10;
  }
  else if ((uVar1 & 0xc0) == 0xc0) {
    iVar2 = FUN_00004c24(uVar1 & 0x3f);
    iVar2 = iVar2 << 0x10;
  }
  else {
    iVar2 = FUN_0000d39c((int)(short)*param_1);
    iVar2 = iVar2 << 0x10;
  }
  return iVar2 >> 0x10;
}


================================================================