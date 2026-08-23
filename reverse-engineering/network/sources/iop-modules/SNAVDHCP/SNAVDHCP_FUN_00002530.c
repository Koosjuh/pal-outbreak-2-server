FUNCTION FUN_00002530 @ 0x00002530 size=720
CALLERS (1): FUN_00001d38@0x00001d38
CALLEES (3): FUN_00002d88@0x00002d88, FUN_00002da0@0x00002da0, FUN_00002d90@0x00002d90

undefined1 * FUN_00002530(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  
  FUN_00002d90(param_1,0,0x5dc);
  *param_1 = 1;
  param_1[1] = 1;
  param_1[2] = 6;
  param_1[3] = 0;
  uVar3 = DAT_00004264;
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 4) = uVar3;
  if ((DAT_00002eb0 == 4) || (DAT_00002eb0 == 5)) {
    *(undefined4 *)(param_1 + 0xc) = DAT_00004138;
  }
  uVar3 = DAT_00004260;
  uVar2 = DAT_00002f91;
  uVar1 = DAT_00002f90;
  *(undefined4 *)(param_1 + 0x1c) = DAT_00002f8c;
  param_1[0x20] = uVar1;
  param_1[0x21] = uVar2;
  param_1[0xf0] = 0x35;
  param_1[0xf3] = 0x3d;
  param_1[0xf4] = 7;
  param_1[0xf1] = 1;
  param_1[0xf2] = 3;
  param_1[0xf5] = 1;
  *(undefined4 *)(param_1 + 0xec) = uVar3;
  uVar2 = DAT_00002f91;
  uVar1 = DAT_00002f90;
  *(undefined4 *)(param_1 + 0xf6) = DAT_00002f8c;
  param_1[0xfa] = uVar1;
  param_1[0xfb] = uVar2;
  param_1[0xfc] = 0x37;
  param_1[0xfd] = 5;
  param_1[0x100] = 6;
  param_1[0x101] = 0xf;
  param_1[0xfe] = 1;
  param_1[0xff] = 3;
  param_1[0x102] = 0x1c;
  puVar6 = param_1 + 0x103;
  if ((DAT_00002eb0 != 4) && (DAT_00002eb0 != 5)) {
    puVar6 = param_1 + 0x109;
    param_1[0x103] = 0x36;
    param_1[0x104] = 4;
    *(undefined4 *)(param_1 + 0x105) = DAT_00004134;
  }
  if (DAT_0000426c != 0) {
    *puVar6 = 0x33;
    puVar6[1] = 4;
    *(uint *)(puVar6 + 2) =
         DAT_0000426c >> 0x18 | DAT_0000426c >> 8 & 0xff00 | (DAT_0000426c & 0xff00) << 8 |
         DAT_0000426c << 0x18;
    puVar6 = puVar6 + 6;
  }
  if ((DAT_00002eb0 != 4) && (DAT_00002eb0 != 5)) {
    *puVar6 = 0x32;
    puVar6[1] = 4;
    *(undefined4 *)(puVar6 + 2) = DAT_00004138;
    puVar6 = puVar6 + 6;
  }
  uVar4 = FUN_00002da0(&DAT_00004270);
  if ((uVar4 & 0xffff) != 0) {
    *puVar6 = 0xc;
    puVar6[1] = (char)uVar4 + '\x01';
    iVar5 = (uVar4 & 0xffff) + 1;
    FUN_00002d88(puVar6 + 2,&DAT_00004270,iVar5);
    puVar6 = puVar6 + 2 + iVar5;
  }
  *puVar6 = 0xff;
  return puVar6 + (1 - (int)param_1);
}


================================================================