FUNCTION FUN_0062e5b0 @ 0x0062e5b0  size=364
CALLERS (1): FUN_0062e3c0@0x0062e3c0
CALLEES (4): FUN_0062f890@0x0062f890, FUN_005c4580@0x005c4580, FUN_005b14b0@0x005b14b0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_0062e5b0(int param_1,long param_2)

{
  char cVar1;
  long lVar2;
  short sVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\x03') {
    sVar3 = *(short *)(param_1 + 0x16) + -1;
    *(short *)(param_1 + 0x16) = sVar3;
    if (sVar3 < 0) {
      *(undefined1 *)(param_1 + 0x10) = 0;
    }
  }
  else if (cVar1 == '\x02') {
    FUN_005c4580();
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    *(undefined2 *)(param_1 + 0x16) = 0;
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 0x10) = 1;
      FUN_0062f890();
      *(undefined1 *)(param_1 + 0x445) = 0;
      *(undefined1 *)(param_1 + 0x444) = 0;
    }
    if (param_2 == 0) {
      if (*(ushort *)(param_1 + 0x456) < 4) {
        FUN_005b09b0(param_1 + 0x444,1,2);
      }
      else {
        *(undefined1 *)(param_1 + 0x444) = 1;
      }
      lVar2 = FUN_005b14b0(0x10);
      if (lVar2 == 0) {
        lVar2 = FUN_005b14b0(0x200);
        if (lVar2 != 0) {
          if (*(ushort *)(param_1 + 0x456) < 4) {
            if (*(char *)(param_1 + 0x444) == '\0') {
              func_0x001b0140(2);
            }
            *(undefined1 *)(param_1 + 0x444) = 1;
          }
          else {
            func_0x001b0140(5);
          }
        }
      }
      else if (*(char *)(param_1 + 0x444) != '\0') {
        *(undefined1 *)(param_1 + 0xf) = 2;
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x445) = 1;
        *(undefined1 *)(param_1 + 0x45a) = 0;
        func_0x001b0140();
      }
    }
  }
  return;
}



================================================================