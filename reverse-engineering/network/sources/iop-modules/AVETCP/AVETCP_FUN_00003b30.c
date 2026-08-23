FUNCTION FUN_00003b30 @ 0x00003b30 size=124
CALLERS (8): FUN_0000af84@0x0000af84, FUN_00001dd0@0x00001dd0, FUN_00003840@0x00003840, FUN_00007000@0x00007000, FUN_00001ab0@0x00001ab0, FUN_0000353c@0x0000353c, FUN_0000b3d4@0x0000b3d4, FUN_00004cac@0x00004cac
CALLEES (1): FUN_000014a8@0x000014a8

uint FUN_00003b30(undefined1 *param_1,undefined4 param_2,short param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (param_1 != (undefined1 *)0x0) {
    iVar5 = 6;
    do {
      uVar2 = *param_1;
      puVar1 = param_1 + 1;
      param_1 = param_1 + 2;
      iVar5 = iVar5 + -1;
      iVar4 = iVar4 + (uint)CONCAT11(uVar2,*puVar1);
    } while (0 < iVar5 * 0x10000);
  }
  uVar3 = FUN_000014a8(iVar4,param_2,(int)param_3);
  uVar3 = (uVar3 >> 0x10) + (uVar3 & 0xffff);
  return ~(uVar3 + (uVar3 >> 0x10)) & 0xffff;
}


================================================================