FUNCTION FUN_005c50a0 @ 0x005c50a0  size=128
CALLERS (5): FUN_005bbb90@0x005bbb90, FUN_005bb4d0@0x005bb4d0, FUN_005bb670@0x005bb670, FUN_005c0ae0@0x005c0ae0, FUN_005c2460@0x005c2460
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c50a0(uint param_1,char *param_2)

{
  byte bVar1;
  
  bVar1 = (byte)(param_1 >> 0x18);
  *param_2 = (bVar1 >> 4) + 0x30;
  param_2[1] = (bVar1 & 0xf) + 0x30;
  param_2[2] = ((byte)(param_1 >> 0x14) & 0xf) + 0x30;
  param_2[3] = ((byte)(param_1 >> 0x10) & 0xf) + 0x30;
  param_2[4] = ((byte)(param_1 >> 0xc) & 0xf) + 0x30;
  param_2[5] = ((byte)(param_1 >> 8) & 0xf) + 0x30;
  param_2[6] = ((byte)(param_1 >> 4) & 0xf) + 0x30;
  param_2[7] = ((byte)param_1 & 0xf) + 0x30;
  return;
}



================================================================