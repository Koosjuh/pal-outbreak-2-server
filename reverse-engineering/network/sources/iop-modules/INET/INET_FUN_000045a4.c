FUNCTION FUN_000045a4 @ 0x000045a4 size=204
CALLERS (0): 
CALLEES (5): FUN_00004078@0x00004078, FUN_00017bf4@0x00017bf4, FUN_0000b0ac@0x0000b0ac, FUN_00017ad8@0x00017ad8, FUN_00011d90@0x00011d90

void FUN_000045a4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: t2 expire\n");
  }
  uVar1 = FUN_00017bf4(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 5;
  uVar1 = FUN_0000b0ac();
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  FUN_00004078(param_1,0,0xffffffff,*(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x20))
  ;
  iVar2 = *(int *)(param_1 + 0x74) + 1;
  *(int *)(param_1 + 0x74) = iVar2;
  if (iVar2 == 1) {
    if (*(uint *)(param_1 + 0x54) < *(uint *)(param_1 + 0x4c)) {
      uVar1 = FUN_00017ad8(FUN_000045a4,param_1,
                           (*(uint *)(param_1 + 0x4c) - *(uint *)(param_1 + 0x54)) * 500);
      *(undefined4 *)(param_1 + 0x14) = uVar1;
    }
  }
  return;
}


================================================================