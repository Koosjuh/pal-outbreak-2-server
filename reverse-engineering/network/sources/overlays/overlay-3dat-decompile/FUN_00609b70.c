FUNCTION FUN_00609b70 @ 0x00609b70  size=104
CALLERS (1): FUN_0060ac30@0x0060ac30
CALLEES (1): FUN_00608ab0@0x00608ab0
----------------------------------------------------------------

undefined8 FUN_00609b70(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  FUN_00608ab0(param_1,param_2,0);
  iVar1 = (int)param_2;
  (**(code **)(iVar1 + 0x2c))(*(undefined4 *)(iVar1 + 0x30),*(undefined4 *)((int)param_1 + 0x2c));
  (**(code **)(iVar1 + 0x2c))(*(undefined4 *)(iVar1 + 0x30),*(undefined4 *)((int)param_1 + 0x28));
  (**(code **)(iVar1 + 0x2c))(*(undefined4 *)(iVar1 + 0x30),param_1);
  return 0;
}



================================================================