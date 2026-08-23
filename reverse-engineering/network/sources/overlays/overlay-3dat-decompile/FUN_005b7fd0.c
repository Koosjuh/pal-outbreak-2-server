FUNCTION FUN_005b7fd0 @ 0x005b7fd0  size=344
CALLERS (16): FUN_005f62e0@0x005f62e0, FUN_006020e0@0x006020e0, FUN_005b3ed0@0x005b3ed0, FUN_006290e0@0x006290e0, FUN_00604af0@0x00604af0, FUN_006018d0@0x006018d0, FUN_005faa60@0x005faa60, FUN_00602230@0x00602230, FUN_0062d140@0x0062d140, FUN_00601760@0x00601760, FUN_00607b10@0x00607b10, FUN_00627ea0@0x00627ea0, ...
CALLEES (1): FUN_005b8130@0x005b8130
----------------------------------------------------------------

void FUN_005b7fd0(byte param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4)

{
  short *psVar1;
  int iVar2;
  long lVar3;
  short *psVar4;
  
  uRam006c4fd3 = 0;
  for (psVar4 = (short *)(&PTR_DAT_00639440)[param_1]; -1 < *psVar4; psVar4 = psVar4 + 6) {
    lVar3 = FUN_005b8130(psVar4);
    iVar2 = (int)lVar3;
    if (lVar3 == 0) {
      return;
    }
    *(byte *)(iVar2 + 2) = param_1;
    *(undefined1 *)(iVar2 + 0x38) = param_2;
    *(undefined2 *)(iVar2 + 0x26) = *(undefined2 *)(&DAT_00639c20 + psVar4[1] * 4);
    *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(&DAT_00639c22 + psVar4[1] * 4);
    *(undefined4 *)(iVar2 + 0x10) = param_3;
    *(undefined1 *)(iVar2 + 0xb) = param_4;
    *(undefined4 *)(iVar2 + 0x30) = 1;
  }
  psVar4 = (short *)(&PTR_DAT_00639b90)[param_1];
  while( true ) {
    if (*psVar4 < 0) {
      return;
    }
    lVar3 = FUN_005b8130(psVar4);
    iVar2 = (int)lVar3;
    if (lVar3 == 0) break;
    *(byte *)(iVar2 + 2) = param_1;
    *(undefined1 *)(iVar2 + 0x38) = param_2;
    *(undefined2 *)(iVar2 + 0x26) = *(undefined2 *)(&DAT_00639c20 + psVar4[1] * 4);
    psVar1 = psVar4 + 1;
    psVar4 = psVar4 + 6;
    *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(&DAT_00639c22 + *psVar1 * 4);
    *(undefined4 *)(iVar2 + 0x10) = param_3;
    *(undefined1 *)(iVar2 + 0xb) = param_4;
    *(undefined4 *)(iVar2 + 0x30) = 1;
  }
  return;
}



================================================================