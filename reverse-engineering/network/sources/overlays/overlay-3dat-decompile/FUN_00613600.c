FUNCTION FUN_00613600 @ 0x00613600  size=316
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (4): thunk_EXT_FUN_001ae3e0@0x00614860, FUN_006146e0@0x006146e0, FUN_00614870@0x00614870, FUN_00616570@0x00616570
----------------------------------------------------------------

void FUN_00613600(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  if (*(char *)(iRam0070d1c0 + 0x4bc) == '\0') {
    FUN_006146e0(0x115,0xc4,0x654100);
  }
  else {
    FUN_00616570(iRam0070d1c0 + 0x4bc,auStack_80,0x20);
    FUN_00614870(auStack_40,auStack_80,0x18);
    FUN_006146e0(0x115,0xc4,auStack_40);
  }
  if (*(char *)(iRam0070d1c0 + 0x6bc) == '\0') {
    FUN_006146e0(0x115,0xfc,0x654120);
  }
  else {
    iVar1 = thunk_EXT_FUN_001ae3e0(iRam0070d1c0 + 0x6bc);
    iVar2 = 0;
    if (iVar1 < 0x19) {
      for (; iVar2 < iVar1; iVar2 = iVar2 + 1) {
        auStack_40[iVar2] = 0x2a;
      }
      auStack_40[iVar2] = 0;
    }
    else {
      iVar1 = 0;
      do {
        iVar2 = iVar1;
        auStack_40[iVar2] = 0x2a;
        iVar1 = iVar2 + 1;
      } while (iVar2 + 1 < 0x16);
      auStack_40[iVar2 + 1] = 0x2e;
      auStack_40[iVar2 + 2] = 0x2e;
      auStack_40[iVar2 + 3] = 0;
    }
    FUN_006146e0(0x115,0xfc,auStack_40);
  }
  return;
}



================================================================