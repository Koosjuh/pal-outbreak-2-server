FUNCTION FUN_005bc370 @ 0x005bc370  size=180
CALLERS (2): FUN_005bb670@0x005bb670, FUN_005bc430@0x005bc430
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bc370(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  
  func_0x00106b60(0x6ce046,0,0x460);
  iVar2 = 0;
  iVar6 = 0;
  iVar3 = 0;
  do {
    iVar3 = (iVar3 - iVar6) * 0x28;
    puVar5 = (undefined1 *)(iVar3 + 0x6cdbe6);
    if (*(char *)(iVar3 + 0x6cdce7) == '\x01') {
      iVar3 = 0x8c;
      puVar4 = (undefined1 *)(iVar2 * 0x118 + 0x6ce046);
      do {
        iVar3 = iVar3 + -1;
        uVar1 = puVar5[1];
        *puVar4 = *puVar5;
        puVar5 = puVar5 + 2;
        puVar4[1] = uVar1;
        puVar4 = puVar4 + 2;
      } while (0 < iVar3);
      iVar2 = iVar2 + 1;
    }
    iVar6 = iVar6 + 1;
    iVar3 = iVar6 * 8;
  } while (iVar6 < 4);
  return;
}



================================================================