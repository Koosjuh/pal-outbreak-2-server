FUNCTION FUN_000043a8 @ 0x000043a8 size=308
CALLERS (4): FUN_000049e0@0x000049e0, FUN_00004b68@0x00004b68, FUN_00005d28@0x00005d28, FUN_00003780@0x00003780
CALLEES (6): FUN_00019a94@0x00019a94, FUN_0000ae24@0x0000ae24, FUN_00017bf4@0x00017bf4, FUN_0000b0ac@0x0000b0ac, FUN_00017ad8@0x00017ad8, FUN_00011d90@0x00011d90

void FUN_000043a8(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: dhcp_init\n");
  }
  if ((iVar3 != 0) && ((*(uint *)(iVar3 + 0x48) & 0x20) != 0)) {
    if ((*(uint *)(param_1 + 0x1c) < 6) && (2 < *(uint *)(param_1 + 0x1c))) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      FUN_00019a94(*(undefined4 *)(iVar3 + 0x4c),0x20000);
    }
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x70) = 0;
      *(undefined4 *)(iVar3 + 0x74) = 0;
      *(undefined4 *)(iVar3 + 0x7c) = 0;
      *(undefined4 *)(iVar3 + 0x80) = 0;
      *(undefined4 *)(iVar3 + 0x1b0) = 0;
    }
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    FUN_0000ae24(param_1 + 0x20,0x24);
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar1 = FUN_00017bf4(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = uVar1;
    uVar1 = FUN_00017bf4(*(undefined4 *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    uVar1 = FUN_00017bf4(*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    uVar2 = FUN_0000b0ac();
    uVar1 = FUN_00017ad8(FUN_00003e54,param_1,uVar2 % 900 + 600);
    *(undefined4 *)(param_1 + 0xc) = uVar1;
  }
  return;
}


================================================================