FUNCTION FUN_00637430 @ 0x00637430  size=268
CALLERS (2): FUN_00636f90@0x00636f90, FUN_006379e0@0x006379e0
CALLEES (3): FUN_00635ba0@0x00635ba0, FUN_00637570@0x00637570, FUN_00637260@0x00637260
----------------------------------------------------------------

undefined8 FUN_00637430(byte param_1,undefined8 param_2,long param_3)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  
  if (param_1 < 6) {
    uVar3 = FUN_00637260();
    return uVar3;
  }
  if (param_3 == 0) {
    uVar1 = *(undefined1 *)(iRam00715da8 + 0x1e);
  }
  else {
    uVar1 = *(undefined1 *)param_3;
  }
  if (param_1 == 9) {
    cVar2 = FUN_00637570(uVar1);
    if ((-1 < cVar2) && ((*(byte *)(iRam00715da8 + 0x1e) & 8) != 0)) {
      return 0;
    }
  }
  else if (param_1 == 8) {
    cVar2 = FUN_00637570(uVar1);
    if ((-1 < cVar2) && ((*(byte *)(iRam00715da8 + 0x1e) & 8) == 0)) {
      return 0;
    }
  }
  else {
    if ((param_1 != 7) && (param_1 != 6)) {
      return 1;
    }
    cVar2 = FUN_00635ba0();
    if (-1 < cVar2) {
      return 0;
    }
  }
  return 1;
}



================================================================