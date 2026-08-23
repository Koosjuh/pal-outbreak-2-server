FUNCTION FUN_005c2080 @ 0x005c2080  size=156
CALLERS (3): FUN_005bfe00@0x005bfe00, FUN_005c0750@0x005c0750, FUN_005bfe90@0x005bfe90
CALLEES (3): FUN_005bea10@0x005bea10, FUN_005be9e0@0x005be9e0, FUN_005bea80@0x005bea80
----------------------------------------------------------------

ulong FUN_005c2080(short param_1)

{
  ulong uVar1;
  ulong unaff_s0;
  
  if (param_1 == 2) {
    uVar1 = FUN_005be9e0(0x7018d0,0x70);
    unaff_s0 = uVar1 & 0xffff;
  }
  else if (param_1 == 1) {
    uVar1 = FUN_005be9e0(0x7018d0,0x43);
    unaff_s0 = uVar1 & 0xffff;
  }
  else if (param_1 == 0) {
    uVar1 = FUN_005be9e0(0x7018d0,0x3e);
    unaff_s0 = uVar1 & 0xffff;
  }
  FUN_005bea10(0x7018d0);
  FUN_005bea80(0x7018d0);
  return unaff_s0;
}



================================================================