FUNCTION FUN_005c7f20 @ 0x005c7f20  size=204
CALLERS (3): FUN_005bc990@0x005bc990, FUN_005bca90@0x005bca90, FUN_005bcfd0@0x005bcfd0
CALLEES (1): FUN_005c7ff0@0x005c7ff0
----------------------------------------------------------------

void FUN_005c7f20(undefined1 param_1)

{
  undefined8 uVar1;
  
  switch(param_1) {
  case 0:
    return;
  case 1:
    uVar1 = 5;
    break;
  case 2:
    uVar1 = 6;
    break;
  case 3:
    uVar1 = 10;
    break;
  case 4:
    uVar1 = 7;
    break;
  case 5:
    uVar1 = 8;
    break;
  case 6:
    uVar1 = 9;
    break;
  case 7:
    uVar1 = 0x11;
    break;
  case 8:
    uVar1 = 0;
    break;
  case 9:
    uVar1 = 1;
    break;
  case 10:
    uVar1 = 2;
    break;
  case 0xb:
    uVar1 = 3;
    break;
  case 0xc:
    uVar1 = 4;
    break;
  case 0xd:
    uVar1 = 0x12;
    break;
  case 0xe:
    uVar1 = 0x13;
    break;
  default:
    goto switchD_005c7f48_default;
  }
  uVar1 = FUN_005c7ff0(uVar1);
  func_0x00109ab0(0x6fc5e8,uVar1);
switchD_005c7f48_default:
  return;
}



================================================================