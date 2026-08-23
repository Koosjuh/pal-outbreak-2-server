FUNCTION FUN_005dfee0 @ 0x005dfee0  size=172
CALLERS (11): FUN_005dd660@0x005dd660, FUN_005dcb90@0x005dcb90, FUN_005dc4b0@0x005dc4b0, FUN_005daba0@0x005daba0, FUN_005dbca0@0x005dbca0, FUN_005db8a0@0x005db8a0, FUN_005cd5d0@0x005cd5d0, FUN_005daf30@0x005daf30, FUN_005db300@0x005db300, FUN_005c92d0@0x005c92d0, FUN_005dc010@0x005dc010
CALLEES (1): FUN_005dfd80@0x005dfd80
----------------------------------------------------------------

void FUN_005dfee0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x20);
    *(int *)((uint)*(byte *)(param_1 + 3) * 4 + iRam00701068 + 0x5ff70) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)((uint)*(byte *)(param_1 + 3) * 4 + iRam00701068 + 0x5ff94) = 0;
    }
    else {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
  }
  else if (*(int *)(param_1 + 0x20) == 0) {
    *(int *)((uint)*(byte *)(param_1 + 3) * 4 + iRam00701068 + 0x5ff94) = iVar1;
    *(undefined4 *)(iVar1 + 0x20) = 0;
  }
  else {
    *(int *)(iVar1 + 0x20) = *(int *)(param_1 + 0x20);
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  }
  FUN_005dfd80();
  return;
}



================================================================