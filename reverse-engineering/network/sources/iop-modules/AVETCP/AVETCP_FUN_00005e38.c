FUNCTION FUN_00005e38 @ 0x00005e38 size=92
CALLERS (2): FUN_00005828@0x00005828, FUN_00004ec4@0x00004ec4
CALLEES (0): 

uint FUN_00005e38(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = param_2 << 0x10;
  while (0 < iVar3) {
    uVar2 = *param_1;
    puVar1 = param_1 + 1;
    param_1 = param_1 + 2;
    param_2 = param_2 + -1;
    uVar4 = uVar4 + CONCAT11(uVar2,*puVar1);
    iVar3 = param_2 * 0x10000;
  }
  uVar4 = (uVar4 >> 0x10) + (uVar4 & 0xffff);
  return ~(uVar4 + (uVar4 >> 0x10)) & 0xffff;
}


================================================================