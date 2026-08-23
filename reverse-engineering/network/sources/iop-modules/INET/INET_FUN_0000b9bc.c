FUNCTION FUN_0000b9bc @ 0x0000b9bc size=196
CALLERS (1): FUN_0000ba80@0x0000ba80
CALLEES (2): FUN_0000ae24@0x0000ae24, FUN_0000a9c0@0x0000a9c0

undefined4 FUN_0000b9bc(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  FUN_0000ae24(param_2,0x4c);
  *param_2 = param_1;
  param_2[1] = 3;
  iVar1 = *(int *)(param_1 + 0x1c);
  param_2[3] = 0;
  param_2[2] = iVar1;
  FUN_0000a9c0(local_20,param_2 + 5,4);
  param_2[8] = *(int *)(param_1 + 0x14);
  FUN_0000a9c0(local_20,param_2 + 10,4);
  param_2[0xd] = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
    param_2[0xe] = 1;
  }
  else if (*(int *)(param_1 + 0xc) == 1) {
    param_2[0xe] = 3;
  }
  else {
    param_2[0xe] = 0;
  }
  return 1;
}


================================================================