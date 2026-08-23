
void FUN_001ab460(int param_1,undefined8 param_2)

{
  short sVar1;
  long lVar2;
  int iVar3;
  
  if (cRam00343573 == '\0') {
    FUN_001ac0b0(0x245680);
  }
  lVar2 = FUN_001ab3d0(param_1,param_2);
  if (lVar2 == 0) {
    if (sRam002a4a0c == 100) {
      FUN_001ac0b0(0x2456a0);
    }
    if ((int)sRam002a4a08 - (int)sRam002a4a0a < param_1) {
      FUN_001ac0b0(0x2456a0);
    }
    sVar1 = sRam002a4a0c;
    iVar3 = (int)sRam002a4a0c;
    *(int *)(iVar3 * 4 + 0x2a4a1c) = iRam002a4a10 + (sRam002a4a0a * 0x12 + (int)sRam002a4a0a) * 8;
    *(short *)(iVar3 * 2 + 0x2a4bac) = (short)param_1;
    *(char *)(sVar1 + 0x2a4c74) = (char)param_2 + '\x01';
    sRam002a4a0a = sRam002a4a0a + (short)param_1;
    sRam002a4a0c = sRam002a4a0c + 1;
  }
  return;
}

