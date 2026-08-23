FUNCTION FUN_00003800 @ 0x00003800 size=92
CALLERS (0): 
CALLEES (1): FUN_00010c64@0x00010c64

int FUN_00003800(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_1 == 1) {
    puVar2 = &DAT_00012fe8;
  }
  else {
    if (param_1 != 2) {
      iVar1 = -0x10000;
      goto LAB_0000384c;
    }
    puVar2 = &DAT_000130e8;
  }
  FUN_00010c64(puVar2);
  iVar1 = 0;
LAB_0000384c:
  return iVar1 >> 0x10;
}


================================================================