FUNCTION FUN_00000478 @ 0x00000478 size=88
CALLERS (0): 
CALLEES (1): FUN_0000fc2c@0x0000fc2c

int FUN_00000478(undefined4 param_1,undefined4 *param_2)

{
  short sVar1;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  
  sVar1 = FUN_0000fc2c(param_1,&local_10,&local_c,&local_a);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = local_10;
    *(undefined2 *)(param_2 + 1) = local_c;
    *(undefined2 *)((int)param_2 + 6) = local_a;
  }
  return (int)sVar1;
}


================================================================