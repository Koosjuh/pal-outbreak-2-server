FUNCTION FUN_00002314 @ 0x00002314 size=540
CALLERS (1): FUN_00001a94@0x00001a94
CALLEES (4): FUN_00002d04@0x00002d04, FUN_00002d88@0x00002d88, FUN_00002da0@0x00002da0, FUN_00002d90@0x00002d90

undefined1 * FUN_00002314(undefined1 *param_1)

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
  DAT_00004294 = FUN_00002d04();
  DAT_00004264 = DAT_00004294 >> 0x18 | DAT_00004294 >> 8 & 0xff00 | (DAT_00004294 & 0xff00) << 8 |
                 DAT_00004294 << 0x18;
  puVar6 = param_1 + 0x103;
  *(uint *)(param_1 + 4) = DAT_00004264;
  uVar3 = DAT_00004260;
  *(undefined2 *)(param_1 + 10) = 0;
  uVar2 = DAT_00002f91;
  uVar1 = DAT_00002f90;
  *(undefined4 *)(param_1 + 0x1c) = DAT_00002f8c;
  param_1[0x20] = uVar1;
  param_1[0x21] = uVar2;
  param_1[0xf0] = 0x35;
  param_1[0xf3] = 0x3d;
  param_1[0xf4] = 7;
  param_1[0xf1] = 1;
  param_1[0xf2] = 1;
  param_1[0xf5] = 1;
  *(undefined4 *)(param_1 + 0xec) = uVar3;
  uVar2 = DAT_00002f91;
  uVar1 = DAT_00002f90;
  *(undefined4 *)(param_1 + 0xf6) = DAT_00002f8c;
  param_1[0xfa] = uVar1;
  param_1[0xfb] = uVar2;
  param_1[0xfc] = 0x37;
  param_1[0xfd] = 5;
  param_1[0xff] = 3;
  param_1[0x101] = 0xf;
  param_1[0xfe] = 1;
  param_1[0x100] = 6;
  param_1[0x102] = 0x1c;
  if (DAT_0000426c != 0) {
    param_1[0x103] = 0x33;
    param_1[0x104] = 4;
    puVar6 = param_1 + 0x109;
    *(uint *)(param_1 + 0x105) =
         DAT_0000426c >> 0x18 | DAT_0000426c >> 8 & 0xff00 | (DAT_0000426c & 0xff00) << 8 |
         DAT_0000426c << 0x18;
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