FUNCTION FUN_00614600 @ 0x00614600  size=212
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (4): FUN_006146e0@0x006146e0, FUN_0060f830@0x0060f830, FUN_0060f860@0x0060f860, FUN_006147a0@0x006147a0
----------------------------------------------------------------

void FUN_00614600(void)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  char cVar4;
  
  psVar3 = (short *)FUN_0060f830(0x654030,(int)*(char *)(iRam0070d1c0 + 0x4f) +
                                          (int)*(char *)(iRam0070d1c0 + 0x50));
  cVar1 = FUN_0060f860(0x654050,(int)*(char *)(iRam0070d1c0 + 0x4f) +
                                (int)*(char *)(iRam0070d1c0 + 0x50));
  for (cVar4 = '\0'; cVar4 < cVar1; cVar4 = cVar4 + '\x01') {
    sVar2 = *psVar3;
    if (sVar2 == -1) {
      sVar2 = FUN_006147a0(*(undefined4 *)(psVar3 + 2),0x16);
    }
    FUN_006146e0(sVar2,psVar3[1],*(undefined4 *)(psVar3 + 2));
    psVar3 = psVar3 + 4;
  }
  return;
}



================================================================