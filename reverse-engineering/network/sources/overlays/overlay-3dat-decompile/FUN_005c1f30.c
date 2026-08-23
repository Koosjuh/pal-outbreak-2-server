FUNCTION FUN_005c1f30 @ 0x005c1f30  size=184
CALLERS (2): FUN_005bfb40@0x005bfb40, FUN_005bfa70@0x005bfa70
CALLEES (4): FUN_005bea10@0x005bea10, FUN_005be9e0@0x005be9e0, FUN_005bea30@0x005bea30, FUN_005bea80@0x005bea80
----------------------------------------------------------------

ulong FUN_005c1f30(short param_1,undefined8 param_2)

{
  ulong uVar1;
  ulong unaff_s0;
  
  if (param_1 == 2) {
    uVar1 = FUN_005be9e0(0x7018d0,0x6e);
    unaff_s0 = uVar1 & 0xffff;
  }
  else if (param_1 == 1) {
    uVar1 = FUN_005be9e0(0x7018d0,0x41);
    unaff_s0 = uVar1 & 0xffff;
  }
  else if (param_1 == 0) {
    uVar1 = FUN_005be9e0(0x7018d0,0x2f);
    unaff_s0 = uVar1 & 0xffff;
  }
  FUN_005bea30(0x7018d0,param_2);
  FUN_005bea10(0x7018d0);
  FUN_005bea80(0x7018d0);
  return unaff_s0;
}



================================================================