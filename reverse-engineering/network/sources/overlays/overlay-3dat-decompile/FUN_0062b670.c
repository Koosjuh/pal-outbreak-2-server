FUNCTION FUN_0062b670 @ 0x0062b670  size=212
CALLERS (2): FUN_0062a680@0x0062a680, FUN_0062aeb0@0x0062aeb0
CALLEES (4): FUN_005ba7b0@0x005ba7b0, FUN_00618b60@0x00618b60, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570
----------------------------------------------------------------

void FUN_0062b670(undefined4 param_1,char param_2)

{
  short *psVar1;
  undefined1 *puVar2;
  long lVar3;
  short *psVar4;
  
  FUN_00618b60();
  psVar4 = (short *)(&PTR_DAT_0066aec0)[param_2];
  while( true ) {
    if (*psVar4 < 0) {
      FUN_005ba570();
      FUN_005ba7b0();
      return;
    }
    lVar3 = FUN_00618ba0(0xd);
    if (lVar3 == 0) break;
    puVar2 = (undefined1 *)lVar3;
    *puVar2 = 1;
    puVar2[1] = 1;
    *(short *)(puVar2 + 0x22) = *psVar4;
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(psVar4 + 4);
    puVar2[3] = *(undefined1 *)((int)psVar4 + 5);
    *(undefined4 *)(puVar2 + 0x10) = param_1;
    *(undefined2 *)(puVar2 + 0x26) = *(undefined2 *)(&DAT_0066aeb0 + psVar4[1] * 4);
    psVar1 = psVar4 + 1;
    psVar4 = psVar4 + 6;
    *(undefined2 *)(puVar2 + 0x28) = *(undefined2 *)(&DAT_0066aeb2 + *psVar1 * 4);
  }
  return;
}



================================================================