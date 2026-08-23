FUNCTION FUN_00607dc0 @ 0x00607dc0  size=420
CALLERS (1): FUN_00607a10@0x00607a10
CALLEES (4): FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b8da0@0x005b8da0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

undefined4 FUN_00607dc0(int param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  cVar1 = param_2[1];
  if (cVar1 == '\x04') {
    iVar2 = *(int *)(param_2 + 0x18);
    *(int *)(param_2 + 0x18) = iVar2 + -1;
    if (iVar2 + -1 < 0) {
      if (param_2[0xb] == '\0') {
        *param_2 = 2;
        param_2[1] = 2;
        func_0x001b0140();
        *(undefined1 *)(param_1 + 0x454) = 0;
        *(undefined4 *)(param_2 + 0x18) = 8;
      }
      else {
        *param_2 = 2;
        param_2[1] = 0;
      }
    }
  }
  else if (cVar1 == '\x03') {
    iVar2 = *(int *)(param_2 + 0x18);
    *(int *)(param_2 + 0x18) = iVar2 + -1;
    if (iVar2 + -1 < 0) {
      param_2[1] = param_2[1] + '\x01';
      FUN_005b9110(0x4c);
    }
  }
  else if (cVar1 == '\x02') {
    lVar3 = FUN_005b14b0(0x10);
    if (lVar3 == 0) {
      lVar3 = FUN_005b14b0(0x200);
      if (lVar3 == 0) {
        FUN_005b09b0(param_2 + 0xb,1,3);
      }
      else {
        func_0x001b0140(2);
        *param_2 = 2;
        param_2[1] = 0;
        FUN_005b9110(0x4c);
      }
    }
    else {
      func_0x001b0140(1);
      param_2[1] = param_2[1] + '\x01';
      *(undefined1 *)(param_1 + 0x43f) = 1;
      *(undefined4 *)(param_2 + 0x18) = 0x10;
    }
  }
  else if (cVar1 == '\x01') {
    iVar2 = *(int *)(param_2 + 0x18);
    *(int *)(param_2 + 0x18) = iVar2 + -1;
    if (iVar2 + -1 < 0) {
      param_2[1] = param_2[1] + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    param_2[1] = 1;
    *(undefined4 *)(param_2 + 0x18) = 0x10;
    param_2[0xb] = 1;
    FUN_005b8da0(0x21,param_2 + 0xb);
  }
  return 0xffffffff;
}



================================================================