FUNCTION FUN_005ae630 @ 0x005ae630  size=276
CALLERS (1): FUN_005ae3e0@0x005ae3e0
CALLEES (7): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005c4460@0x005c4460, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005ae630(int param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x54b5) == '\x01') {
    *(short *)(param_1 + 0x54ba) = *(short *)(param_1 + 0x54ba) + -1;
    if (*(short *)(param_1 + 0x54ba) < 0) {
      *(undefined1 *)(param_1 + 0x54bc) = 1;
      FUN_005c4460();
      *(char *)(param_1 + 0x54b4) = *(char *)(param_1 + 0x54b4) + '\x01';
      *(undefined1 *)(param_1 + 0x54b5) = 0;
    }
  }
  else if (*(char *)(param_1 + 0x54b5) == '\0') {
    lVar2 = FUN_005b14b0(0x10);
    if (lVar2 != 0) {
      *(char *)(param_1 + 0x54b5) = *(char *)(param_1 + 0x54b5) + '\x01';
      func_0x001b0140(1);
      *(undefined2 *)(param_1 + 0x54ba) = 6;
      FUN_005b9110(0x4c);
    }
    FUN_005af2c0(4);
    FUN_005af2e0(0x14);
    uVar3 = FUN_0062fea0(0xd);
    iVar1 = func_0x001ae3e0(uVar3);
    uVar3 = FUN_0062fea0(0xd);
    iVar4 = (int)((ulong)((long)(iVar1 * 5) << 0x21) >> 0x20);
    if (iVar1 * 10 < 0) {
      iVar4 = iVar1 * 10 + 1;
    }
    FUN_005af1e0(0x140 - (iVar4 >> 1),0x160,2,uVar3);
  }
  return;
}



================================================================