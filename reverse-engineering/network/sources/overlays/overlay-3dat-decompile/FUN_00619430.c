FUNCTION FUN_00619430 @ 0x00619430  size=384
CALLERS (1): FUN_00619330@0x00619330
CALLEES (2): FUN_00604860@0x00604860, FUN_005af400@0x005af400
----------------------------------------------------------------

undefined8 FUN_00619430(undefined8 param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  char acStack_40 [32];
  undefined1 auStack_20 [30];
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  FUN_005af400();
  param_2[5] = '\0';
  lVar4 = 0;
  lVar3 = 0;
  do {
    lVar3 = func_0x007df500(lVar3 >> 0x38,&uStack_1,&uStack_2,auStack_20,acStack_40);
    if ((acStack_40[0] != '\0') && (lVar2 = func_0x00109d70(0x874fc0,acStack_40), lVar2 != 0)) {
      lVar2 = FUN_00604860(0x694700,0x32,acStack_40);
      if (lVar2 == -1) {
        if (lVar3 != 0) {
          func_0x0010a4f0(param_2[5] * 0x38 + 0x7148f0,auStack_20,0x10);
          func_0x0010a4f0(param_2[5] * 0x38 + 0x714900,acStack_40,0x10);
          *(undefined4 *)(param_2[5] * 0x38 + 0x714910) = 0;
          param_2[5] = param_2[5] + '\x01';
        }
      }
      else {
        iVar1 = (int)lVar2 * 0x38;
        func_0x0010a4f0(iVar1 + 0x694710,acStack_40,0x10);
        if (*(int *)(iVar1 + 0x694720) != -1) {
          *(int *)(iVar1 + 0x694720) = *(int *)(iVar1 + 0x694720) + 1;
        }
      }
    }
    lVar4 = (long)((int)lVar4 + 1);
    lVar3 = lVar4 << 0x38;
  } while (lVar4 < 4);
  *param_2 = *param_2 + '\x01';
  return 0;
}



================================================================