FUNCTION FUN_006053e0 @ 0x006053e0  size=72
CALLERS (1): FUN_00605430@0x00605430
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

long FUN_006053e0(undefined2 param_1)

{
  undefined1 *puVar1;
  long lVar2;
  
  lVar2 = FUN_00618ba0();
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(undefined2 *)(puVar1 + 0x22) = param_1;
    *(undefined4 *)(puVar1 + 0x30) = 1;
    puVar1[2] = 0;
  }
  return lVar2;
}



================================================================