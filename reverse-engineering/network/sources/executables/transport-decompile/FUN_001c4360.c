
undefined8 FUN_001c4360(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x30) + 6) == -1) {
    uRam00368480 = 0;
  }
  else {
    uRam00368480 = FUN_001c3b10();
  }
  *(undefined1 *)(param_1 + 0xd) = 0x10;
  return 0;
}

