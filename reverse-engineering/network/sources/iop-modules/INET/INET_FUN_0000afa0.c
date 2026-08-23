FUNCTION FUN_0000afa0 @ 0x0000afa0 size=268
CALLERS (1): FUN_00012170@0x00012170
CALLEES (1): FUN_0000af20@0x0000af20

void FUN_0000afa0(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar3 = 0;
  iVar2 = 0x1f;
  do {
    do {
      iVar2 = iVar2 + -1;
      param_1 = param_1 * 0x5d588b65 + 1;
      uVar1 = uVar1 >> 1 | param_1 & 0x80000000;
    } while (-1 < iVar2);
    (&DAT_0001db10)[iVar3] = uVar1;
    iVar3 = iVar3 + 1;
    iVar2 = 0x1f;
  } while (iVar3 < 0x11);
  iVar3 = 0x11;
  iVar2 = 0x40;
  DAT_0001db50 = DAT_0001db50 << 0x17 ^ DAT_0001db10 >> 9 ^ DAT_0001db4c;
  do {
    iVar3 = iVar3 + 1;
    *(uint *)((int)&DAT_0001db14 + iVar2) =
         *(int *)(iVar2 + 0x1dad0) << 0x17 ^ *(uint *)(iVar2 + 0x1dad4) >> 9 ^
         *(uint *)((int)&DAT_0001db10 + iVar2);
    iVar2 = iVar2 + 4;
  } while (iVar3 < 0x209);
  FUN_0000af20();
  FUN_0000af20();
  FUN_0000af20();
  DAT_0001b980 = 0x208;
  return;
}


================================================================