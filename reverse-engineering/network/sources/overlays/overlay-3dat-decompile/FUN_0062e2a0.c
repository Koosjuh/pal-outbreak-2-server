FUNCTION FUN_0062e2a0 @ 0x0062e2a0  size=276
CALLERS (1): FUN_0062d950@0x0062d950
CALLEES (5): FUN_00637180@0x00637180, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_00617a00@0x00617a00, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_0062e2a0(int param_1)

{
  char cVar1;
  long lVar2;
  short sVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\x04') {
    FUN_005b9110(0x4c);
    FUN_00617a00(0x6c4b90);
  }
  else if (cVar1 == '\x03') {
    sVar3 = *(short *)(param_1 + 0x16) + -1;
    *(short *)(param_1 + 0x16) = sVar3;
    if ((sVar3 < 0) || (lVar2 = FUN_005b14b0(0x210), lVar2 != 0)) {
      *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    }
  }
  else if (cVar1 == '\x02') {
    sVar3 = *(short *)(param_1 + 0x16) + -1;
    *(short *)(param_1 + 0x16) = sVar3;
    if (sVar3 < 0) {
      *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
      *(undefined2 *)(param_1 + 0x16) = 0x708;
    }
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)(param_1 + 0x10) = 2;
    *(undefined2 *)(param_1 + 0x16) = 8;
  }
  else if (cVar1 == '\0') {
    FUN_00637180();
    FUN_005b8cf0(0xffffffffffffffae);
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
  }
  return;
}



================================================================