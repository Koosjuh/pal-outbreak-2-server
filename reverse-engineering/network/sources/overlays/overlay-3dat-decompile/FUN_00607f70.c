FUNCTION FUN_00607f70 @ 0x00607f70  size=112
CALLERS (1): FUN_00607ac0@0x00607ac0
CALLEES (3): FUN_005ba7b0@0x005ba7b0, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570
----------------------------------------------------------------

void FUN_00607f70(void)

{
  undefined1 *puVar1;
  long lVar2;
  short *psVar3;
  
  psVar3 = &DAT_0064a0a0;
  while( true ) {
    if (*psVar3 < 0) {
      FUN_005ba570();
      FUN_005ba7b0();
      return;
    }
    lVar2 = FUN_00618ba0(0x1f);
    if (lVar2 == 0) break;
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(short *)(puVar1 + 0x22) = *psVar3;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(psVar3 + 4);
    psVar3 = psVar3 + 6;
  }
  return;
}



================================================================