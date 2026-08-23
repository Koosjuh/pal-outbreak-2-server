FUNCTION FUN_005ae130 @ 0x005ae130  size=176
CALLERS (2): FUN_005b4a50@0x005b4a50, FUN_005ade20@0x005ade20
CALLEES (7): FUN_005ae2c0@0x005ae2c0, FUN_005ae1e0@0x005ae1e0, FUN_005ae260@0x005ae260, FUN_005ae310@0x005ae310, FUN_005ae210@0x005ae210, FUN_005ae3c0@0x005ae3c0, FUN_005ae3a0@0x005ae3a0
----------------------------------------------------------------

undefined8 FUN_005ae130(int param_1)

{
  undefined8 uVar1;
  
  switch(*(undefined1 *)(param_1 + 0x993)) {
  case 0:
    uVar1 = FUN_005ae1e0();
    break;
  case 1:
    uVar1 = FUN_005ae210();
    break;
  case 2:
    uVar1 = FUN_005ae260();
    break;
  case 3:
    uVar1 = FUN_005ae2c0();
    break;
  case 4:
    uVar1 = FUN_005ae310();
    break;
  case 5:
    uVar1 = FUN_005ae3a0();
    break;
  case 6:
    uVar1 = FUN_005ae3c0();
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}



================================================================