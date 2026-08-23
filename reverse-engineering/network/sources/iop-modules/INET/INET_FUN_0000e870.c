FUNCTION FUN_0000e870 @ 0x0000e870 size=584
CALLERS (1): FUN_0000ec64@0x0000ec64
CALLEES (6): FUN_00011d90@0x00011d90, FUN_0000e848@0x0000e848, FUN_0000e1c8@0x0000e1c8, FUN_000199b4@0x000199b4, FUN_000090c8@0x000090c8, FUN_0000e6ac@0x0000e6ac

void FUN_0000e870(int param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  if (*(uint *)(param_1 + 0x70) == 0) {
    if ((*(uint *)(param_1 + 0x48) & 0x200) == 0) {
      FUN_00011d90("running without ip_addr\n");
      return;
    }
    if (DAT_0001b880 == 0) {
      return;
    }
    pcVar2 = *(code **)(DAT_0001b880 + 8);
    goto LAB_0000ea9c;
  }
  uVar5 = *(uint *)(param_1 + 0x70) >> 0x1e;
  if (*(int *)(param_1 + 0x74) == 0) {
    if (uVar5 == 2) {
      uVar3 = 0xffff0000;
    }
    else {
      uVar3 = 0xff000000;
      if ((1 < uVar5) && (uVar3 = 0xffffff00, uVar5 != 3)) goto LAB_0000e918;
    }
    *(undefined4 *)(param_1 + 0x74) = uVar3;
  }
LAB_0000e918:
  if ((*(uint *)(param_1 + 0x70) & 0xe0000000) == 0xe0000000) {
    FUN_00011d90("running with invalid ip_addr\n");
    return;
  }
  if ((*(uint *)(param_1 + 0x48) & 0x14) == 0x10) {
    *(uint *)(param_1 + 0x78) = ~*(uint *)(param_1 + 0x74) | *(uint *)(param_1 + 0x70);
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 4;
  }
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 2;
  FUN_0000e1c8(*(undefined4 *)(param_1 + 0x70),0,*(undefined4 *)(param_1 + 0x74),0,0,0,param_1 + 8);
  piVar1 = DAT_0001b868;
  if (*(int *)(param_1 + 0x7c) != 0) {
    FUN_0000e1c8(0,*(undefined4 *)(param_1 + 0x7c),0,4,0,0,param_1 + 8);
    piVar1 = DAT_0001b868;
  }
  for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    iVar4 = FUN_000199b4(param_1 + 8,piVar1 + 8);
    if (iVar4 == 0) {
      piVar1[0xb] = param_1;
      piVar1[5] = piVar1[5] | 1;
    }
  }
  if (*(int *)(param_1 + 0x80) != 0) {
    FUN_0000e6ac();
  }
  if ((1 < *(ushort *)(param_1 + 0x40)) && (*(int *)(param_1 + 0x1b0) != 0)) {
    FUN_0000e6ac();
  }
  if ((*(uint *)(param_1 + 0x48) & 0x400) != 0) {
    FUN_000090c8(param_1);
  }
  FUN_0000e848();
  if ((*(uint *)(param_1 + 0x48) & 0x200) == 0) {
    return;
  }
  if (DAT_0001b880 == 0) {
    return;
  }
  pcVar2 = *(code **)(DAT_0001b880 + 8);
LAB_0000ea9c:
  (*pcVar2)(param_1);
  return;
}


================================================================