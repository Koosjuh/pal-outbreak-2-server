FUNCTION FUN_0000e6e0 @ 0x0000e6e0 size=80
CALLERS (1): FUN_0000e90c@0x0000e90c
CALLEES (1): FUN_00001c50@0x00001c50

undefined1 * FUN_0000e6e0(undefined1 *param_1,short param_2)

{
  if ((ushort)(param_2 - 1U) < 0xff) {
    *param_1 = (char)param_2;
    param_1 = param_1 + 1;
  }
  else {
    *param_1 = 0;
    param_1 = (undefined1 *)FUN_00001c50(param_1 + 1,param_2);
  }
  return param_1;
}


================================================================