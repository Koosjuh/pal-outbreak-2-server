FUNCTION FUN_000114dc @ 0x000114dc size=56
CALLERS (1): FUN_000007f8@0x000007f8
CALLEES (1): FUN_00002ae8@0x00002ae8

int FUN_000114dc(undefined2 *param_1)

{
  short sVar1;
  undefined4 local_10;
  undefined1 local_c;
  
  local_10 = *(undefined4 *)(param_1 + 2);
  local_c = 3;
  sVar1 = FUN_00002ae8(*param_1,&local_10);
  return (int)sVar1;
}


================================================================