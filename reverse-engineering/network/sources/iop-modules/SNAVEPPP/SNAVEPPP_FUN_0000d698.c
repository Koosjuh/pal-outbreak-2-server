FUNCTION FUN_0000d698 @ 0x0000d698 size=132
CALLERS (3): FUN_0000d458@0x0000d458, FUN_0000dc5c@0x0000dc5c, FUN_0000670c@0x0000670c
CALLEES (3): FUN_00010c38@0x00010c38, FUN_00010ae4@0x00010ae4, FUN_0000a624@0x0000a624

void FUN_0000d698(undefined1 *param_1)

{
  uint uVar1;
  
  if ((param_1[2] & 0x30) == 0) {
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  PPP: phase ==> Network\n");
    }
    *param_1 = 3;
    uVar1 = FUN_00010ae4();
    *(uint *)(param_1 + 0xd4) = uVar1 / 1000;
    FUN_0000a624(param_1 + 0x6c);
  }
  return;
}


================================================================