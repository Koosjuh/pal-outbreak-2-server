FUNCTION FUN_0062c1d0 @ 0x0062c1d0  size=376
CALLERS (1): FUN_0062ba70@0x0062ba70
CALLEES (4): FUN_0062cf50@0x0062cf50, FUN_00618b60@0x00618b60, FUN_0062cd20@0x0062cd20, FUN_00629d00@0x00629d00
----------------------------------------------------------------

undefined8 FUN_0062c1d0(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  lVar3 = FUN_0062cf50(param_1,0x7154a0);
  if (lVar3 != 0) {
    puVar5 = (undefined1 *)param_2;
    *puVar5 = 1;
    puVar5[1] = 0;
    puVar5[2] = 0;
    FUN_00618b60();
    FUN_0062cd20(param_2,0);
    FUN_00629d00(param_2,3);
    FUN_00629d00(param_2,4);
    iVar4 = 0;
    bVar1 = false;
    iVar2 = 0;
    do {
      iVar6 = (int)param_1;
      iVar2 = iVar6 + iVar2 * 4 + iVar4 * 5;
      lVar3 = func_0x00109d70(0x7154b1,iVar2 + 0x1055);
      if (lVar3 == 0) {
        func_0x00109eb8(iVar2 + 0x1055,0x7154b1);
        bVar1 = true;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar4 * 8;
    } while (iVar4 < 3);
    if (cRam007154b1 == '\0') {
      func_0x00106b60(iVar6 + *(short *)(puVar5 + 10) * 0x24 + (int)*(short *)(puVar5 + 10) + 0x1045
                      ,0,0x10);
      func_0x00106b60(iVar6 + *(short *)(puVar5 + 10) * 0x24 + (int)*(short *)(puVar5 + 10) + 0x1055
                      ,0,0x14);
    }
    if (!bVar1) {
      func_0x00109eb8(iVar6 + *(short *)(puVar5 + 10) * 0x24 + (int)*(short *)(puVar5 + 10) + 0x1055
                      ,0x7154b1);
    }
  }
  return 0;
}



================================================================