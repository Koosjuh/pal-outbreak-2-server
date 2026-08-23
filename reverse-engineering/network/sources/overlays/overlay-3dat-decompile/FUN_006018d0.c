FUNCTION FUN_006018d0 @ 0x006018d0  size=368
CALLERS (1): FUN_005fede0@0x005fede0
CALLEES (5): FUN_005ba7b0@0x005ba7b0, FUN_00618b60@0x00618b60, FUN_00618ba0@0x00618ba0, FUN_005b7fd0@0x005b7fd0, FUN_005b6c90@0x005b6c90
----------------------------------------------------------------

void FUN_006018d0(int param_1)

{
  undefined1 *puVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  *(undefined1 *)(param_1 + 0x43d) = 0xff;
  *(undefined1 *)(param_1 + 0x907) = *(undefined1 *)(param_1 + 0x909);
  FUN_00618b60();
  iVar4 = 0;
  do {
    lVar2 = FUN_00618ba0();
    if (lVar2 != 0) {
      iVar3 = iVar4 * 0x1c;
      puVar1 = (undefined1 *)lVar2;
      *puVar1 = 1;
      puVar1[1] = 1;
      *(short *)(puVar1 + 0x22) = (short)*(undefined4 *)(&DAT_00649c30 + iVar3);
      if (*(int *)(&DAT_00649c34 + iVar3) != 0) {
        *(int *)(puVar1 + 0x34) = *(int *)(&DAT_00649c34 + iVar3);
      }
      *(undefined4 *)(puVar1 + 0x30) = *(undefined4 *)(&DAT_00649c38 + iVar3);
      *(undefined **)(puVar1 + 0xc) = (&PTR_FUN_00649c3c)[iVar4 * 7];
      puVar1[2] = (char)*(undefined4 *)(&DAT_00649c40 + iVar3);
      *(short *)(puVar1 + 0x26) = (short)*(undefined4 *)(&DAT_00649c44 + iVar3);
      *(short *)(puVar1 + 0x28) = (short)*(undefined4 *)(&DAT_00649c48 + iVar3);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  lVar2 = FUN_00618ba0();
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    if (*(char *)(param_1 + 0x97e) == '\0') {
      *(undefined2 *)(puVar1 + 0x22) = 0x56;
      FUN_005b6c90(8,4,param_1 + 0x907);
    }
    else {
      *(undefined2 *)(puVar1 + 0x22) = 0x55;
      FUN_005b6c90(7,4,param_1 + 0x907);
    }
    *(undefined4 *)(puVar1 + 0x30) = 1;
    if (*(char *)(param_1 + 0x97e) == '\0') {
      FUN_005b7fd0(0x1d,0,param_1 + 0x907,3);
    }
    else {
      FUN_005b7fd0(0x1e,0,param_1 + 0x907,4);
    }
    FUN_005ba7b0();
  }
  return;
}



================================================================