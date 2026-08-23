FUNCTION FUN_005f8220 @ 0x005f8220  size=120
CALLERS (1): FUN_005f7800@0x005f7800
CALLEES (4): FUN_005bfd80@0x005bfd80, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0
----------------------------------------------------------------

void FUN_005f8220(int param_1)

{
  undefined2 uVar1;
  
  if (*(char *)(param_1 + 0xf) == '\x01') {
    FUN_005b6900();
  }
  else if (*(char *)(param_1 + 0xf) == '\0') {
    uRam006c45fc = 1;
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 5;
    uVar1 = FUN_005adc80(1);
    FUN_005bfd80(uVar1,0x5f82a0);
  }
  return;
}



================================================================