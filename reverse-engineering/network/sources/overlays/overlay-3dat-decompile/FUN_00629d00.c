FUNCTION FUN_00629d00 @ 0x00629d00  size=84
CALLERS (6): FUN_0062c1d0@0x0062c1d0, FUN_0062bb20@0x0062bb20, FUN_00628f00@0x00628f00, FUN_0062a680@0x0062a680, FUN_0062aeb0@0x0062aeb0, FUN_006290e0@0x006290e0
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_00629d00(undefined4 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  long lVar2;
  
  lVar2 = FUN_00618ba0();
  puVar1 = (undefined1 *)lVar2;
  if (lVar2 != 0) {
    *puVar1 = 1;
    puVar1[1] = 0;
    puVar1[3] = param_2;
    *(code **)(puVar1 + 0xc) = FUN_00629d60;
    *(undefined4 *)(puVar1 + 0x10) = param_1;
  }
  return;
}



================================================================