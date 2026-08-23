FUNCTION FUN_005f5970 @ 0x005f5970  size=196
CALLERS (0): 
CALLEES (1): FUN_005af810@0x005af810
----------------------------------------------------------------

void FUN_005f5970(int param_1)

{
  long lVar1;
  short sVar2;
  
  if (*(char *)(*(char *)(param_1 + 3) + 0x6c54d0) == '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    lVar1 = FUN_005af810();
    if (lVar1 == 0) {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 1;
      sVar2 = 0x60;
      if (*(char *)(param_1 + 2) == '\0') {
        sVar2 = 0x54;
      }
      *(short *)(param_1 + 0x28) = sVar2 + *(char *)(param_1 + 3) * 0x14;
      *(short *)(param_1 + 0x26) = *(short *)(*(char *)(param_1 + 3) * 2 + 0x6c54e0) + 4;
      *(short *)(param_1 + 0x22) = *(char *)(*(char *)(param_1 + 3) + 0x6c54d0) + 99;
    }
  }
  return;
}



================================================================