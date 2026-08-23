FUNCTION FUN_0001168c @ 0x0001168c size=684
CALLERS (8): FUN_00003cf8@0x00003cf8, FUN_0000c428@0x0000c428, FUN_0000ce24@0x0000ce24, FUN_0000ad44@0x0000ad44, FUN_00004c24@0x00004c24, FUN_000034a8@0x000034a8, FUN_0000b3d4@0x0000b3d4, FUN_00007000@0x00007000
CALLEES (3): FUN_00014e24@0x00014e24, FUN_000120e0@0x000120e0, FUN_000001d0@0x000001d0

void FUN_0001168c(ushort param_1,int param_2,short param_3,short param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  if (param_3 == 2) {
    uVar5 = param_1 | 0x80;
    uVar1 = DAT_00016178 & 4;
  }
  else {
    uVar5 = param_1 | 0xc0;
    if (param_3 != 1) {
      if ((DAT_00016178 & 2) != 0) {
        FUN_00014e24("ave-tcp: ASR nh %d event %d\n",(int)(short)param_1,(int)param_4);
      }
      if ((1 < (ushort)(param_4 - 10U)) && (param_4 != 4)) goto LAB_000118fc;
      iVar2 = (int)(short)param_1;
      iVar3 = iVar2 * 0xc;
      if ((*(short *)(&DAT_00017ea6 + iVar3) == iVar2) &&
         (*(short *)(*(short *)(&DAT_00017ea6 + iVar3) * 0x17c + DAT_00016180 + 0x13a) == 4)) {
        *(ushort *)(&DAT_00017ea0 + iVar3) = param_1;
        *(undefined2 *)(&DAT_00017ea2 + iVar3) = 0xfffa;
        if ((&DAT_00017ea8)[iVar2 * 3] == -1) goto LAB_000118fc;
        uVar4 = (&DAT_00017ea8)[iVar2 * 3];
      }
      else {
        iVar2 = (int)(short)param_1;
        iVar3 = iVar2 * 0xc;
        if ((*(short *)(&DAT_00018834 + iVar3) != iVar2) ||
           (*(short *)(*(short *)(&DAT_00018834 + iVar3) * 0x17c + DAT_00016180 + 0x13a) != 4))
        goto LAB_000118fc;
        *(ushort *)(&DAT_00018830 + iVar3) = param_1;
        *(undefined2 *)(&DAT_00018832 + iVar3) = 0xfffa;
        if ((&DAT_00018838)[iVar2 * 3] == -1) goto LAB_000118fc;
        uVar4 = (&DAT_00018838)[iVar2 * 3];
      }
      FUN_000120e0(uVar4);
      goto LAB_000118fc;
    }
    uVar1 = DAT_00016178 & 0x10;
  }
  param_1 = uVar5;
  if (uVar1 != 0) {
    FUN_00014e24("ave-tcp: ASR nh %d event %d\n",(int)(short)uVar5,(int)param_4);
  }
LAB_000118fc:
  if (param_2 != 0) {
    FUN_000001d0((int)(short)param_1,param_2,(int)param_4);
  }
  return;
}


================================================================