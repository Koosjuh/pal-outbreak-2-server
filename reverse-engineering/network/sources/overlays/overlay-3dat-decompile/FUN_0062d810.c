FUNCTION FUN_0062d810 @ 0x0062d810  size=160
CALLERS (1): FUN_0062d640@0x0062d640
CALLEES (4): FUN_005bfd80@0x005bfd80, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0
----------------------------------------------------------------

void FUN_0062d810(int param_1)

{
  undefined2 uVar1;
  
  if (*(char *)(param_1 + 0xf) == '\x01') {
    FUN_005b6900();
  }
  else if (*(char *)(param_1 + 0xf) == '\0') {
    cRam006c45fc = (char)*(undefined2 *)(param_1 + 0x53a) + '\x01';
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 5;
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    *(undefined1 *)(param_1 + 0x4b7) = 0;
    *(undefined4 *)(param_1 + 0x9a0) = 0x708;
    *(undefined1 *)(param_1 + 0x10b5) = 0;
    uVar1 = FUN_005adc80(1);
    FUN_005bfd80(uVar1,0x62d8b0);
  }
  return;
}



================================================================