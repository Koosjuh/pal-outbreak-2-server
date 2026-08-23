FUNCTION FUN_00019444 @ 0x00019444 size=220
CALLERS (1): FUN_00019520@0x00019520
CALLEES (2): FUN_0000a9c0@0x0000a9c0, FUN_0000ae24@0x0000ae24

undefined4 FUN_00019444(int param_1,int *param_2)

{
  int iVar1;
  
  FUN_0000ae24(param_2,0x4c);
  *param_2 = param_1;
  param_2[1] = 2;
  iVar1 = *(int *)(param_1 + 0x24);
  param_2[3] = 0;
  param_2[2] = iVar1;
  FUN_0000a9c0(param_1 + 0x18,param_2 + 5,4);
  param_2[8] = (uint)*(ushort *)(param_1 + 0x1e);
  FUN_0000a9c0(param_1 + 0x14,param_2 + 10,4);
  param_2[0xd] = (uint)*(ushort *)(param_1 + 0x1c);
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 1) {
    param_2[0xe] = 2;
  }
  else if (iVar1 < 2) {
    if (iVar1 == 0) {
      param_2[0xe] = 1;
    }
    else {
      param_2[0xe] = 0;
    }
  }
  else if (iVar1 == 2) {
    param_2[0xe] = 3;
  }
  else {
    param_2[0xe] = 0;
  }
  return 1;
}


================================================================