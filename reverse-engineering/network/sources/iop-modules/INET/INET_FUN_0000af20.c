FUNCTION FUN_0000af20 @ 0x0000af20 size=128
CALLERS (2): FUN_0000b0ac@0x0000b0ac, FUN_0000afa0@0x0000afa0
CALLEES (0): 

void FUN_0000af20(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  puVar2 = &DAT_0001db10;
  iVar4 = 0x7a4;
  do {
    puVar1 = (uint *)((int)&DAT_0001db10 + iVar4);
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
    *puVar2 = *puVar2 ^ *puVar1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 0x20);
  iVar3 = 0x20;
  puVar2 = &DAT_0001db90;
  iVar4 = 0;
  do {
    puVar1 = (uint *)((int)&DAT_0001db10 + iVar4);
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
    *puVar2 = *puVar2 ^ *puVar1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 0x209);
  return;
}


================================================================