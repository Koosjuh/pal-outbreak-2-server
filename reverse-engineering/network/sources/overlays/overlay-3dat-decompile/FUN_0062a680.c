FUNCTION FUN_0062a680 @ 0x0062a680  size=76
CALLERS (1): FUN_0062a5e0@0x0062a5e0
CALLEES (3): FUN_0062b670@0x0062b670, FUN_00618b60@0x00618b60, FUN_00629d00@0x00629d00
----------------------------------------------------------------

undefined8 FUN_0062a680(undefined8 param_1,undefined8 param_2)

{
  *(char *)param_2 = *(char *)param_2 + '\x01';
  FUN_00618b60();
  FUN_0062b670(param_2,0);
  FUN_00629d00(param_2,2);
  return 0;
}



================================================================