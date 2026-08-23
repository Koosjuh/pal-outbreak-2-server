FUNCTION FUN_005fe140 @ 0x005fe140  size=148
CALLERS (0): 
CALLEES (3): FUN_005af810@0x005af810, FUN_005bac80@0x005bac80, FUN_005bace0@0x005bace0
----------------------------------------------------------------

void FUN_005fe140(int param_1)

{
  char cVar1;
  short sVar2;
  long lVar3;
  
  *(undefined4 *)(param_1 + 0x30) = 0;
  lVar3 = FUN_005af810();
  if (lVar3 == 0) {
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    lVar3 = FUN_005bac80(uRam006c4b96);
    if (lVar3 == 0) {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      sVar2 = func_0x001ae3e0(lVar3);
      *(short *)(param_1 + 0x26) = sVar2 * 9 + 0x150;
      *(undefined2 *)(param_1 + 0x28) = 0x136;
      *(undefined1 *)(param_1 + 1) = 1;
      cVar1 = FUN_005bace0(uRam006c4b96);
      *(short *)(param_1 + 0x22) = cVar1 + 99;
    }
  }
  return;
}



================================================================