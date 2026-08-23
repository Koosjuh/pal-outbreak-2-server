FUNCTION FUN_005da650 @ 0x005da650  size=212
CALLERS (18): FUN_005d8d60@0x005d8d60, FUN_005d8b90@0x005d8b90, FUN_005d8ea0@0x005d8ea0, FUN_005d9ac0@0x005d9ac0, FUN_005d8c90@0x005d8c90, FUN_005d9940@0x005d9940, FUN_005d9450@0x005d9450, FUN_005da420@0x005da420, FUN_005d9160@0x005d9160, FUN_005d9030@0x005d9030, FUN_005d8e00@0x005d8e00, FUN_005d8f90@0x005d8f90, ...
CALLEES (0): 
----------------------------------------------------------------

void FUN_005da650(int param_1,int param_2)

{
  if (*(int *)(iRam00701070 + 0x10) < param_2) {
    *(int *)(iRam00701070 + 0x10) = param_2;
    *(short *)(iRam00701070 + 0x22) = (short)(0x20490 / *(int *)(iRam00701070 + 0x10));
    if (0x17c < *(int *)(iRam00701070 + 0x10)) {
      *(undefined1 *)(iRam00701070 + 0x2a) = 1;
    }
  }
  if (*(int *)(iRam00701070 + 0xc) <= param_1) {
    *(int *)(iRam00701070 + 0xc) = param_1;
    *(short *)(iRam00701070 + 0x26) = (short)(0x4eb40 / *(int *)(iRam00701070 + 0xc));
    if (0x248 < *(int *)(iRam00701070 + 0xc)) {
      *(undefined1 *)(iRam00701070 + 0x2b) = 1;
    }
  }
  return;
}



================================================================