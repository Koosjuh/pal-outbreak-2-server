FUNCTION FUN_005fec30 @ 0x005fec30  size=216
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (6): FUN_005c0f60@0x005c0f60, FUN_005f4b80@0x005f4b80, FUN_005b14b0@0x005b14b0, FUN_005f4be0@0x005f4be0, FUN_005f54d0@0x005f54d0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_005fec30(int param_1)

{
  long lVar1;
  
  if (*(char *)(param_1 + 0x97f) != '\0') {
    *(undefined1 *)(param_1 + 0x97f) = 0;
    FUN_005c0f60(uRam006c4600,0x600ff0);
  }
  FUN_005f4b80();
  lVar1 = FUN_005f4be0();
  if (lVar1 == 0) {
    *(undefined1 *)(param_1 + 0x992) = 1;
    lVar1 = FUN_005b14b0(0x10);
    if (lVar1 == 0) {
      lVar1 = FUN_005b14b0(0x200);
      if (lVar1 == 0) {
        FUN_005b09b0(param_1 + 0x907,1,3);
      }
      else {
        func_0x001b0140(2);
        *(undefined1 *)(param_1 + 0x907) = 1;
        *(undefined1 *)(param_1 + 0x992) = 0;
      }
    }
    else {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      *(undefined1 *)(param_1 + 0x10) = 0;
      func_0x001b0140(1);
      *(undefined2 *)(param_1 + 0x16) = 8;
      *(undefined1 *)(param_1 + 0x992) = 0;
    }
  }
  FUN_005f54d0(2);
  return;
}



================================================================