FUNCTION FUN_000036b0 @ 0x000036b0 size=300
CALLERS (1): FUN_00004550@0x00004550
CALLEES (3): FUN_00010b3c@0x00010b3c, FUN_00010b74@0x00010b74, FUN_00010c38@0x00010c38

undefined4 FUN_000036b0(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = DAT_000132d4;
  uVar5 = param_2 + 0xe;
  sVar1 = *(short *)(DAT_000131ec + 2);
  if (uVar5 < 0x3c) {
    uVar5 = 0x3c;
  }
  if (*(int *)(DAT_000132d4 + 0x40) == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar4 = FUN_00010b74(0,uVar5,0);
    if (iVar4 == 0) {
      uVar3 = 0xffffffff;
      if (DAT_00012efc != 0) {
        FUN_00010c38("ave-ppp %s:","ppDdlProcessRecvInt");
        FUN_00010c38("Can\'t allocate packet buf.\n",0);
        uVar3 = 0xffffffff;
      }
    }
    else {
      FUN_00010b3c(iVar4,DAT_000132d4 + 0x44,0xe);
      FUN_00010b3c(iVar4 + 0xe,param_1,param_2);
      (**(code **)(iVar2 + 0xc))((int)sVar1,*(undefined2 *)(iVar2 + 4),iVar4,uVar5);
      uVar3 = 0;
    }
  }
  return uVar3;
}


================================================================