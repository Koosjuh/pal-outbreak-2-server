FUNCTION FUN_005c44a0 @ 0x005c44a0  size=220
CALLERS (3): FUN_005ff690@0x005ff690, FUN_0062e440@0x0062e440, FUN_005fed10@0x005fed10
CALLEES (4): FUN_005bf230@0x005bf230, FUN_005bf1e0@0x005bf1e0, FUN_005bdfe0@0x005bdfe0, FUN_005c5ff0@0x005c5ff0
----------------------------------------------------------------

undefined8 FUN_005c44a0(char param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == '\0') {
    uRam006cbc84 = 0;
    FUN_005bf230(param_2);
  }
  else if (cRam006ff2b0 == '\0') {
    uRam006fec00 = (undefined4)param_2;
    FUN_005c5ff0(uRam006febe8);
  }
  else {
    uVar1 = FUN_005bf1e0(2);
    iVar2 = (uVar1 & 0xffff) - 1;
    *(undefined2 *)(iVar2 * 0x144 + 0x6cfb70) = 1;
    uRam006cbc84 = 0;
    FUN_005bf230(param_2);
    sRam006d2158 = (short)iVar2 + 1;
    uRam006cbc84 = 0;
    uRam006cbc7e = 0x10;
    FUN_005bdfe0(0x21);
  }
  return 0;
}



================================================================