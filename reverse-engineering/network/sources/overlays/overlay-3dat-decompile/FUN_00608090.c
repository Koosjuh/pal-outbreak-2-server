FUNCTION FUN_00608090 @ 0x00608090  size=56
CALLERS (1): FUN_00607ac0@0x00607ac0
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_00608090(void)

{
  undefined1 *puVar1;
  long lVar2;
  
  lVar2 = FUN_00618ba0();
  puVar1 = (undefined1 *)lVar2;
  if (lVar2 != 0) {
    *puVar1 = 1;
    puVar1[1] = 0;
    *(code **)(puVar1 + 0xc) = FUN_006080d0;
  }
  return;
}



================================================================