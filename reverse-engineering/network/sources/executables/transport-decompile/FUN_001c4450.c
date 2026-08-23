
undefined8 FUN_001c4450(undefined8 param_1)

{
  if (*(char *)(*(int *)((int)param_1 + 0x30) + 6) == -1) {
    uRam00368484 = 0x14;
    uRam0036848a = 0x1518;
    uRam00368486 = 300;
    uRam00368488 = 300;
    uRam0036848c = 0x708;
    uRam0036848e = 0x708;
    uRam00368490 = 0x708;
    uRam00368492 = 0x708;
  }
  else {
    uRam00368484 = FUN_001c3ab0();
    uRam00368486 = FUN_001c3ab0(param_1);
    uRam00368488 = FUN_001c3ab0(param_1);
    uRam0036848a = FUN_001c3ab0(param_1);
    uRam0036848c = FUN_001c3ab0(param_1);
    uRam0036848e = FUN_001c3ab0(param_1);
    uRam00368490 = FUN_001c3ab0(param_1);
    uRam00368492 = FUN_001c3ab0(param_1);
  }
  *(undefined1 *)((int)param_1 + 0xd) = 4;
  return 0;
}

