FUNCTION FUN_005da370 @ 0x005da370  size=176
CALLERS (1): FUN_005e7e30@0x005e7e30
CALLEES (1): FUN_005da780@0x005da780
----------------------------------------------------------------

void FUN_005da370(undefined2 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  *(undefined2 *)(iRam00701070 + 0x18) = param_1;
  if (*(char *)(iRam00701070 + 0x39) != '\0') {
    if ((int)(*(ushort *)(iRam00701070 + 0x18) & 8) >> 3 == 0) {
      *(ushort *)(iRam00701070 + 0x18) = *(ushort *)(iRam00701070 + 0x18) + 8;
    }
  }
  func_0x00109eb8(iRam00701070 + 0x33b);
  *(char *)(iRam00701070 + 0x5c3) = (char)param_3;
  *(undefined1 *)(iRam00701070 + 0x38) = 0x1e;
  *(undefined1 *)(iRam00701070 + 0x37) = 1;
  FUN_005da780(param_3,param_4);
  return;
}



================================================================