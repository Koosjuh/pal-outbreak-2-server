FUNCTION FUN_0000d400 @ 0x0000d400 size=88
CALLERS (0): 
CALLEES (3): FUN_00010c38@0x00010c38, FUN_0000a720@0x0000a720, FUN_0000e3c8@0x0000e3c8

void FUN_0000d400(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0xc);
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  PPP: phase ==> Link Termination\n");
  }
  *puVar1 = 4;
  FUN_0000a720(puVar1 + 0x6c);
  FUN_0000e3c8(puVar1 + 0x38);
  return;
}


================================================================