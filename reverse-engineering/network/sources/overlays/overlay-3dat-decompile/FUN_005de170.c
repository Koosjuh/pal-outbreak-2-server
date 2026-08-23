FUNCTION FUN_005de170 @ 0x005de170  size=296
CALLERS (2): FUN_005c9a00@0x005c9a00, FUN_005c8e00@0x005c8e00
CALLEES (1): FUN_005e7e30@0x005e7e30
----------------------------------------------------------------

undefined4 FUN_005de170(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  
  if (cRam00701060 != '\0') {
    if (cRam00701060 != '\x01') {
      return 0;
    }
    uVar1 = REG_RCNT0_COUNT;
    do {
      sVar4 = FUN_005e7e30(uRam00701050,1,param_1);
      if (((sVar4 != 0) && (sVar4 != 1)) || (uVar2 = REG_RCNT0_COUNT, uVar2 < uVar1)) break;
      iVar3 = REG_RCNT0_COUNT;
    } while (iVar3 - uVar1 < 0x41);
    if (sVar4 == 3) {
      uRam00701058 = 3;
      cRam00701060 = 0;
      return 0x701058;
    }
    if (sVar4 == 2) {
      uRam00701058 = 2;
      cRam00701060 = 0;
      return 0x701058;
    }
    if (sVar4 == 1) {
      uRam00701058 = 1;
      return 0x701058;
    }
    if (sVar4 == 0) {
      uRam00701058 = 0;
      return 0x701058;
    }
  }
  return 0;
}



================================================================