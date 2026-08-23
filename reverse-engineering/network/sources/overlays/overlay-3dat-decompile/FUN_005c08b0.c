FUNCTION FUN_005c08b0 @ 0x005c08b0  size=104
CALLERS (2): FUN_005c28f0@0x005c28f0, FUN_005c29c0@0x005c29c0
CALLEES (4): FUN_005bea40@0x005bea40, FUN_005bea10@0x005bea10, FUN_005be9e0@0x005be9e0, FUN_005bea80@0x005bea80
----------------------------------------------------------------

undefined2 FUN_005c08b0(undefined8 param_1)

{
  undefined2 uVar1;
  
  uVar1 = FUN_005be9e0(0x7018d0,0x91);
  FUN_005bea40(0x7018d0,param_1);
  FUN_005bea10(0x7018d0);
  FUN_005bea80(0x7018d0);
  return uVar1;
}



================================================================