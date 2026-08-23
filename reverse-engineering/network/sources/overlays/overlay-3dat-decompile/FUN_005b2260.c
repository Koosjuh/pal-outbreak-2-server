FUNCTION FUN_005b2260 @ 0x005b2260  size=416
CALLERS (1): FUN_005b1a30@0x005b1a30
CALLEES (6): FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005f6970@0x005f6970, FUN_005b1d10@0x005b1d10, FUN_005b8da0@0x005b8da0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_005b2260(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 0x430);
  if (cVar1 == '\x04') {
    sVar3 = *(short *)(iVar4 + 0x436) + -1;
    *(short *)(iVar4 + 0x436) = sVar3;
    if (sVar3 < 0) {
      if (*(char *)(iVar4 + 0x435) == '\0') {
        FUN_005f6970(1);
      }
      FUN_005b1d10(param_1);
    }
  }
  else if (cVar1 == '\x03') {
    sVar3 = *(short *)(iVar4 + 0x436) + -1;
    *(short *)(iVar4 + 0x436) = sVar3;
    if (sVar3 < 0) {
      *(char *)(iVar4 + 0x430) = *(char *)(iVar4 + 0x430) + '\x01';
      *(undefined2 *)(iVar4 + 0x436) = 4;
      FUN_005b9110(0x21);
    }
  }
  else if (cVar1 == '\x02') {
    lVar2 = FUN_005b14b0(0x10);
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x200);
      if (lVar2 == 0) {
        FUN_005b09b0(iVar4 + 0x435,1,3);
      }
      else {
        func_0x001b0140(2);
        FUN_005b9110(0x21);
        FUN_005b1d10(param_1);
      }
    }
    else {
      func_0x001b0140(1);
      *(char *)(iVar4 + 0x430) = *(char *)(iVar4 + 0x430) + '\x01';
      *(undefined1 *)(iVar4 + 0x43f) = 1;
      *(undefined2 *)(iVar4 + 0x436) = 4;
    }
  }
  else if (cVar1 == '\x01') {
    sVar3 = *(short *)(iVar4 + 0x436) + -1;
    *(short *)(iVar4 + 0x436) = sVar3;
    if (sVar3 < 0) {
      *(char *)(iVar4 + 0x430) = *(char *)(iVar4 + 0x430) + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar4 + 0x430) = 1;
    *(undefined2 *)(iVar4 + 0x436) = 4;
    *(undefined1 *)(iVar4 + 0x435) = 1;
    FUN_005b8da0(0x21,iVar4 + 0x435);
  }
  return;
}



================================================================