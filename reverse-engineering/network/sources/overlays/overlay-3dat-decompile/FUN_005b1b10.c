FUNCTION FUN_005b1b10 @ 0x005b1b10  size=512
CALLERS (0): 
CALLEES (5): FUN_005b1e80@0x005b1e80, FUN_00618c20@0x00618c20, FUN_005b14b0@0x005b14b0, FUN_005b1e30@0x005b1e30, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_005b1b10(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (*(char *)(iVar2 + 0x42c) == '\0') {
    FUN_00618c20();
  }
  else {
    cVar1 = *(char *)(param_1 + 4);
    if (cVar1 == '\v') {
      *(undefined1 *)(param_1 + 4) = 4;
    }
    else if (cVar1 == '\n') {
      *(undefined2 *)(param_1 + 0x28) =
           *(undefined2 *)(&DAT_00638c30 + *(char *)(iVar2 + 0x42f) * 2);
      if (*(char *)(iVar2 + 0x438) != '\0') {
        *(undefined1 *)(param_1 + 4) = 0xb;
      }
    }
    else if (cVar1 == '\x04') {
      FUN_00618c20();
    }
    else if (cVar1 == '\x03') {
      FUN_005b1e80(*(undefined1 *)(iVar2 + 0x42f));
      *(undefined1 *)(iVar2 + 0x438) = 1;
      iVar4 = FUN_005b1e30();
      *(undefined1 *)(iVar2 + 0x42d) = *(undefined1 *)(*(char *)(iVar2 + 0x42f) + iVar4 + 1);
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
    }
    else if (cVar1 == '\x02') {
      FUN_005b1e80(*(undefined1 *)(iVar2 + 0x42f));
      pcVar3 = (char *)FUN_005b1e30();
      lVar5 = FUN_005b09b0(iVar2 + 0x42f,*pcVar3 + -1,2);
      if (lVar5 == 0) {
        lVar5 = FUN_005b14b0(0x10);
        if (lVar5 == 0) {
          lVar5 = FUN_005b14b0(0x200);
          if ((lVar5 != 0) || (lVar5 = FUN_005b14b0(0x8000), lVar5 != 0)) {
            *(undefined1 *)(iVar2 + 0x438) = 1;
            *(undefined1 *)(param_1 + 4) = 4;
            *(undefined1 *)(iVar2 + 0x42d) = 7;
            func_0x001b0140(2);
          }
        }
        else {
          *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
          func_0x001b0140(1);
        }
      }
    }
    else if (cVar1 == '\x01') {
      *(undefined1 *)(param_1 + 4) = 2;
      if (*(char *)(param_1 + 2) == '\0') {
        *(undefined1 *)(param_1 + 1) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 4) = 10;
        *(undefined1 *)(param_1 + 1) = 1;
        *(undefined2 *)(param_1 + 0x26) = 0x60;
        *(undefined2 *)(param_1 + 0x28) =
             *(undefined2 *)(&DAT_00638c30 + *(char *)(iVar2 + 0x42f) * 2);
      }
    }
    else if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 4) = 1;
    }
  }
  return;
}



================================================================