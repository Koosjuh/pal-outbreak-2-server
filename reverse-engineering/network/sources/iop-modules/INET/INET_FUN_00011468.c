FUNCTION FUN_00011468 @ 0x00011468 size=116
CALLERS (1): FUN_000114dc@0x000114dc
CALLEES (0): 

int FUN_00011468(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = 0;
  uVar6 = 0;
  do {
    uVar4 = *param_1;
    param_1 = param_1 + 1;
    if (uVar4 != 0xffffffff) {
      iVar3 = 0;
      uVar1 = 1;
      do {
        if ((uVar4 & uVar1) == 0) {
          iVar2 = -1;
          if (iVar5 + iVar3 < 100) {
            iVar2 = iVar5 + iVar3;
          }
          return iVar2;
        }
        iVar3 = iVar3 + 1;
        uVar1 = uVar1 << 1;
      } while (iVar3 < 0x20);
    }
    uVar6 = uVar6 + 1;
    iVar5 = iVar5 + 0x20;
  } while (uVar6 < 0x19);
  return -1;
}


================================================================