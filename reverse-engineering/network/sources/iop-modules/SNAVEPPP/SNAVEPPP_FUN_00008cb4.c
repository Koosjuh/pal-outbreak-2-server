FUNCTION FUN_00008cb4 @ 0x00008cb4 size=380
CALLERS (1): FUN_000054a8@0x000054a8
CALLEES (1): FUN_0000236c@0x0000236c

void FUN_00008cb4(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined1 local_60 [4];
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined2 local_40 [8];
  undefined2 local_30;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20 [4];
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  
  sVar1 = FUN_0000236c(local_60);
  iVar3 = 0;
  if (sVar1 == 0) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 >> 0x10;
      (&DAT_00014aa0)[iVar2] = local_60[iVar2];
      (&DAT_00014aa4)[iVar2] = local_5c[iVar2];
      (&DAT_00014aa8)[iVar2] = local_58[iVar2];
      (&DAT_00014aac)[iVar2] = local_54[iVar2];
      (&DAT_00014ab0)[iVar2] = local_50[iVar2];
      iVar3 = iVar3 + 1;
      (&DAT_00014ab4)[iVar2] = local_4c[iVar2];
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < 4);
    iVar3 = 0;
    DAT_00014ab8 = local_48;
    DAT_00014abc = local_44;
    iVar2 = 0;
    do {
      iVar2 = iVar2 >> 0x10;
      (&DAT_00014ac0)[iVar2] = local_40[iVar2 * 2];
      iVar3 = iVar3 + 1;
      (&DAT_00014ad4)[iVar2] = local_20[iVar2];
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < 4);
    DAT_00014ac8 = local_30;
    DAT_00014aca = local_2c;
    DAT_00014acc = local_28;
    DAT_00014ad0 = local_24;
    DAT_00014adc = local_18;
    DAT_00014ade = local_16;
    DAT_00014ae0 = local_14;
    DAT_00014ae2 = local_12;
    DAT_00014ae4 = local_10;
  }
  return;
}


================================================================