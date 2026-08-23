FUNCTION FUN_00008918 @ 0x00008918 size=924
CALLERS (1): FUN_00007fb4@0x00007fb4
CALLEES (9): FUN_00002d88@0x00002d88, FUN_00010b4c@0x00010b4c, FUN_00010aac@0x00010aac, FUN_00007da4@0x00007da4, FUN_00007894@0x00007894, FUN_00010c38@0x00010c38, FUN_00010abc@0x00010abc, FUN_000103cc@0x000103cc, FUN_00010b44@0x00010b44

undefined4 FUN_00008918(short param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  
  iVar3 = FUN_00002d88();
  if (iVar3 == 0) {
    return 1;
  }
  DAT_00013608 = FUN_000103cc();
  DAT_0001360c = param_1 * 1000;
  FUN_00010b4c(&DAT_000161c0,0,0x200);
  while( true ) {
    FUN_00010b44(&DAT_000161c0,&DAT_000161c1,0x1ff);
    sVar2 = FUN_00007894(&DAT_000163bf,1);
    if (sVar2 != 0) {
      return 4;
    }
    iVar4 = FUN_00010aac(*(undefined4 *)(iVar3 + 0x1c));
    sVar2 = FUN_00010abc((int)&DAT_000163c0 - iVar4,*(undefined4 *)(iVar3 + 0x1c),iVar4);
    if (sVar2 == 0) {
      if ((DAT_00012efc & 1) != 0) {
        FUN_00010c38("ave-ppp: WaitStringConnect %s\n",*(undefined4 *)(iVar3 + 0x1c));
      }
      uVar6 = 0;
      if (*(short *)(iVar3 + 8) != 0) {
        DAT_00012ef4 = 0;
        do {
          sVar2 = FUN_00007894(&DAT_000161c0 + uVar6,1);
          if (sVar2 != 0) {
            return 4;
          }
        } while (((&DAT_000161c0)[uVar6] != *(char *)(iVar3 + 0x38)) &&
                (uVar6 = uVar6 + 1, uVar6 < 0x1ff));
        (&DAT_000161c0)[uVar6] = 0;
        sVar2 = FUN_00007da4(&DAT_000161c0);
        pbVar5 = &DAT_000161c0 + sVar2;
        while( true ) {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          if (9 < bVar1 - 0x30) break;
          DAT_00012ef4 = DAT_00012ef4 * 10 + -0x30 + (uint)bVar1;
        }
      }
      return 0;
    }
    iVar4 = FUN_00010aac(*(undefined4 *)(iVar3 + 0x20));
    sVar2 = FUN_00010abc((int)&DAT_000163c0 - iVar4,*(undefined4 *)(iVar3 + 0x20),iVar4);
    if (sVar2 == 0) {
      if ((DAT_00012efc & 1) == 0) {
        return 2;
      }
      FUN_00010c38("ave-ppp: WaitStringConnect %s\n",*(undefined4 *)(iVar3 + 0x20));
      return 2;
    }
    iVar4 = FUN_00010aac(*(undefined4 *)(iVar3 + 0x24));
    sVar2 = FUN_00010abc((int)&DAT_000163c0 - iVar4,*(undefined4 *)(iVar3 + 0x24),iVar4);
    if (sVar2 == 0) break;
    iVar4 = FUN_00010aac(*(undefined4 *)(iVar3 + 0x28));
    sVar2 = FUN_00010abc((int)&DAT_000163c0 - iVar4,*(undefined4 *)(iVar3 + 0x28),iVar4);
    if (sVar2 == 0) {
      if ((DAT_00012efc & 1) == 0) {
        return 0xd;
      }
      FUN_00010c38("ave-ppp: WaitStringConnect %s\n",*(undefined4 *)(iVar3 + 0x28));
      return 0xd;
    }
    iVar4 = FUN_00010aac(*(undefined4 *)(iVar3 + 0x2c));
    sVar2 = FUN_00010abc((int)&DAT_000163c0 - iVar4,*(undefined4 *)(iVar3 + 0x2c),iVar4);
    if (sVar2 == 0) {
      if ((DAT_00012efc & 1) == 0) {
        return 0xc;
      }
      FUN_00010c38("ave-ppp: WaitStringConnect %s\n",*(undefined4 *)(iVar3 + 0x2c));
      return 0xc;
    }
    iVar4 = FUN_00010aac(*(undefined4 *)(iVar3 + 0x30));
    sVar2 = FUN_00010abc((int)&DAT_000163c0 - iVar4,*(undefined4 *)(iVar3 + 0x30),iVar4);
    if (sVar2 == 0) {
      if ((DAT_00012efc & 1) == 0) {
        return 3;
      }
      FUN_00010c38("ave-ppp: WaitStringConnect %s\n",*(undefined4 *)(iVar3 + 0x30));
      return 3;
    }
  }
  if ((DAT_00012efc & 1) == 0) {
    return 0xb;
  }
  FUN_00010c38("ave-ppp: WaitStringConnect %s\n",*(undefined4 *)(iVar3 + 0x24));
  return 0xb;
}


================================================================