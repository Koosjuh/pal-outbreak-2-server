FUNCTION FUN_0000d458 @ 0x0000d458 size=328
CALLERS (1): FUN_00004550@0x00004550
CALLEES (6): FUN_0000e660@0x0000e660, FUN_0000e5e4@0x0000e5e4, FUN_00010c38@0x00010c38, FUN_0000d698@0x0000d698, FUN_00007308@0x00007308, FUN_00007388@0x00007388

void FUN_0000d458(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  PPP: phase ==> Authentication\n");
  }
  **(undefined1 **)(param_1 + 0xc) = 2;
  *(byte *)(*(int *)(param_1 + 0xc) + 2) = *(byte *)(*(int *)(param_1 + 0xc) + 2) & 0xcf;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8) = 0;
  if ((*(ushort *)(iVar1 + 0x1c) & 8) != 0) {
    if (*(short *)(iVar1 + 0x24) == -0x3fdd) {
      FUN_0000e5e4(*(undefined4 *)(param_1 + 0xc));
    }
    else if (*(short *)(iVar1 + 0x24) == -0x3ddd) {
      FUN_00007308(*(undefined4 *)(param_1 + 0xc));
      FUN_00007388(*(undefined4 *)(param_1 + 0xc));
    }
  }
  if ((*(ushort *)(iVar1 + 0x50) & 8) != 0) {
    if (*(short *)(iVar1 + 0x58) == -0x3fdd) {
      FUN_0000e660(*(undefined4 *)(param_1 + 0xc));
    }
    else if (*(short *)(iVar1 + 0x58) == -0x3ddd) {
      FUN_00007388(*(undefined4 *)(param_1 + 0xc));
      FUN_00007308(*(undefined4 *)(param_1 + 0xc));
    }
  }
  FUN_0000d698(*(undefined4 *)(param_1 + 0xc));
  return;
}


================================================================