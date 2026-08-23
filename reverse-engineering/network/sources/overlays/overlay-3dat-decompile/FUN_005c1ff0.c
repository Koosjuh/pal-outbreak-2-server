FUNCTION FUN_005c1ff0 @ 0x005c1ff0  size=144
CALLERS (2): FUN_005c04f0@0x005c04f0, FUN_005c05c0@0x005c05c0
CALLEES (5): FUN_005bea60@0x005bea60, FUN_005bea10@0x005bea10, FUN_005be9e0@0x005be9e0, FUN_005bea30@0x005bea30, FUN_005bea80@0x005bea80
----------------------------------------------------------------

undefined2 FUN_005c1ff0(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = FUN_005be9e0(0x7018d0,0x6e);
  FUN_005bea30(0x7018d0,param_1);
  uVar2 = func_0x0010a050(param_2);
  FUN_005bea60(0x7018d0,param_2,uVar2);
  FUN_005bea10(0x7018d0);
  FUN_005bea80(0x7018d0);
  return uVar1;
}



================================================================