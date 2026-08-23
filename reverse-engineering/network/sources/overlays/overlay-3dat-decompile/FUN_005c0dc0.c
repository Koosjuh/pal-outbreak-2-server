FUNCTION FUN_005c0dc0 @ 0x005c0dc0  size=104
CALLERS (2): FUN_005c0a00@0x005c0a00, FUN_005c0ae0@0x005c0ae0
CALLEES (4): FUN_005bea10@0x005bea10, FUN_005be9e0@0x005be9e0, FUN_005bea30@0x005bea30, FUN_005bea80@0x005bea80
----------------------------------------------------------------

undefined2 FUN_005c0dc0(undefined8 param_1)

{
  undefined2 uVar1;
  
  uVar1 = FUN_005be9e0(0x7018d0,0x86);
  FUN_005bea30(0x7018d0,param_1);
  FUN_005bea10(0x7018d0);
  FUN_005bea80(0x7018d0);
  return uVar1;
}



================================================================