FUNCTION FUN_005c0e30 @ 0x005c0e30  size=204
CALLERS (4): FUN_0062cb00@0x0062cb00, FUN_0062e720@0x0062e720, FUN_005f8060@0x005f8060, FUN_00617a50@0x00617a50
CALLEES (1): FUN_005bf0e0@0x005bf0e0
----------------------------------------------------------------

undefined4 FUN_005c0e30(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (cRam006cbb6c == '\0') {
    func_0x00106b60(0x6cdbe6,0,0x460);
    FUN_005bf0e0(0,param_1);
    FUN_005bf0e0(1,param_2);
    FUN_005bf0e0(2,param_3);
    uRam006ff2b1 = 3;
    cRam006cbb6c = '\x01';
    pcRam006cbb48 = FUN_005c1c80;
    uVar1 = 0;
    uRam006cbb68 = 0;
    uRam006cbb4c = param_4;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



================================================================