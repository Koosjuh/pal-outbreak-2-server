FUNCTION FUN_005c5780 @ 0x005c5780  size=132
CALLERS (1): FUN_005c5810@0x005c5810
CALLEES (1): FUN_005c7ff0@0x005c7ff0
----------------------------------------------------------------

void FUN_005c5780(undefined1 param_1)

{
  undefined8 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = 0xb;
    break;
  case 1:
    uVar1 = 0xc;
    break;
  case 2:
    uVar1 = 0xd;
    break;
  case 3:
    uVar1 = 0xe;
    break;
  case 4:
    uVar1 = 0xf;
    break;
  case 5:
    uVar1 = 0x10;
    break;
  default:
    goto switchD_005c57a8_default;
  }
  uVar1 = FUN_005c7ff0(uVar1);
  func_0x00109ab0(0x6fbe58,uVar1);
switchD_005c57a8_default:
  return;
}



================================================================