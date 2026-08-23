FUNCTION FUN_00617bb0 @ 0x00617bb0  size=120
CALLERS (1): FUN_00617110@0x00617110
CALLEES (2): FUN_005ba7b0@0x005ba7b0, FUN_005b8130@0x005b8130
----------------------------------------------------------------

void FUN_00617bb0(void)

{
  int iVar1;
  long lVar2;
  short *psVar3;
  
  psVar3 = &DAT_00654210;
  while( true ) {
    if (*psVar3 < 0) {
      FUN_005ba7b0();
      return;
    }
    lVar2 = FUN_005b8130(psVar3);
    if (lVar2 == 0) break;
    iVar1 = (int)lVar2;
    if (*(short *)(iVar1 + 0x22) == 0xad) {
      *(undefined4 *)(iVar1 + 0x34) = 0xfffffff6;
      *(undefined4 *)(iVar1 + 0x30) = 2;
    }
    else {
      *(undefined4 *)(iVar1 + 0x30) = 1;
    }
    psVar3 = psVar3 + 6;
  }
  return;
}



================================================================