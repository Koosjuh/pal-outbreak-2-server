FUNCTION FUN_005b20c0 @ 0x005b20c0  size=408
CALLERS (1): FUN_005b1a30@0x005b1a30
CALLEES (9): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005af2c0@0x005af2c0, FUN_005b1d10@0x005b1d10, FUN_005af1e0@0x005af1e0, FUN_005b9060@0x005b9060, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_005b20c0(int param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  
  cVar1 = *(char *)(param_1 + 0x430);
  if (cVar1 == '\x03') {
    *(char *)(param_1 + 0x431) = *(char *)(param_1 + 0x431) + -1;
    if (*(char *)(param_1 + 0x431) < '\0') {
      FUN_005b1d10();
    }
  }
  else if (cVar1 == '\x02') {
    lVar3 = FUN_005b14b0(0x8200);
    if (lVar3 != 0) {
      *(char *)(param_1 + 0x430) = *(char *)(param_1 + 0x430) + '\x01';
      *(undefined1 *)(param_1 + 0x431) = 8;
      FUN_005b9110(0x4c);
      func_0x001b0140(2);
    }
    FUN_005af2e0(0x14);
    FUN_005af2c0(0x15);
    uVar4 = FUN_0062fea0(0x21);
    iVar2 = func_0x001ae3e0(uVar4);
    uVar4 = FUN_0062fea0(0x21);
    iVar5 = (int)((ulong)((long)(iVar2 * 5) << 0x21) >> 0x20);
    if (iVar2 * 10 < 0) {
      iVar5 = iVar2 * 10 + 1;
    }
    FUN_005af1e0(0x140 - (iVar5 >> 1),0x177,2,uVar4);
  }
  else if (cVar1 == '\x01') {
    *(char *)(param_1 + 0x431) = *(char *)(param_1 + 0x431) + -1;
    if (*(char *)(param_1 + 0x431) < '\0') {
      *(char *)(param_1 + 0x430) = *(char *)(param_1 + 0x430) + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x430) = 1;
    *(undefined1 *)(param_1 + 0x431) = 0x10;
    if (*(char *)(param_1 + 0x5194) == '\0') {
      if (*(char *)(param_1 + 0x4096) == '\0') {
        FUN_005b8cf0(0xffffffffffffff90,param_1 + 0x5194);
      }
      else {
        FUN_005b9060(0x8014,param_1 + 0x4096);
      }
    }
    else {
      FUN_005b9060(0x8014);
    }
  }
  return;
}



================================================================