FUNCTION FUN_000130e8 @ 0x000130e8 size=128
CALLERS (0): 
CALLEES (1): FUN_00014e24@0x00014e24

void FUN_000130e8(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  FUN_00014e24("=== USED STRUCUTER BUFFER =========================\n");
  iVar3 = 0;
  puVar1 = &DAT_00022d60;
  puVar2 = &DAT_00022d78;
  do {
    FUN_00014e24("STU = [%08x], BUF = [%08x]\n",puVar1,puVar2);
    puVar2 = puVar2 + 0x634;
    iVar3 = iVar3 + 1;
    puVar1 = puVar1 + 0x634;
  } while (iVar3 < 0x20);
  FUN_00014e24("===================================================\n");
  return;
}


================================================================