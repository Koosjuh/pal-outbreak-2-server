FUNCTION FUN_0000560c @ 0x0000560c size=396
CALLERS (1): FUN_00000a80@0x00000a80
CALLEES (4): FUN_00007a48@0x00007a48, FUN_00005bbc@0x00005bbc, FUN_00006bc4@0x00006bc4, FUN_0000810c@0x0000810c

int FUN_0000560c(undefined4 param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  iVar3 = 0;
  iVar1 = 0;
  do {
    iVar3 = iVar3 + 1;
    if ((&DAT_0000de90)[(iVar1 >> 0x10) * 0x70a] == 6) {
      uVar5 = 1;
      if ((DAT_00009710 & 2) != 0) {
        FUN_0000810c("pppoe : session state FATAL\n");
      }
      (&DAT_0000de90)[(iVar1 >> 0x10) * 0x70a] = -1;
      break;
    }
    iVar1 = iVar3 * 0x10000;
  } while (iVar3 * 0x10000 < 1);
  iVar3 = 0;
  iVar1 = 0;
  do {
    sVar2 = (short)iVar3;
    psVar4 = &DAT_0000de90 + (iVar1 >> 0x10) * 0x70a;
    iVar3 = iVar3 + 1;
    if (*psVar4 == -1) break;
    iVar1 = iVar3 * 0x10000;
    sVar2 = -1;
  } while (iVar3 * 0x10000 < 1);
  iVar1 = -1;
  if (psVar4 != (short *)0x0) {
    iVar1 = FUN_00007a48(&DAT_0000eca8);
    if (iVar1 << 0x10 < 0) {
      iVar1 = -1;
    }
    else {
      FUN_00005bbc(psVar4,param_1,uVar5);
      *psVar4 = 0;
      FUN_00006bc4(psVar4,200,0x32);
      iVar1 = (int)sVar2;
    }
  }
  return iVar1;
}


================================================================