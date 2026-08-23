FUNCTION FUN_0062a5e0 @ 0x0062a5e0  size=160
CALLERS (2): FUN_00629330@0x00629330, FUN_006293b0@0x006293b0
CALLEES (6): FUN_0062b020@0x0062b020, FUN_0062a6d0@0x0062a6d0, FUN_0062a8c0@0x0062a8c0, FUN_0062adb0@0x0062adb0, FUN_0062a680@0x0062a680, FUN_0062aeb0@0x0062aeb0
----------------------------------------------------------------

undefined8 FUN_0062a5e0(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  switch(uRam00695d10) {
  case 0:
    uVar1 = FUN_0062a680();
    break;
  case 1:
    uVar1 = FUN_0062a6d0();
    break;
  case 2:
    uVar1 = FUN_0062a8c0();
    break;
  case 3:
    uVar1 = FUN_0062adb0();
    break;
  case 4:
    uVar1 = FUN_0062aeb0();
    break;
  case 5:
    uVar1 = FUN_0062b020();
  }
  return uVar1;
}



================================================================