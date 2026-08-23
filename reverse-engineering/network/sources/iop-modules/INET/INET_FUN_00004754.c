FUNCTION FUN_00004754 @ 0x00004754 size=424
CALLERS (0): 
CALLEES (5): FUN_000008d8@0x000008d8, FUN_00004670@0x00004670, FUN_00001530@0x00001530, FUN_0000e148@0x0000e148, FUN_00011d90@0x00011d90

void FUN_00004754(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: arp timeout\n");
  }
  if (*(int *)(param_1 + 0x1c) == 2) {
    *(undefined4 *)(param_1 + 0x1c) = 3;
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x70) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(iVar2 + 0x74) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(iVar2 + 0x7c) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(iVar2 + 0x80) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(iVar2 + 0x1b0) = *(undefined4 *)(param_1 + 0x30);
    }
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x40);
    FUN_0000e148(iVar2);
    if ((DAT_0001b850 & 0x20) != 0) {
      FUN_00011d90("DHCP: the following addresses are updated for %s\n",iVar2 + 8);
      FUN_00011d90(s_ipadr__0001b6b8);
      uVar1 = 0;
      if (iVar2 != 0) {
        uVar1 = *(undefined4 *)(iVar2 + 0x70);
      }
      FUN_00001530(uVar1);
      FUN_00011d90(s_ipmsk__0001b6c0);
      uVar1 = 0;
      if (iVar2 != 0) {
        uVar1 = *(undefined4 *)(iVar2 + 0x74);
      }
      FUN_00001530(uVar1);
      FUN_00011d90(s_gwadr__0001b6c8);
      uVar1 = 0;
      if (iVar2 != 0) {
        uVar1 = *(undefined4 *)(iVar2 + 0x7c);
      }
      FUN_00001530(uVar1);
      FUN_00011d90(" nsadr1=");
      uVar1 = 0;
      if (iVar2 != 0) {
        uVar1 = *(undefined4 *)(iVar2 + 0x80);
      }
      FUN_00001530(uVar1);
      FUN_00011d90(" nsadr2=");
      uVar1 = 0;
      if (iVar2 != 0) {
        uVar1 = *(undefined4 *)(iVar2 + 0x1b0);
      }
      FUN_00001530(uVar1);
      FUN_00011d90(&DAT_0001b6d0);
    }
    FUN_00004670(param_1);
    FUN_000008d8(iVar2);
  }
  return;
}


================================================================