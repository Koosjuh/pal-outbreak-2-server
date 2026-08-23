FUNCTION FUN_0000d398 @ 0x0000d398 size=72
CALLERS (1): FUN_0000d5a8@0x0000d5a8
CALLEES (1): FUN_00010c38@0x00010c38

void FUN_0000d398(int param_1)

{
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  PPP: phase ==> Link Establishment\n");
  }
  **(undefined1 **)(param_1 + 0xc) = 1;
  return;
}


================================================================