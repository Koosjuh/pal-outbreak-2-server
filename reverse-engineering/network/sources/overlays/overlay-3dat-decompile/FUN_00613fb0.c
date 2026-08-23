FUNCTION FUN_00613fb0 @ 0x00613fb0  size=288
CALLERS (1): FUN_00613c30@0x00613c30
CALLEES (5): FUN_006146e0@0x006146e0, FUN_0060f830@0x0060f830, FUN_00618520@0x00618520, FUN_0060f860@0x0060f860, FUN_006147a0@0x006147a0
----------------------------------------------------------------

void FUN_00613fb0(char param_1)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  char cVar5;
  undefined1 auStack_100 [256];
  
  psVar3 = (short *)FUN_0060f830(0x653ff0,*(undefined1 *)(iRam0070d1c0 + 0x4e));
  cVar1 = FUN_0060f860(0x654010,*(undefined1 *)(iRam0070d1c0 + 0x4e));
  for (cVar5 = '\0'; cVar5 < cVar1; cVar5 = cVar5 + '\x01') {
    sVar2 = *psVar3;
    if (sVar2 == -1) {
      sVar2 = FUN_006147a0(*(undefined4 *)(psVar3 + 2),0x16);
    }
    if (cVar5 == param_1) {
      iVar4 = FUN_00618520(iRam0070d1c0 + 0x10d8);
      func_0x00109728(auStack_100,*(undefined4 *)(psVar3 + 2),iVar4 + 1);
      FUN_006146e0(sVar2,psVar3[1],auStack_100);
    }
    else {
      FUN_006146e0(sVar2,psVar3[1],*(undefined4 *)(psVar3 + 2));
    }
    psVar3 = psVar3 + 4;
  }
  return;
}



================================================================