FUNCTION FUN_00001688 @ 0x00001688 size=524
CALLERS (1): FUN_0000203c@0x0000203c
CALLEES (6): FUN_0000018c@0x0000018c, FUN_000015c0@0x000015c0, FUN_000007f8@0x000007f8, FUN_00003d8c@0x00003d8c, FUN_00000a4c@0x00000a4c, FUN_0000043c@0x0000043c

undefined4 FUN_00001688(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint local_28 [2];
  
  iVar5 = *(int *)(param_1 + 0x18);
  if (iVar5 != 0) {
    iVar6 = *(int *)(iVar5 + 0x24);
    iVar3 = *(int *)(iVar6 + 4);
    uVar4 = *(undefined4 *)(iVar6 + 8);
    uVar2 = 0x10005;
    if (*(char *)(iVar3 + 0x10) == '\x01') {
      uVar2 = 0x10004;
    }
    iVar1 = FUN_0000018c(uVar4,uVar2,0,0);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = FUN_0000043c(uVar4,0x109,*(undefined4 *)(iVar3 + 0x1c));
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = FUN_0000043c(uVar4,0x10a,*(undefined4 *)(iVar3 + 0x20));
    if (iVar1 == 0) {
      if (*(char *)(iVar3 + 0x10) == '\x01') {
        if (*(int *)(iVar3 + 0x14) != 0) {
          iVar1 = FUN_00003d8c();
          if (*(char *)(iVar3 + 0x18) != '\0') {
            iVar1 = iVar1 + 1;
          }
          iVar1 = FUN_0000018c(uVar4,0x10e,*(undefined4 *)(iVar3 + 0x14),iVar1);
          if (iVar1 != 0) {
            return 0xffffffff;
          }
        }
        if (*(char *)(iVar3 + 0x19) == '\x01') {
          uVar2 = 0x11000;
        }
        else {
          uVar2 = 0x11001;
        }
        iVar3 = FUN_0000018c(uVar4,uVar2,0,0);
        if (iVar3 != 0) {
          return 0xffffffff;
        }
      }
      iVar3 = FUN_000007f8(iVar6 + 0x14,*(undefined4 *)(iVar5 + 0x14));
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      iVar3 = FUN_000007f8(iVar6 + 0x14,*(undefined4 *)(iVar5 + 0x18));
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      iVar3 = FUN_0000018c(uVar4,8,local_28,4);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      if (((local_28[0] & 0x40) != 0) && (iVar3 = FUN_00000a4c(param_1), iVar3 != 0)) {
        return 0xffffffff;
      }
      if (((local_28[0] & 0x10) == 0) || (iVar5 = FUN_000015c0(iVar5), iVar5 == 0)) {
        iVar5 = FUN_0000018c(uVar4,0x10000,0,0);
        if (iVar5 != 0) {
          return 0xffffffff;
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}


================================================================