FUNCTION FUN_00006260 @ 0x00006260 size=184
CALLERS (1): FUN_00005070@0x00005070
CALLEES (0): 

undefined4 FUN_00006260(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = DAT_00014a6c;
    param_1[1] = DAT_00014a70;
    *(undefined2 *)(param_1 + 2) = DAT_00014a78;
    *(undefined2 *)((int)param_1 + 10) = DAT_00014a7c;
    *(undefined2 *)(param_1 + 3) = DAT_00014a7e;
    param_1[4] = DAT_00014a80;
    param_1[5] = DAT_00014a84;
    *(undefined2 *)(param_1 + 6) = DAT_00014a8c;
    *(undefined2 *)((int)param_1 + 0x1a) = DAT_00014a90;
    *(undefined2 *)(param_1 + 7) = DAT_00014a92;
    *(undefined2 *)((int)param_1 + 0x1e) = DAT_00014a94;
    *(undefined2 *)(param_1 + 8) = DAT_00014a96;
    *(undefined2 *)((int)param_1 + 0x22) = DAT_00014a98;
    return 0;
  }
  return 0xffffffff;
}


================================================================