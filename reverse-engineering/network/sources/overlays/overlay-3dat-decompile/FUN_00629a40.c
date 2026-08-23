FUNCTION FUN_00629a40 @ 0x00629a40  size=212
CALLERS (2): FUN_00628f00@0x00628f00, FUN_006290e0@0x006290e0
CALLEES (4): FUN_005ba7b0@0x005ba7b0, FUN_00618b60@0x00618b60, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570
----------------------------------------------------------------

void FUN_00629a40(undefined4 param_1,char param_2)

{
  short *psVar1;
  undefined1 *puVar2;
  long lVar3;
  short *psVar4;
  
  FUN_00618b60();
  psVar4 = (short *)(&PTR_DAT_0066ac90)[param_2];
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
    *(undefined2 *)(puVar2 + 0x26) = *(undefined2 *)(&DAT_0066ac30 + psVar4[1] * 4);
    psVar1 = psVar4 + 1;
    psVar4 = psVar4 + 6;
    *(undefined2 *)(puVar2 + 0x28) = *(undefined2 *)(&DAT_0066ac32 + *psVar1 * 4);
  }
  return;
}



================================================================