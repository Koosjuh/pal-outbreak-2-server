FUNCTION FUN_005ae9b0 @ 0x005ae9b0  size=304
CALLERS (1): FUN_005ae770@0x005ae770
CALLEES (7): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005ae9b0(int param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  
  cVar1 = *(char *)(param_1 + 0x5198);
  if (cVar1 == '\x02') {
    *(short *)(param_1 + 0x519a) = *(short *)(param_1 + 0x519a) + -1;
    if (*(short *)(param_1 + 0x519a) < 0) {
      *(char *)(param_1 + 0x5197) = *(char *)(param_1 + 0x5197) + '\x01';
      *(undefined1 *)(param_1 + 0x5198) = 0;
    }
  }
  else if (cVar1 == '\x01') {
    lVar3 = FUN_005b14b0(0x10);
    if (lVar3 != 0) {
      *(char *)(param_1 + 0x5198) = *(char *)(param_1 + 0x5198) + '\x01';
      func_0x001b0140(1);
      *(undefined2 *)(param_1 + 0x519a) = 6;
      FUN_005b9110(0x4c);
    }
    FUN_005af2c0(4);
    FUN_005af2e0(0x14);
    uVar4 = FUN_0062fea0(0xd);
    iVar2 = func_0x001ae3e0(uVar4);
    uVar4 = FUN_0062fea0(0xd);
    iVar5 = (int)((ulong)((long)(iVar2 * 5) << 0x21) >> 0x20);
    if (iVar2 * 10 < 0) {
      iVar5 = iVar2 * 10 + 1;
    }
    FUN_005af1e0(0x140 - (iVar5 >> 1),0x160,2,uVar4);
  }
  else if (cVar1 == '\0') {
    FUN_005b9060(0x14,param_1 + 0x5ec);
    *(char *)(param_1 + 0x5198) = *(char *)(param_1 + 0x5198) + '\x01';
  }
  return;
}



================================================================