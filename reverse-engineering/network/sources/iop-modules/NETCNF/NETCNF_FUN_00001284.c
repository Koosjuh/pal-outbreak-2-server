FUNCTION FUN_00001284 @ 0x00001284 size=120
CALLERS (2): FUN_00000fe4@0x00000fe4, FUN_00000da8@0x00000da8
CALLEES (0): 

void FUN_00001284(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 2;
  do {
    pbVar1 = (byte *)(param_1 + iVar3);
    *(byte *)(iVar2 + 0xb1ee) = (*pbVar1 >> 5) + 1;
    *(byte *)(iVar2 + 0xb1ef) = (*pbVar1 >> 2 & 7) + 1;
    iVar3 = iVar3 + 1;
    (&DAT_0000b1f0)[iVar2] = (*pbVar1 & 3) + 1;
    iVar2 = iVar2 + 3;
  } while (iVar3 < 8);
  return;
}


================================================================