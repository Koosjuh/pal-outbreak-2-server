FUNCTION FUN_0062adb0 @ 0x0062adb0  size=244
CALLERS (1): FUN_0062a5e0@0x0062a5e0
CALLEES (4): FUN_00637180@0x00637180, FUN_006345e0@0x006345e0, FUN_00634ab0@0x00634ab0, FUN_006371d0@0x006371d0
----------------------------------------------------------------

undefined8 FUN_0062adb0(int param_1,undefined1 *param_2)

{
  char cVar1;
  
  if (param_2[1] == '\x01') {
    cVar1 = FUN_00634ab0(param_1 + 0xfc4,uRam006c4610,uRam006c4618 | uRam006c4620);
    if ((cVar1 == -1) || (cVar1 == '\x01')) {
      *param_2 = 1;
      param_2[1] = 0;
      param_2[2] = 0;
      uRam006c4fd3 = 1;
      FUN_00637180();
      func_0x001b0140(1);
    }
  }
  else if (param_2[1] == '\0') {
    FUN_006371d0(0x42980000,0x118);
    FUN_006345e0(0,0,0x60,param_1 + 0xfc4);
    param_2[1] = param_2[1] + '\x01';
  }
  return 0;
}



================================================================