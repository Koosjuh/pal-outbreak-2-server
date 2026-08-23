FUNCTION FUN_00001164 @ 0x00001164 size=220
CALLERS (2): FUN_00001458@0x00001458, FUN_000000c8@0x000000c8
CALLEES (3): FUN_00002164@0x00002164, FUN_00000e50@0x00000e50, FUN_00000e94@0x00000e94

undefined4 FUN_00001164(void)

{
  char *pcVar1;
  undefined4 uVar2;
  
  DAT_00002734 = FUN_00000e94();
  DAT_00002730 = FUN_00000e50();
  if (DAT_00002730 == 2) {
    pcVar1 = "CardBus";
  }
  else {
    pcVar1 = "no";
    if (DAT_00002730 == 1) {
      pcVar1 = "16bit";
    }
  }
  if (DAT_00002734 == 2) {
    uVar2 = 5;
  }
  else {
    uVar2 = 0;
    if (DAT_00002734 == 1) {
      uVar2 = 3;
    }
  }
  FUN_00002164("dev9: %s pcmcia card detected. vcc = %dV\n",pcVar1,uVar2);
  if (DAT_00002734 == 3) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0xffffffff;
    if (DAT_00002730 == 1) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================