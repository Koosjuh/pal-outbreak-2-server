FUNCTION FUN_0062d730 @ 0x0062d730  size=212
CALLERS (1): FUN_0062d640@0x0062d640
CALLEES (4): FUN_005f7610@0x005f7610, FUN_0062f500@0x0062f500, FUN_005b14b0@0x005b14b0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_0062d730(int param_1)

{
  long lVar1;
  
  if (*(char *)(param_1 + 0xf) != '\x01') {
    if (*(char *)(param_1 + 0xf) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 0xf) = 1;
    *(undefined1 *)(param_1 + 0x10) = 1;
    FUN_0062f500(param_1 + 0x10);
  }
  lVar1 = FUN_005b14b0(0x200);
  if (lVar1 == 0) {
    lVar1 = FUN_005b14b0(0x10);
    if (lVar1 == 0) {
      FUN_005b09b0(param_1 + 4,(int)*(short *)(param_1 + 10) - 1U & 0xff,1);
    }
    else {
      *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
      *(undefined1 *)(param_1 + 0xf) = 0;
      *(undefined1 *)(param_1 + 0x10) = 0;
      *(ushort *)(param_1 + 0xc) = (ushort)*(byte *)(*(short *)(param_1 + 4) * 4 + param_1 + 0x1c);
      func_0x001b0140(1);
    }
  }
  else {
    FUN_005f7610();
  }
  return;
}



================================================================