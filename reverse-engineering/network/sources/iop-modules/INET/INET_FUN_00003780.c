FUNCTION FUN_00003780 @ 0x00003780 size=292
CALLERS (1): FUN_00004b68@0x00004b68
CALLEES (4): FUN_0000b0ac@0x0000b0ac, FUN_00017ad8@0x00017ad8, FUN_00011d90@0x00011d90, FUN_000043a8@0x000043a8

void FUN_00003780(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: dhcp_retransmit\n");
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    if (*(int *)(param_1 + 0x5c) == 4) {
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      FUN_000043a8();
    }
    else {
      (**(code **)(param_1 + 0x58))
                (param_1,*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 100),
                 *(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c));
      uVar1 = FUN_0000b0ac();
      uVar3 = *(uint *)(param_1 + 0x5c);
      *(uint *)(param_1 + 0x5c) = uVar3 + 1;
      uVar2 = FUN_00017ad8(FUN_00003780,param_1,uVar1 % 2000 + (4 << (uVar3 & 0x1f)) * 1000 + -1000)
      ;
      *(undefined4 *)(param_1 + 0xc) = uVar2;
    }
  }
  return;
}


================================================================