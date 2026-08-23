FUNCTION FUN_005b1fa0 @ 0x005b1fa0  size=280
CALLERS (1): FUN_005b1a30@0x005b1a30
CALLEES (4): FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b1d10@0x005b1d10, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_005b1fa0(int param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(param_1 + 0x430);
  if (cVar1 == '\x03') {
    *(char *)(param_1 + 0x431) = *(char *)(param_1 + 0x431) + -1;
    if (*(char *)(param_1 + 0x431) < '\0') {
      FUN_005b1d10();
    }
  }
  else if (cVar1 == '\x02') {
    lVar2 = FUN_005b14b0(0x8200);
    if (lVar2 != 0) {
      *(char *)(param_1 + 0x430) = *(char *)(param_1 + 0x430) + '\x01';
      *(undefined1 *)(param_1 + 0x431) = 8;
      FUN_005b9110(0x4c);
      func_0x001b0140(2);
    }
  }
  else if (cVar1 == '\x01') {
    *(char *)(param_1 + 0x431) = *(char *)(param_1 + 0x431) + -1;
    if (*(char *)(param_1 + 0x431) < '\0') {
      *(char *)(param_1 + 0x430) = *(char *)(param_1 + 0x430) + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x430) = 1;
    *(undefined1 *)(param_1 + 0x431) = 8;
    if (*(char *)(param_1 + 0x42d) == '\x05') {
      FUN_005b8cf0(0x1f);
    }
    else {
      FUN_005b8cf0(0xffffffffffffff8a);
    }
  }
  return;
}



================================================================