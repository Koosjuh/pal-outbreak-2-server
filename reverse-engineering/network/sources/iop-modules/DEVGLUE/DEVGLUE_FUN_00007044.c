FUNCTION FUN_00007044 @ 0x00007044 size=148
CALLERS (2): FUN_000072d8@0x000072d8, FUN_00007394@0x00007394
CALLEES (1): FUN_00008044@0x00008044

undefined4 FUN_00007044(int *param_1,int param_2)

{
  int iVar1;
  undefined2 local_18;
  undefined2 local_16 [3];
  
  local_18 = 0x301;
  FUN_00008044(*param_1,&local_18,2);
  *param_1 = *param_1 + 2;
  local_16[0] = 0x800;
  FUN_00008044(*param_1,local_16,2);
  iVar1 = *param_1;
  *param_1 = iVar1 + 2;
  FUN_00008044(iVar1 + 2,param_2 + 0x32,8);
  *param_1 = *param_1 + 8;
  return 0xc;
}


================================================================