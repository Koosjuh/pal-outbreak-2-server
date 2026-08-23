FUNCTION FUN_005ba940 @ 0x005ba940  size=184
CALLERS (1): FUN_005fc0c0@0x005fc0c0
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005ba940(int param_1)

{
  undefined1 *puVar1;
  int iVar3;
  int iVar4;
  long lVar2;
  
  iVar4 = 0;
  while( true ) {
    if (1 < iVar4) {
      uRam006c552c = 0;
      fRam006c5528 = 100.0 / (float)param_1;
      return;
    }
    lVar2 = FUN_00618ba0();
    puVar1 = (undefined1 *)lVar2;
    if (lVar2 == 0) break;
    *puVar1 = 1;
    *(code **)(puVar1 + 0xc) = FUN_005baa70;
    iVar3 = iVar4 * 2;
    puVar1[2] = (char)iVar4;
    iVar4 = iVar4 + 1;
    *(undefined2 *)(puVar1 + 0x22) = *(undefined2 *)(&DAT_00639e28 + iVar3);
    *(undefined4 *)(puVar1 + 0x10) = 0x6c552c;
    *(undefined4 *)(puVar1 + 0x34) = 0xffffffe8;
  }
  return;
}



================================================================