FUNCTION FUN_005af1a0 @ 0x005af1a0  size=64
CALLERS (3): FUN_005ace00@0x005ace00, FUN_005f7800@0x005f7800, FUN_0062d5e0@0x0062d5e0
CALLEES (2): FUN_005c71d0@0x005c71d0, FUN_005c7020@0x005c7020
----------------------------------------------------------------

void FUN_005af1a0(int param_1,long param_2)

{
  if (*(char *)(param_1 + 0x146a) != '\0') {
    *(undefined1 *)(param_1 + 0x146a) = 0;
    if (param_2 == 0) {
      FUN_005c7020();
    }
    else {
      FUN_005c71d0();
    }
  }
  return;
}



================================================================