FUNCTION FUN_005b4c80 @ 0x005b4c80  size=288
CALLERS (6): FUN_005faa60@0x005faa60, FUN_005b47a0@0x005b47a0, FUN_005b3cb0@0x005b3cb0, FUN_005b45f0@0x005b45f0, FUN_005b3ed0@0x005b3ed0, FUN_005b41b0@0x005b41b0
CALLEES (1): FUN_005b8130@0x005b8130
----------------------------------------------------------------

void FUN_005b4c80(char param_1)

{
  short *psVar1;
  int iVar2;
  long lVar3;
  short *psVar4;
  
  uRam006c4fcd = 0xff;
  for (psVar4 = (short *)(&PTR_DAT_00638d40)[param_1]; -1 < *psVar4; psVar4 = psVar4 + 6) {
    lVar3 = FUN_005b8130(psVar4);
    iVar2 = (int)lVar3;
    if (lVar3 == 0) {
      return;
    }
    *(undefined2 *)(iVar2 + 0x26) = *(undefined2 *)(&DAT_00638e40 + psVar4[1] * 4);
    *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(&DAT_00638e42 + psVar4[1] * 4);
    *(char *)(iVar2 + 2) = param_1;
    *(undefined4 *)(iVar2 + 0x30) = 0;
  }
  psVar4 = (short *)(&PTR_DAT_00638e10)[param_1];
  while( true ) {
    if (*psVar4 < 0) {
      return;
    }
    lVar3 = FUN_005b8130(psVar4);
    iVar2 = (int)lVar3;
    if (lVar3 == 0) break;
    *(undefined2 *)(iVar2 + 0x26) = *(undefined2 *)(&DAT_00638e40 + psVar4[1] * 4);
    psVar1 = psVar4 + 1;
    psVar4 = psVar4 + 6;
    *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(&DAT_00638e42 + *psVar1 * 4);
    *(char *)(iVar2 + 2) = param_1;
    *(undefined4 *)(iVar2 + 0x30) = 0;
  }
  return;
}



================================================================