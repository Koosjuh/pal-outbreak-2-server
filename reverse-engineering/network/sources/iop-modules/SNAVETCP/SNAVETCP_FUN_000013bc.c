FUNCTION FUN_000013bc @ 0x000013bc size=152
CALLERS (5): FUN_00004cac@0x00004cac, FUN_00007000@0x00007000, FUN_00001ab0@0x00001ab0, FUN_00001dd0@0x00001dd0, FUN_00003840@0x00003840
CALLEES (0): 

uint FUN_000013bc(uint *param_1)

{
  byte bVar1;
  int *piVar2;
  
  bVar1 = (byte)param_1[1];
  if (bVar1 == 2) {
    piVar2 = (int *)((*param_1 >> 0x18) * 0x3c + DAT_00016188);
    return *piVar2 + (uint)*(ushort *)((int)piVar2 + (uint)*(byte *)((int)param_1 + 2) * 6 + 0xe) +
                     (*param_1 & 0xffff);
  }
  if (bVar1 < 3) {
    if (bVar1 != 1) {
      return 0;
    }
  }
  else if (bVar1 != 3) {
    return 0;
  }
  return *param_1;
}


================================================================