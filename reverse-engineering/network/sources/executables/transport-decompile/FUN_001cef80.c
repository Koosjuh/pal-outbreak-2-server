
void FUN_001cef80(void)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  
  FUN_001cbc20(0x1400);
  FUN_001cf360();
  iVar3 = 0;
  psVar4 = (short *)((uint)uRam0034357c * 0x10 + 0x4f83e0);
  do {
    sVar2 = *psVar4;
    psVar1 = psVar4 + 1;
    psVar4 = psVar4 + 2;
    if (((sVar2 != -1) || (*psVar1 != 0)) && (sVar2 != -1)) {
      FUN_001ce070(0,sVar2,sVar2,3,0,0xffffffffffffffff);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}

