FUNCTION FUN_00628760 @ 0x00628760  size=248
CALLERS (2): FUN_0062d140@0x0062d140, FUN_00627ea0@0x00627ea0
CALLEES (3): FUN_005ba7b0@0x005ba7b0, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570
----------------------------------------------------------------

void FUN_00628760(undefined4 param_1,long param_2)

{
  short *psVar1;
  undefined1 *puVar2;
  long lVar3;
  short *psVar4;
  
  psVar4 = (short *)(&PTR_DAT_0066a988)[(int)param_2];
  while( true ) {
    if (*psVar4 < 0) {
      if (param_2 == 1) {
        FUN_005ba570(9);
      }
      else if (param_2 == 0) {
        FUN_005ba570(0x23);
      }
      FUN_005ba7b0();
      return;
    }
    lVar3 = FUN_00618ba0();
    if (lVar3 == 0) break;
    puVar2 = (undefined1 *)lVar3;
    *puVar2 = 1;
    puVar2[1] = 1;
    *(short *)(puVar2 + 0x22) = *psVar4;
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(psVar4 + 4);
    puVar2[3] = *(undefined1 *)((int)psVar4 + 5);
    *(undefined4 *)(puVar2 + 0x10) = param_1;
    *(undefined2 *)(puVar2 + 0x26) = *(undefined2 *)(&DAT_0066a990 + psVar4[1] * 4);
    psVar1 = psVar4 + 1;
    psVar4 = psVar4 + 6;
    *(undefined2 *)(puVar2 + 0x28) = *(undefined2 *)(&DAT_0066a992 + *psVar1 * 4);
  }
  return;
}



================================================================