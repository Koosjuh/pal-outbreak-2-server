FUNCTION FUN_005c1e70 @ 0x005c1e70  size=184
CALLERS (3): FUN_005c0060@0x005c0060, FUN_005c02b0@0x005c02b0, FUN_005bffa0@0x005bffa0
CALLEES (4): FUN_005bea10@0x005bea10, FUN_005be9e0@0x005be9e0, FUN_005bea30@0x005bea30, FUN_005bea80@0x005bea80
----------------------------------------------------------------

ulong FUN_005c1e70(short param_1,undefined8 param_2)

{
  ulong uVar1;
  ulong unaff_s0;
  
  if (param_1 == 2) {
    uVar1 = FUN_005be9e0(0x7018d0,0x7b);
    unaff_s0 = uVar1 & 0xffff;
  }
  else if (param_1 == 1) {
    uVar1 = FUN_005be9e0(0x7018d0,0x49);
    unaff_s0 = uVar1 & 0xffff;
  }
  else if (param_1 == 0) {
    uVar1 = FUN_005be9e0(0x7018d0,0x35);
    unaff_s0 = uVar1 & 0xffff;
  }
  FUN_005bea30(0x7018d0,param_2);
  FUN_005bea10(0x7018d0);
  FUN_005bea80(0x7018d0);
  return unaff_s0;
}



================================================================