FUNCTION FUN_006332a0 @ 0x006332a0  size=176
CALLERS (2): FUN_00632d20@0x00632d20, FUN_00633210@0x00633210
CALLEES (0): 
----------------------------------------------------------------

long FUN_006332a0(int param_1,int param_2,long param_3)

{
  long lVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  
  lVar1 = (long)*(char *)(param_1 + 0xf);
  iVar7 = 0;
  lVar6 = lVar1;
  if (param_3 < lVar1) {
    lVar1 = -1;
  }
  else {
    for (; *(char *)(param_1 + 0x1f) == -1; param_1 = param_1 + 0x10) {
      iVar5 = 0;
      do {
        puVar2 = (undefined1 *)(param_1 + iVar5);
        puVar3 = (undefined1 *)(param_2 + iVar7 * 0xe + iVar5);
        iVar5 = iVar5 + 1;
        *puVar3 = *puVar2;
      } while (iVar5 < 0xe);
      iVar7 = iVar7 + 1;
      lVar6 = (long)((int)lVar6 + -0xe);
    }
    lVar4 = 0;
    while( true ) {
      iVar5 = (int)lVar4;
      if (lVar6 <= lVar4) break;
      lVar4 = (long)(iVar5 + 1);
      *(undefined1 *)(param_2 + iVar7 * 0xe + iVar5) = *(undefined1 *)(param_1 + iVar5);
    }
    *(undefined1 *)(param_2 + iVar5 + iVar7 * 0xe) = 0;
  }
  return lVar1;
}



================================================================