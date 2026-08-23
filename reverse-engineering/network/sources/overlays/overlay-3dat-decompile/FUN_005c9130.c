FUNCTION FUN_005c9130 @ 0x005c9130  size=416
CALLERS (1): FUN_005c8ed0@0x005c8ed0
CALLEES (1): FUN_005dfde0@0x005dfde0
----------------------------------------------------------------

void FUN_005c9130(void)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  
  func_0x00106b60(iRam00701068 + 0x68dd8,0,0x50);
  func_0x00106b60(iRam00701068 + 0x68e28,0,0x28);
  func_0x00106b60(iRam00701068 + 0x68e50,0,0x28);
  uVar3 = 0;
  while( true ) {
    if (499 < uVar3) {
      return;
    }
    iVar2 = uVar3 * 4;
    lVar1 = FUN_005dfde0(1,0);
    *(int *)(iRam00701068 + iVar2 + 0x5ffc0) = (int)lVar1;
    if (lVar1 == 0) break;
    uVar3 = uVar3 + 1 & 0xffff;
    **(undefined1 **)(iRam00701068 + iVar2 + 0x5ffc0) = 0;
    *(undefined1 *)(*(int *)(iRam00701068 + iVar2 + 0x5ffc0) + 0x5f) = 0;
    *(undefined1 **)(*(int *)(iRam00701068 + iVar2 + 0x5ffc0) + 0x14) = &LAB_005c8090;
    *(undefined1 **)(*(int *)(iRam00701068 + iVar2 + 0x5ffc0) + 0x18) = &LAB_005c8090;
    *(undefined1 *)(*(int *)(iRam00701068 + iVar2 + 0x5ffc0) + 1) = 0;
    *(undefined1 *)(*(int *)(iRam00701068 + iVar2 + 0x5ffc0) + 0x5f) = 0;
    *(undefined1 *)(*(int *)(iRam00701068 + iVar2 + 0x5ffc0) + 5) = 0;
  }
  return;
}



================================================================