FUNCTION FUN_005b47a0 @ 0x005b47a0  size=180
CALLERS (2): FUN_005b3ed0@0x005b3ed0, FUN_005b41b0@0x005b41b0
CALLEES (3): FUN_005b9110@0x005b9110, FUN_005ba570@0x005ba570, FUN_005b4c80@0x005b4c80
----------------------------------------------------------------

undefined4 FUN_005b47a0(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 3);
  if (cVar1 == '\x02') {
    iVar2 = *(int *)(param_1 + 0x18) + -1;
    *(int *)(param_1 + 0x18) = iVar2;
    if (iVar2 < 0) {
      return 1;
    }
  }
  else if (cVar1 == '\x01') {
    iVar2 = *(int *)(param_1 + 0x18) + -1;
    *(int *)(param_1 + 0x18) = iVar2;
    if (iVar2 < 0) {
      *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
      *(undefined4 *)(param_1 + 0x18) = 0x3c;
      FUN_005b9110(0x4c);
    }
  }
  else {
    if (cVar1 != '\0') {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x18) = 0x3c;
    *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
    FUN_005b4c80(6);
    FUN_005ba570(0x20);
  }
  return 0;
}



================================================================