FUNCTION FUN_005ba570 @ 0x005ba570  size=64
CALLERS (16): FUN_005fc850@0x005fc850, FUN_00628760@0x00628760, FUN_005f62e0@0x005f62e0, FUN_005f8340@0x005f8340, FUN_005b47a0@0x005b47a0, FUN_0062cd20@0x0062cd20, FUN_00629a40@0x00629a40, FUN_005b45f0@0x005b45f0, FUN_005b3ed0@0x005b3ed0, FUN_00604af0@0x00604af0, FUN_00607f70@0x00607f70, FUN_0062b670@0x0062b670, ...
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005ba570(undefined1 param_1)

{
  undefined1 *puVar1;
  long lVar2;
  
  lVar2 = FUN_00618ba0();
  puVar1 = (undefined1 *)lVar2;
  if (lVar2 != 0) {
    *puVar1 = 1;
    *(code **)(puVar1 + 0xc) = FUN_005ba5b0;
    puVar1[3] = param_1;
  }
  return;
}



================================================================