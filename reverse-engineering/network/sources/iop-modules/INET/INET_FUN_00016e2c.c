FUNCTION FUN_00016e2c @ 0x00016e2c size=328
CALLERS (1): FUN_00016f74@0x00016f74
CALLEES (2): FUN_0000a9c0@0x0000a9c0, FUN_0000ae24@0x0000ae24

undefined4 FUN_00016e2c(int param_1,int *param_2)

{
  FUN_0000ae24(param_2,0x4c);
  *param_2 = param_1;
  param_2[1] = 1;
  param_2[2] = *(int *)(param_1 + 0x94);
  param_2[3] = *(int *)(param_1 + 0x80) + *(int *)(param_1 + 0x8c);
  FUN_0000a9c0(param_1 + 0x14,param_2 + 5,4);
  param_2[8] = (uint)*(ushort *)(param_1 + 0x1a);
  FUN_0000a9c0(param_1 + 0x10,param_2 + 10,4);
  param_2[0xd] = (uint)*(ushort *)(param_1 + 0x18);
  switch(*(undefined4 *)(param_1 + 0x28)) {
  case 0:
    param_2[0xe] = 1;
    break;
  case 1:
    param_2[0xe] = 4;
    break;
  case 2:
    param_2[0xe] = 5;
    break;
  case 3:
    param_2[0xe] = 6;
    break;
  case 4:
    param_2[0xe] = 7;
    break;
  case 5:
    param_2[0xe] = 8;
    break;
  case 6:
    param_2[0xe] = 9;
    break;
  case 7:
    param_2[0xe] = 10;
    break;
  case 8:
    param_2[0xe] = 0xb;
    break;
  case 9:
    param_2[0xe] = 0xc;
    break;
  case 10:
    param_2[0xe] = 0xd;
    break;
  default:
    param_2[0xe] = 0;
  }
  return 1;
}


================================================================