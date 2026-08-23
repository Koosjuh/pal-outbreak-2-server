FUNCTION FUN_00613e70 @ 0x00613e70  size=208
CALLERS (1): FUN_00613c30@0x00613c30
CALLEES (4): FUN_006146e0@0x006146e0, FUN_0060f830@0x0060f830, FUN_0060f860@0x0060f860, FUN_006147a0@0x006147a0
----------------------------------------------------------------

void FUN_00613e70(void)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  char cVar4;
  
  psVar3 = (short *)FUN_0060f830(0x653ff0,*(undefined1 *)(iRam0070d1c0 + 0x4e));
  cVar1 = FUN_0060f860(0x654010,*(undefined1 *)(iRam0070d1c0 + 0x4e));
  for (cVar4 = '\0'; cVar4 < (char)(cVar1 + -3); cVar4 = cVar4 + '\x01') {
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