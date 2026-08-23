FUNCTION FUN_005d6d50 @ 0x005d6d50  size=828
CALLERS (1): FUN_005c80a0@0x005c80a0
CALLEES (2): FUN_005dee40@0x005dee40, FUN_005d7690@0x005d7690
----------------------------------------------------------------

void FUN_005d6d50(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iRam00701040 = iRam00701068 + 0x46000;
  iRam00701038 = iRam00701068 + 0x4633c;
  iRam00701030 = iRam00701068 + 0x486bc;
  iRam00701028 = iRam00701068 + 0x4a83c;
  iRam00701020 = iRam00701068 + 0x2a000;
  func_0x00106b60(iRam00701040,0,0x33c);
  iVar3 = 0;
  *(int *)(iRam00701068 + 0x4f370) = iRam00701040;
  do {
    iVar2 = iVar3 + 1;
    iVar1 = iVar3 * 0x114;
    iVar3 = iVar3 + 1;
    *(int *)(iRam00701040 + iVar1) = iRam00701040 + iVar2 * 0x114;
  } while (iVar3 < 2);
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x8000;
    iVar1 = iVar3 * 0x114;
    iVar3 = iVar3 + 1;
    *(int *)(iRam00701040 + iVar1 + 0x10c) = iRam00701068 + iVar2 + 0x2e000;
  } while (iVar3 < 3);
  func_0x00106b60(iRam00701038,0,0x2380);
  iVar3 = 0;
  *(int *)(iRam00701068 + 0x4f47c) = iRam00701038;
  do {
    iVar2 = iVar3 + 1;
    iVar1 = iVar3 * 0x11c;
    iVar3 = iVar3 + 1;
    *(int *)(iRam00701038 + iVar1) = iRam00701038 + iVar2 * 0x11c;
  } while (iVar3 < 0x1f);
  func_0x00106b60(iRam00701030,0,0x2180);
  iVar3 = 0;
  *(int *)(iRam00701068 + 0x4f588) = iRam00701030;
  iRam00701018 = iRam00701030;
  do {
    iVar2 = iVar3 + 1;
    iVar1 = iVar3 * 0x10c;
    iVar3 = iVar3 + 1;
    *(int *)(iRam00701030 + iVar1) = iRam00701030 + iVar2 * 0x10c;
  } while (iVar3 < 0x1f);
  func_0x00106b60(iRam00701068 + 0x4a83c,0,0x1720);
  iVar3 = 0;
  *(int *)(iRam00701068 + 0x4f694) = iRam00701068 + 0x4a83c;
  do {
    iVar2 = iVar3 + 1;
    iVar1 = iVar3 * 0x128;
    iVar3 = iVar3 + 1;
    *(int *)(iRam00701068 + iVar1 + 0x4a83c) = iRam00701068 + iVar2 * 0x128 + 0x4a83c;
  } while (iVar3 < 0x13);
  func_0x00106b60(0x701000,0,0x14);
  FUN_005dee40();
  FUN_005d7690();
  uRam00700ff8 = 0;
  return;
}



================================================================