FUNCTION FUN_005fcba0 @ 0x005fcba0  size=200
CALLERS (0): 
CALLEES (3): FUN_005af810@0x005af810, FUN_005bac80@0x005bac80, FUN_005bace0@0x005bace0
----------------------------------------------------------------

void FUN_005fcba0(int param_1)

{
  char cVar1;
  short sVar2;
  long lVar3;
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 1) = 1;
  }
  lVar3 = FUN_005af810();
  if (lVar3 == 0) {
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 1) = 1;
  }
  lVar3 = FUN_005bac80(uRam006c4b96);
  if (lVar3 == 0) {
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    sVar2 = func_0x001ae3e0(lVar3);
    *(short *)(param_1 + 0x26) = sVar2 * 10 + 0x84;
    *(undefined2 *)(param_1 + 0x28) = 0x6c;
    cVar1 = FUN_005bace0(uRam006c4b96);
    *(short *)(param_1 + 0x22) = cVar1 + 99;
  }
  return;
}



================================================================