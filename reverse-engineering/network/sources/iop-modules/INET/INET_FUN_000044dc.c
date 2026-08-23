FUNCTION FUN_000044dc @ 0x000044dc size=200
CALLERS (0): 
CALLEES (4): FUN_00004078@0x00004078, FUN_0000b0ac@0x0000b0ac, FUN_00017ad8@0x00017ad8, FUN_00011d90@0x00011d90

void FUN_000044dc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: t1 expire\n");
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 4;
  if (*(int *)(param_1 + 0x48) != 0) {
    uVar1 = FUN_0000b0ac();
    *(undefined4 *)(param_1 + 0x44) = uVar1;
    FUN_00004078(param_1,0,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44),
                 *(undefined4 *)(param_1 + 0x20));
    iVar2 = *(int *)(param_1 + 0x70) + 1;
    *(int *)(param_1 + 0x70) = iVar2;
    if (iVar2 == 1) {
      if (*(uint *)(param_1 + 0x50) < *(uint *)(param_1 + 0x54)) {
        uVar1 = FUN_00017ad8(FUN_000044dc,param_1,
                             (*(uint *)(param_1 + 0x54) - *(uint *)(param_1 + 0x50)) * 500);
        *(undefined4 *)(param_1 + 0x10) = uVar1;
      }
    }
  }
  return;
}


================================================================