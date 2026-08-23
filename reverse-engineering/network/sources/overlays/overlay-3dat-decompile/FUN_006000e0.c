FUNCTION FUN_006000e0 @ 0x006000e0  size=228
CALLERS (1): FUN_005b5fb0@0x005b5fb0
CALLEES (0): 
----------------------------------------------------------------

void FUN_006000e0(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = iRam003435d4 + 0xc942c;
  while ((iVar4 = -1, iVar5 < 4 &&
         (lVar2 = func_0x00109d70(iVar3 + 0x14,param_1), iVar4 = iVar5, lVar2 != 0))) {
    iVar5 = iVar5 + 1;
    iVar3 = iVar3 + 0x830;
  }
  if (-1 < iVar4) {
    iVar5 = (int)param_1;
    if (*(int *)(iVar5 + 0x14) == 0) {
      *(undefined1 *)(iVar3 + 1) = 4;
      *(undefined1 *)(iVar3 + 3) = 1;
    }
    else {
      *(undefined1 *)(iVar3 + 1) = 2;
    }
    iVar4 = *(int *)(iVar5 + 0x18);
    *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + iVar4;
    iVar1 = *(int *)(iVar3 + 0x28);
    *(int *)(iVar3 + 0x28) = iVar1 + iVar4;
    func_0x001069a8(iVar3 + 0x30 + iVar1,iVar5 + 0x1c);
  }
  return;
}



================================================================