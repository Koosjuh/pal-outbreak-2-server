FUNCTION FUN_00011414 @ 0x00011414 size=60
CALLERS (1): FUN_0000078c@0x0000078c
CALLEES (1): FUN_0000ef14@0x0000ef14

int FUN_00011414(undefined2 *param_1)

{
  short sVar1;
  undefined4 local_10;
  undefined1 local_c;
  
  local_10 = *(undefined4 *)(param_1 + 2);
  local_c = 3;
  sVar1 = FUN_0000ef14(*param_1,&local_10,0);
  return (int)sVar1;
}


================================================================