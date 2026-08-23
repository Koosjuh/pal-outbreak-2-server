FUNCTION FUN_0061c9f0 @ 0x0061c9f0  size=652
CALLERS (1): FUN_00619800@0x00619800
CALLEES (2): FUN_0061cc80@0x0061cc80, FUN_0061cce0@0x0061cce0
----------------------------------------------------------------

void FUN_0061c9f0(uint param_1,long param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  short sVar4;
  undefined2 uVar5;
  short sVar6;
  long lVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  short sVar11;
  int iVar12;
  undefined1 auStack_30 [32];
  undefined1 auStack_10 [16];
  
  uVar8 = param_1 & 0xff;
  if ((uVar8 != 0) && (uVar8 < 0xb7)) {
    iVar9 = uVar8 * 0xc;
    sVar1 = *(short *)(&DAT_00665e50 + iVar9);
    sVar11 = *(short *)(&DAT_00665e52 + iVar9);
    uVar2 = *(undefined2 *)(&DAT_00665e56 + iVar9);
    uVar3 = *(undefined2 *)(&DAT_00665e58 + iVar9);
    sVar4 = *(short *)(&DAT_00665e5a + iVar9);
    uVar5 = *(undefined2 *)(&DAT_00665e54 + iVar9);
    func_0x001af060(uVar5,uVar5);
    iVar9 = *(int *)(&DAT_00665df0 + (uint)bRam0034359d * 4);
    piVar10 = *(int **)(iVar9 + (param_1 & 0xff) * 4);
    sVar6 = sVar1;
    if (param_2 == 0) {
      while (*piVar10 != 0) {
        lVar7 = func_0x00109be0(*piVar10,0x25);
        if (lVar7 == 0) {
          if (sVar1 == -1) {
            sVar6 = FUN_0061cc80(*piVar10,uVar5);
          }
          FUN_0061cce0(*piVar10,sVar6,sVar11,uVar2,uVar3,uVar5);
          sVar11 = sVar11 + sVar4;
          piVar10 = piVar10 + 1;
        }
        else {
          sVar11 = sVar11 + sVar4;
          piVar10 = *(int **)(iVar9 + (uint)(byte)(&DAT_00669b5a)[*(char *)((int)lVar7 + 1)] * 4);
        }
      }
    }
    else if (iRam00715360 != 0x7f) {
      iVar9 = func_0x00109be0(*piVar10,0x25);
      iVar12 = iVar9 - *piVar10;
      func_0x0010a4f0(auStack_30,*piVar10,iVar12);
      auStack_30[iVar12] = 0;
      func_0x00109728(auStack_10,0x669bc8,iRam00715360);
      func_0x00109ab0(auStack_30,auStack_10);
      func_0x00109ab0(auStack_30,iVar9 + 2);
      FUN_0061cce0(auStack_30,sVar1,sVar11,uVar2,uVar3,uVar5);
    }
  }
  return;
}



================================================================