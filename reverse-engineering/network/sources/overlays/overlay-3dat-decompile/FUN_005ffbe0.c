FUNCTION FUN_005ffbe0 @ 0x005ffbe0  size=480
CALLERS (1): FUN_005ff9f0@0x005ff9f0
CALLEES (2): FUN_005af2f0@0x005af2f0, FUN_006020e0@0x006020e0
----------------------------------------------------------------

void FUN_005ffbe0(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  
  uRam0070b468 = 0;
  iVar4 = 0;
  iVar2 = (int)param_1;
  *(undefined1 *)(iVar2 + 0x908) = 0;
  do {
    if (3 < iVar4) {
LAB_005ffc50:
      *(undefined1 *)(iVar2 + 0x44c) = *(undefined1 *)(iVar2 + 0x908);
      puVar5 = (undefined1 *)
               (iRam003435d4 + 0xc942c +
               (*(char *)(iVar2 + 0x908) * 0x82 + (int)*(char *)(iVar2 + 0x908)) * 0x10);
      func_0x00106b60(puVar5,0,0x830);
      func_0x00109eb8(puVar5 + 0x14,
                      iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) *
                              0x10 + 0x309c);
      func_0x00109eb8(puVar5 + 4,
                      iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) *
                              0x10 + 0x30ac);
      func_0x007deae0(puVar5 + 0x30);
      *puVar5 = 4;
      puVar5[1] = 4;
      puVar5[3] = 1;
      *(char *)(iVar2 + 0xe) = *(char *)(iVar2 + 0xe) + '\x01';
      func_0x001069a8(iRam003435d4 + 0xcb4ec,puVar5,0x830);
      func_0x001069a8(iRam003435d4 + 0xcf5c0,
                      iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) *
                              0x10 + 0x30c0,0xd4);
      func_0x001069a8(iVar2 + 0x3cdc,
                      iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) *
                              0x10 + 0x2e1c,0x3b0);
      FUN_005af2f0(0,1);
      FUN_006020e0(param_1);
      return;
    }
    lVar1 = func_0x00109d70(iVar2 + iVar4 * 0x3b0 + 0x30ac,iVar2 + 0x1e3c);
    if (lVar1 == 0) {
      uVar3 = (undefined1)iVar4;
      *(undefined1 *)(iVar2 + 0x908) = uVar3;
      *(undefined1 *)(iVar2 + 0x4a2) = uVar3;
      *(undefined1 *)(iVar2 + 0x15) = uVar3;
      goto LAB_005ffc50;
    }
    iVar4 = iVar4 + 1;
  } while( true );
}



================================================================