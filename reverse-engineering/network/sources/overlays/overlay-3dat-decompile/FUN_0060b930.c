FUNCTION FUN_0060b930 @ 0x0060b930  size=268
CALLERS (1): FUN_00608c80@0x00608c80
CALLEES (1): FUN_0060b410@0x0060b410
----------------------------------------------------------------

long FUN_0060b930(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 int param_5)

{
  long lVar1;
  long lVar2;
  
  lVar1 = (**(code **)(param_5 + 0x28))(*(undefined4 *)(param_5 + 0x30),0x13,4);
  if (lVar1 == 0) {
    lVar2 = -4;
  }
  else {
    lVar2 = FUN_0060b410(param_1,0x13,0x13,0,0,param_3,param_2,param_4);
    if (lVar2 == -3) {
      *(char **)(param_5 + 0x20) = s_oversubscribed_dynamic_bit_lengt_0064a300;
    }
    else if ((lVar2 == -5) || (*(int *)param_2 == 0)) {
      lVar2 = -3;
      *(char **)(param_5 + 0x20) = s_incomplete_dynamic_bit_lengths_t_0064a330;
    }
    (**(code **)(param_5 + 0x2c))(*(undefined4 *)(param_5 + 0x30),lVar1);
  }
  return lVar2;
}



================================================================