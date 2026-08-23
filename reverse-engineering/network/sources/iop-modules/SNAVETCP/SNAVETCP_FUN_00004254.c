FUNCTION FUN_00004254 @ 0x00004254 size=100
CALLERS (15): FUN_00002394@0x00002394, FUN_00005e94@0x00005e94, FUN_0000f344@0x0000f344, FUN_00004ec4@0x00004ec4, FUN_0000acf0@0x0000acf0, FUN_00005f10@0x00005f10, FUN_0000f308@0x0000f308, FUN_00002d9c@0x00002d9c, FUN_000045ec@0x000045ec, FUN_000049c4@0x000049c4, FUN_00005828@0x00005828, FUN_000025a4@0x000025a4, FUN_00002020@0x00002020, FUN_00002f1c@0x00002f1c, FUN_00004a30@0x00004a30
CALLEES (0): 

int FUN_00004254(short param_1)

{
  int iVar1;
  
  if ((int)DAT_00016160 <= (int)param_1) {
    return 0;
  }
  iVar1 = param_1 * 0x2c;
  if ((&DAT_00022871)[iVar1] != '\x02') {
    return 0;
  }
  return iVar1 + 0x22870;
}


================================================================