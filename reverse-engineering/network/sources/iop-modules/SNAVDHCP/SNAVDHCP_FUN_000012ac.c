FUNCTION FUN_000012ac @ 0x000012ac size=124
CALLERS (3): FUN_00001568@0x00001568, FUN_000029ac@0x000029ac, FUN_00000e10@0x00000e10
CALLEES (0): 

byte FUN_000012ac(int param_1,byte param_2,undefined4 *param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)(param_1 + 4);
  while( true ) {
    do {
      pbVar2 = pbVar3;
      if (0x4d3 < param_1 - (int)pbVar2) {
        return 0;
      }
      bVar1 = *pbVar2;
      pbVar3 = pbVar2 + 1;
    } while (bVar1 == 0);
    if (bVar1 == 0xff) break;
    if (bVar1 == param_2) {
      bVar1 = *pbVar3;
      *param_3 = pbVar2 + 2;
      return bVar1;
    }
    pbVar3 = pbVar2 + *pbVar3 + 2;
  }
  return 0;
}


================================================================