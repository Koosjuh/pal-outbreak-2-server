FUNCTION FUN_005dfde0 @ 0x005dfde0  size=248
CALLERS (10): FUN_005dbf00@0x005dbf00, FUN_005c9130@0x005c9130, FUN_005dd3b0@0x005dd3b0, FUN_005db6d0@0x005db6d0, FUN_005dae40@0x005dae40, FUN_005db130@0x005db130, FUN_005dc3b0@0x005dc3b0, FUN_005dbb10@0x005dbb10, FUN_005da8e0@0x005da8e0, FUN_005dca70@0x005dca70
CALLEES (1): FUN_005dfd50@0x005dfd50
----------------------------------------------------------------

long FUN_005dfde0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  long extraout_a1;
  int extraout_a2_lo;
  
  lVar3 = FUN_005dfd50(param_1,param_2,param_1);
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  else {
    iVar2 = (int)lVar3;
    *(char *)(iVar2 + 3) = (char)extraout_a2_lo;
    if (extraout_a1 == 0) {
      iVar4 = extraout_a2_lo * 4;
      iVar1 = *(int *)(iVar4 + iRam00701068 + 0x5ff70);
      *(int *)(iVar2 + 0x20) = iVar1;
      *(int *)(iVar4 + iRam00701068 + 0x5ff70) = iVar2;
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      if (iVar1 == 0) {
        *(int *)(iVar4 + iRam00701068 + 0x5ff94) = iVar2;
      }
      else {
        *(int *)(iVar1 + 0x1c) = iVar2;
      }
    }
    else {
      iVar4 = extraout_a2_lo * 4;
      iVar1 = *(int *)(iVar4 + iRam00701068 + 0x5ff94);
      *(int *)(iVar2 + 0x1c) = iVar1;
      *(int *)(iVar4 + iRam00701068 + 0x5ff94) = iVar2;
      *(undefined4 *)(iVar2 + 0x20) = 0;
      if (iVar1 == 0) {
        *(int *)(iVar4 + iRam00701068 + 0x5ff70) = iVar2;
      }
      else {
        *(int *)(iVar1 + 0x20) = iVar2;
      }
    }
  }
  return lVar3;
}



================================================================