FUNCTION FUN_00002020 @ 0x00002020 size=240
CALLERS (1): FUN_00001ab0@0x00001ab0
CALLEES (2): FUN_00001080@0x00001080, FUN_00004254@0x00004254

undefined4 FUN_00002020(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = FUN_00001080();
  iVar2 = FUN_00004254(0);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar4 = FUN_00001080(*(undefined4 *)(iVar2 + 4));
    if ((int)uVar4 < 0) {
      if ((uVar1 & 0xc0000000) == 0x80000000) {
        uVar4 = uVar4 & 0xffff0000;
      }
      else if ((uVar1 & 0xe0000000) == 0xc0000000) {
        uVar4 = uVar4 & 0xffffff00;
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = uVar4 & 0xff000000;
    }
    if ((int)uVar1 < 0) {
      if ((uVar1 & 0xc0000000) == 0x80000000) {
        uVar5 = 0xffff0000;
      }
      else {
        if ((uVar1 & 0xe0000000) != 0xc0000000) {
          return 0;
        }
        uVar5 = 0xffffff00;
      }
    }
    else {
      uVar5 = 0xff000000;
    }
    uVar5 = uVar1 & uVar5;
    if (uVar5 == uVar4) {
      uVar5 = uVar1 & *(uint *)(iVar2 + 0x10);
    }
    uVar3 = FUN_00001080(uVar5);
  }
  return uVar3;
}


================================================================