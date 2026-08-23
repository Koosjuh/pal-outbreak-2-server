FUNCTION FUN_00001454 @ 0x00001454 size=84
CALLERS (15): FUN_00009c90@0x00009c90, FUN_00011514@0x00011514, FUN_0000ef14@0x0000ef14, FUN_00003840@0x00003840, FUN_00007000@0x00007000, FUN_0000313c@0x0000313c, FUN_00004ec4@0x00004ec4, FUN_0000a264@0x0000a264, FUN_00001dd0@0x00001dd0, FUN_00008c70@0x00008c70, FUN_00001ab0@0x00001ab0, FUN_00008dc4@0x00008dc4, FUN_0000353c@0x0000353c, FUN_000097cc@0x000097cc, FUN_00002ae8@0x00002ae8
CALLEES (0): 

void FUN_00001454(int *param_1,short param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 1);
  if (bVar1 != 2) {
    if (bVar1 < 3) {
      if (bVar1 != 1) {
        return;
      }
    }
    else if (bVar1 != 3) {
      return;
    }
  }
  *param_1 = *param_1 + (int)param_2;
  return;
}


================================================================