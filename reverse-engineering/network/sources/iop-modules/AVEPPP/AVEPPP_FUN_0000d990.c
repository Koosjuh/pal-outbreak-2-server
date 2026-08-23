FUNCTION FUN_0000d990 @ 0x0000d990 size=24
CALLERS (1): FUN_00001dbc@0x00001dbc
CALLEES (0): 

undefined4 FUN_0000d990(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_3 + 0x30);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  return 0;
}


================================================================