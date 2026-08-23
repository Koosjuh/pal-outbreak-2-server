FUNCTION FUN_00005e94 @ 0x00005e94 size=124
CALLERS (4): FUN_00003840@0x00003840, FUN_00007000@0x00007000, FUN_00005828@0x00005828, FUN_0000223c@0x0000223c
CALLEES (1): FUN_00004254@0x00004254

undefined4 FUN_00005e94(uint param_1,short param_2)

{
  int iVar1;
  
  iVar1 = FUN_00004254((int)param_2);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(iVar1 + 4) != 0) {
    if (param_1 == 0xffffffff) {
      return 1;
    }
    if (param_1 != *(uint *)(iVar1 + 8)) {
      if ((*(uint *)(iVar1 + 8) & 1) != 0) {
        return 0;
      }
      if (param_1 == 0) {
        return 1;
      }
      return 0;
    }
  }
  return 1;
}


================================================================