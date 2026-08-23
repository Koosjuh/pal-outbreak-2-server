FUNCTION FUN_00612fd0 @ 0x00612fd0  size=196
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (4): FUN_006146e0@0x006146e0, FUN_0060f830@0x0060f830, FUN_0060f860@0x0060f860, FUN_006147a0@0x006147a0
----------------------------------------------------------------

void FUN_00612fd0(void)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  char cVar4;
  
  psVar3 = (short *)FUN_0060f830(0x653fb0,*(undefined1 *)(iRam0070d1c0 + 0x4d));
  cVar1 = FUN_0060f860(0x653fd0,*(undefined1 *)(iRam0070d1c0 + 0x4d));
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