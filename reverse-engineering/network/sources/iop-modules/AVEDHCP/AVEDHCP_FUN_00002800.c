FUNCTION FUN_00002800 @ 0x00002800 size=428
CALLERS (1): FUN_00002150@0x00002150
CALLEES (4): FUN_00002d04@0x00002d04, FUN_00002da0@0x00002da0, FUN_00002d88@0x00002d88, FUN_00002d90@0x00002d90

undefined1 * FUN_00002800(undefined1 *param_1)

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
  puVar6 = param_1 + 0x102;
  *(uint *)(param_1 + 4) = DAT_00004264;
  *(undefined4 *)(param_1 + 0xc) = DAT_00004138;
  uVar3 = DAT_00004260;
  uVar2 = DAT_00002f91;
  uVar1 = DAT_00002f90;
  *(undefined4 *)(param_1 + 0x1c) = DAT_00002f8c;
  param_1[0x20] = uVar1;
  param_1[0x21] = uVar2;
  param_1[0xf1] = 1;
  param_1[0xf2] = 7;
  param_1[0xf4] = 7;
  param_1[0xf5] = 1;
  *(undefined4 *)(param_1 + 0xec) = uVar3;
  param_1[0xf0] = 0x35;
  param_1[0xf3] = 0x3d;
  uVar2 = DAT_00002f91;
  uVar1 = DAT_00002f90;
  *(undefined4 *)(param_1 + 0xf6) = DAT_00002f8c;
  param_1[0xfa] = uVar1;
  param_1[0xfb] = uVar2;
  param_1[0xfc] = 0x36;
  param_1[0xfd] = 4;
  *(undefined4 *)(param_1 + 0xfe) = DAT_00004134;
  uVar4 = FUN_00002da0(&DAT_00004270);
  if ((uVar4 & 0xffff) != 0) {
    iVar5 = (uVar4 & 0xffff) + 1;
    param_1[0x102] = 0xc;
    param_1[0x103] = (char)uVar4 + '\x01';
    FUN_00002d88(param_1 + 0x104,&DAT_00004270,iVar5);
    puVar6 = param_1 + 0x104 + iVar5;
  }
  *puVar6 = 0xff;
  return puVar6 + (1 - (int)param_1);
}


================================================================