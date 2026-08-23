FUNCTION FUN_0062cfd0 @ 0x0062cfd0  size=288
CALLERS (1): FUN_0062cf50@0x0062cf50
CALLEES (5): FUN_00604810@0x00604810, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b8da0@0x005b8da0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

undefined4 FUN_0062cfd0(undefined8 param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  long lVar2;
  
  if (param_2[1] == '\x01') {
    lVar2 = FUN_005b14b0(0x10);
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x200);
      if (lVar2 != 0) {
        func_0x001b0140(2);
        return 1;
      }
      if (*(short *)(param_2 + 8) == 0) {
        *(undefined2 *)(param_2 + 0x10) = 1;
      }
      else {
        FUN_005b09b0(param_2 + 0x10,1,2);
      }
    }
    else if (*(short *)(param_2 + 0x10) == 0) {
      if (*(short *)(param_2 + 8) != 0) {
        *param_2 = 1;
        param_2[1] = 0;
        func_0x001b0140();
      }
    }
    else {
      *param_2 = 2;
      param_2[1] = 0;
      func_0x001b0140(1);
      *(undefined2 *)(param_2 + 4) = 6;
      FUN_005b9110(0x4c);
    }
  }
  else {
    if (param_2[1] != '\0') {
      return 0;
    }
    uVar1 = FUN_00604810(0x694700,0x32);
    *(undefined2 *)(param_2 + 8) = uVar1;
    *(undefined2 *)(param_2 + 0x10) = 0;
    param_2[1] = param_2[1] + '\x01';
    FUN_005b8da0(0xffffffffffffffaf,param_2 + 0x10);
  }
  return 0;
}



================================================================