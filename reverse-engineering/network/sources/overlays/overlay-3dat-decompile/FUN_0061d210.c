FUNCTION FUN_0061d210 @ 0x0061d210  size=388
CALLERS (1): FUN_00619800@0x00619800
CALLEES (2): FUN_0061cc80@0x0061cc80, FUN_0061cce0@0x0061cce0
----------------------------------------------------------------

void FUN_0061d210(long param_1)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  short sVar4;
  undefined2 uVar5;
  short sVar6;
  int iVar7;
  int *piVar8;
  short sVar9;
  
  if ((param_1 != 0) && (param_1 < 0x10)) {
    iVar7 = (int)param_1 * 0xc;
    sVar1 = *(short *)(&DAT_00666910 + iVar7);
    sVar9 = *(short *)(&DAT_00666912 + iVar7);
    uVar2 = *(undefined2 *)(&DAT_00666916 + iVar7);
    uVar3 = *(undefined2 *)(&DAT_00666918 + iVar7);
    sVar4 = *(short *)(&DAT_0066691a + iVar7);
    uVar5 = *(undefined2 *)(&DAT_00666914 + iVar7);
    piVar8 = *(int **)(*(int *)(&DAT_00665e30 + (uint)bRam0034359d * 4) + (int)param_1 * 4);
    func_0x001af060(uVar5,uVar5);
    sVar6 = sVar1;
    for (; *piVar8 != 0; piVar8 = piVar8 + 1) {
      if (sVar1 == -1) {
        sVar6 = FUN_0061cc80(*piVar8,uVar5);
      }
      FUN_0061cce0(*piVar8,sVar6,sVar9,uVar2,uVar3,uVar5);
      sVar9 = sVar9 + sVar4;
    }
  }
  return;
}



================================================================