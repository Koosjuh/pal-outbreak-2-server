FUNCTION FUN_005c3b10 @ 0x005c3b10  size=304
CALLERS (1): FUN_005c4600@0x005c4600
CALLEES (6): FUN_005c2ae0@0x005c2ae0, FUN_005c3c40@0x005c3c40, FUN_005c2ad0@0x005c2ad0, FUN_005bf1e0@0x005bf1e0, FUN_005c2e90@0x005c2e90, FUN_005c4f00@0x005c4f00
----------------------------------------------------------------

void FUN_005c3b10(undefined8 param_1)

{
  short sVar1;
  undefined2 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_20 [32];
  
  sVar1 = FUN_005bf1e0(0);
  uVar2 = FUN_005c4f00();
  pcVar3 = (char *)FUN_005c2ae0(sVar1 + -1,uVar2);
  func_0x00106b60(auStack_20,0,0x20);
  uVar5 = (uint)bRam006d2296;
  iVar7 = 0x6cc044;
  if ((*pcVar3 >> 7 & 1U) != 0) {
    iVar7 = 0x6cc045;
    uVar5 = bRam006d2296 - 1 & 0xff;
  }
  if ((pcVar3[1] >> 7 & 1U) != 0) {
    iVar7 = iVar7 + 1;
    uVar5 = uVar5 - 1 & 0xff;
  }
  if ((char)uVar5 < '\0') {
    uVar5 = 0;
  }
  iVar6 = 0;
  while( true ) {
    if ((int)uVar5 <= iVar6) break;
    auStack_20[iVar6] = *(undefined1 *)(iVar7 + iVar6);
    iVar6 = iVar6 + 1;
  }
  uVar4 = FUN_005c2e90(1);
  uVar5 = FUN_005c3c40(param_1,auStack_20,pcVar3[2],pcVar3 + 3,uVar4);
  uVar5 = uVar5 & 0xff;
  uVar4 = FUN_005c2ad0();
  FUN_005c3c40(param_1,auStack_20 + (uVar5 & 0xff),pcVar3[0x2b],pcVar3 + 0x2c,uVar4);
  return;
}



================================================================