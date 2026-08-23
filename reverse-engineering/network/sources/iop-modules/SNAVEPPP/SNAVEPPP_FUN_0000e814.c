FUNCTION FUN_0000e814 @ 0x0000e814 size=240
CALLERS (1): FUN_0000bb44@0x0000bb44
CALLEES (0): 

undefined4 * FUN_0000e814(short param_1,ushort param_2)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if ((ushort)(param_1 - 1U) < 0x10) {
    DAT_0001379c = &DAT_000137d0;
    DAT_000137a1 = (char)param_1 + -1;
  }
  if ((ushort)(param_2 - 1) < 0x10) {
    DAT_00013798 = &DAT_00014090;
    DAT_000137a0 = (char)param_2 - 1;
  }
  puVar1 = DAT_00013798;
  DAT_000137a3 = 0xff;
  DAT_000137a4 = 0xff;
  DAT_000137a2 = 0;
  if (0 < (int)((uint)param_2 << 0x10)) {
    uVar4 = (uint)DAT_000137a0;
    if (DAT_000137a0 != 0) {
      do {
        iVar2 = (short)uVar4 * 0x8c;
        uVar3 = uVar4 - 1;
        puVar1[iVar2] = (char)uVar4;
        *(undefined1 **)(puVar1 + iVar2 + 4) = puVar1 + iVar2 + -0x8c;
        uVar4 = uVar3;
      } while (0 < (int)(uVar3 * 0x10000));
    }
    uVar4 = (uint)DAT_000137a0;
    *puVar1 = 0;
    *(undefined1 **)(puVar1 + 4) = puVar1 + uVar4 * 0x8c;
  }
  return &DAT_00013798;
}


================================================================