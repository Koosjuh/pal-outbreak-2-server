FUNCTION FUN_00012cb0 @ 0x00012cb0 size=388
CALLERS (2): FUN_0000e65c@0x0000e65c, FUN_0000ea28@0x0000ea28
CALLEES (4): FUN_00014dd4@0x00014dd4, FUN_00014e24@0x00014e24, FUN_00014ddc@0x00014ddc, FUN_000125c0@0x000125c0

undefined * FUN_00012cb0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 local_18 [2];
  
  if ((DAT_00016178 & 0x80) != 0) {
    FUN_00014e24("ave-tcp: AT_InetAllocPkt called. flg %d\n",param_3);
  }
  FUN_00014dd4(local_18);
  bVar3 = false;
  puVar4 = (undefined *)0x0;
  puVar5 = (undefined *)0x0;
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar1 = iVar1 >> 0x10;
    iVar2 = iVar2 + 1;
    if ((&DAT_00028cf0)[iVar1] == 0) {
      puVar4 = &DAT_00028d88 + iVar1 * 0x634;
      bVar3 = true;
      (&DAT_00028cf0)[iVar1] = 1;
      puVar5 = &DAT_00028d70 + iVar1 * 0x634;
      break;
    }
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 0x20);
  if (bVar3) {
    *(undefined **)(puVar5 + 0x14) = puVar4;
    *(undefined **)(puVar5 + 0x10) = puVar4;
    FUN_00014ddc(local_18[0]);
    if ((DAT_00016178 & 0x80) != 0) {
      FUN_00014e24("ave-tcp: AT_InetAllocPkt buf 0x%08x\n",puVar4);
    }
    if (param_3 != 0) {
      puVar4 = puVar5;
    }
  }
  else {
    FUN_00014ddc(local_18[0]);
    if ((DAT_00016178 & 0x80) != 0) {
      FUN_00014e24("ave-tcp: AT_InetAllocPkt can\'t alloc buffer. return NULL\n");
    }
    FUN_000125c0();
    puVar4 = (undefined *)0x0;
  }
  return puVar4;
}


================================================================