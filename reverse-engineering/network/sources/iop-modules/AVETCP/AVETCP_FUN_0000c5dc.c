FUNCTION FUN_0000c5dc @ 0x0000c5dc size=252
CALLERS (1): FUN_00001930@0x00001930
CALLEES (2): FUN_0000b3d4@0x0000b3d4, FUN_00014e24@0x00014e24

void FUN_0000c5dc(void)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  pbVar4 = (byte *)(DAT_00016180 + 0x13f);
  iVar5 = DAT_00016180;
  do {
    if (*(short *)(pbVar4 + -7) != 0) {
      sVar1 = *(short *)(pbVar4 + 0x35);
      if ((*(short *)(pbVar4 + 0x35) != 0) &&
         (*(short *)(pbVar4 + 0x35) = sVar1 + -1, sVar2 = DAT_00016198, sVar1 == 1)) {
        *pbVar4 = *pbVar4 | 1;
        uVar3 = DAT_00016178 & 2;
        *(short *)(pbVar4 + 0x35) = sVar2 / 100;
        if (uVar3 != 0) {
          FUN_00014e24("AT_TCP_Fasttimer: acknow rawsend\n");
        }
        FUN_0000b3d4(iVar5);
      }
    }
    pbVar4 = pbVar4 + 0x17c;
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0x17c;
  } while (iVar6 * 0x10000 >> 0x10 < 3);
  return;
}


================================================================