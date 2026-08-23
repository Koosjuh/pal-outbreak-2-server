FUNCTION FUN_00627d60 @ 0x00627d60  size=316
CALLERS (2): FUN_005f76f0@0x005f76f0, FUN_005f8d40@0x005f8d40
CALLEES (7): FUN_00627ea0@0x00627ea0, FUN_00628710@0x00628710, FUN_00628750@0x00628750, FUN_00628690@0x00628690, FUN_00627f20@0x00627f20, FUN_00628110@0x00628110, FUN_00628210@0x00628210
----------------------------------------------------------------

void FUN_00627d60(undefined8 param_1)

{
  int iVar1;
  long unaff_s0;
  
  iVar1 = (int)param_1;
  if (*(char *)(iVar1 + 0xe) != '\x01') {
    if (*(char *)(iVar1 + 0xe) != '\0') {
      return;
    }
    *(undefined1 *)(iVar1 + 0xe) = 1;
    func_0x00106b60(0x695ce0,0,0x18);
  }
  switch(uRam00695ce0) {
  case 0:
    unaff_s0 = FUN_00627ea0(param_1);
    break;
  case 1:
    unaff_s0 = FUN_00627f20(param_1);
    break;
  case 2:
    unaff_s0 = FUN_00628110(param_1);
    break;
  case 3:
    unaff_s0 = FUN_00628210(param_1);
    break;
  case 4:
    unaff_s0 = FUN_00628690(param_1);
    break;
  case 5:
    unaff_s0 = FUN_00628710(param_1);
    break;
  case 6:
    unaff_s0 = FUN_00628750(param_1,0x695ce0);
  }
  if (unaff_s0 == 1) {
    *(undefined1 *)(iVar1 + 1) = 0;
    *(undefined1 *)(iVar1 + 0xe) = 0;
    *(undefined1 *)(iVar1 + 0xf) = 0;
    *(undefined1 *)(iVar1 + 0x10) = 0;
    *(undefined1 *)(iVar1 + 0x11) = 0;
  }
  return;
}



================================================================