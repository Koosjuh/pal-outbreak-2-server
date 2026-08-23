FUNCTION FUN_005bdef0 @ 0x005bdef0  size=120
CALLERS (2): FUN_005bd8c0@0x005bd8c0, FUN_005bd940@0x005bd940
CALLEES (4): FUN_005bea60@0x005bea60, FUN_005bea10@0x005bea10, FUN_005be9e0@0x005be9e0, FUN_005bea80@0x005bea80
----------------------------------------------------------------

undefined2 FUN_005bdef0(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  
  uVar1 = FUN_005be9e0(0x7018d0,0x21);
  FUN_005bea60(0x7018d0,param_1,param_2);
  FUN_005bea10(0x7018d0);
  FUN_005bea80(0x7018d0);
  return uVar1;
}



================================================================