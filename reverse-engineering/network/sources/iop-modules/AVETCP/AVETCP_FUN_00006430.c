FUNCTION FUN_00006430 @ 0x00006430 size=96
CALLERS (1): FUN_000060c0@0x000060c0
CALLEES (0): 

undefined4 FUN_00006430(int param_1)

{
  ushort *puVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  sVar3 = 0;
  iVar2 = *(int *)(param_1 + 0x10);
  iVar4 = 0;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = iVar4 + 1;
    if ((*(short *)(iVar2 + 8) != sVar3) || (7 < iVar4 * 0x10000 >> 0x10)) break;
    puVar1 = (ushort *)(iVar2 + 10);
    iVar2 = *(int *)(iVar2 + 0xc);
    sVar3 = sVar3 + (*puVar1 >> 3);
  }
  return 0xffffffff;
}


================================================================