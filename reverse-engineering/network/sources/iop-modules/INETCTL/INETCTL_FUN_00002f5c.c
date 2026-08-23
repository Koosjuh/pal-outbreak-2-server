FUNCTION FUN_00002f5c @ 0x00002f5c size=376
CALLERS (2): FUN_00003128@0x00003128, FUN_000030d4@0x000030d4
CALLEES (4): FUN_0000203c@0x0000203c, FUN_00003de8@0x00003de8, FUN_00003de0@0x00003de0, FUN_00003df0@0x00003df0

int FUN_00002f5c(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  
  if ((param_2 == 0) || (*(int *)(PTR_DAT_000045e0 + 0x18) != 0)) {
    iVar2 = FUN_00003de8(0,auStack_58);
    if (iVar2 == 0) {
      FUN_00003de0(0,DAT_000045c8);
      iVar4 = 0;
      iVar2 = DAT_000046f0;
      piVar1 = DAT_000046ec;
      if (param_2 == 0) {
        for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
          if ((param_1 == 0) || (param_1 == *(int *)(iVar2 + 8))) {
            iVar3 = FUN_0000203c(iVar2,9);
            iVar4 = iVar4 + iVar3;
          }
          if ((param_1 == 0) && (*(int *)(iVar2 + 4) != 0)) {
            FUN_00003df0(100000);
          }
        }
      }
      else {
        for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
          if ((param_1 == 0) || (param_1 == piVar1[2])) {
            iVar2 = FUN_0000203c(piVar1,8);
            iVar4 = iVar4 + iVar2;
          }
          if ((param_1 == 0) && (*piVar1 != 0)) {
            FUN_00003df0(100000);
          }
        }
      }
      FUN_00003de0(0,local_38);
      iVar2 = 0;
      if (iVar4 != 0) {
        iVar2 = -1;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


================================================================