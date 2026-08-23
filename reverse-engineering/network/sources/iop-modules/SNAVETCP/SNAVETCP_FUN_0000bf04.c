FUNCTION FUN_0000bf04 @ 0x0000bf04 size=388
CALLERS (1): FUN_00001930@0x00001930
CALLEES (1): FUN_0000c088@0x0000c088

void FUN_0000bf04(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  DAT_00016168 = 0x4b0;
  iVar5 = 0;
  if (DAT_0001619b != 0) {
    iVar2 = 0;
    do {
      iVar2 = (iVar2 >> 0x10) * 0x17c;
      sVar1 = *(short *)(iVar2 + DAT_00016180 + 0x138);
      if ((sVar1 != 0) && (sVar1 == 1)) {
        iVar4 = 0;
        do {
          iVar3 = iVar2 + DAT_00016180 + (short)iVar4 * 2;
          sVar1 = *(short *)(iVar3 + 0x124);
          if ((*(short *)(iVar3 + 0x124) != 0) &&
             (*(short *)(iVar3 + 0x124) = sVar1 + -1, sVar1 == 1)) {
            FUN_0000c088();
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 * 0x10000 >> 0x10 < 4);
        iVar2 = (short)iVar5 * 0x17c + DAT_00016180;
        *(short *)(iVar2 + 0x110) = *(short *)(iVar2 + 0x110) + 1;
        if (*(short *)(iVar2 + 0x112) != 0) {
          *(short *)(iVar2 + 0x112) = *(short *)(iVar2 + 0x112) + 1;
        }
      }
      iVar5 = iVar5 + 1;
      iVar2 = iVar5 * 0x10000;
    } while (iVar5 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
  }
  DAT_00016164 = DAT_00016164 + 64000;
  return;
}


================================================================