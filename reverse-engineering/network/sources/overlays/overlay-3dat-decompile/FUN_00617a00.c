FUNCTION FUN_00617a00 @ 0x00617a00  size=80
CALLERS (6): FUN_0062cb00@0x0062cb00, FUN_0062e720@0x0062e720, FUN_005b1a30@0x005b1a30, FUN_005aeae0@0x005aeae0, FUN_0062d8b0@0x0062d8b0, FUN_0062e2a0@0x0062e2a0
CALLEES (2): FUN_00637180@0x00637180, FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_00617a00(undefined8 param_1)

{
  undefined1 *puVar1;
  
  FUN_00637180();
  puVar1 = (undefined1 *)param_1;
  *puVar1 = 0xb;
  puVar1[1] = 0;
  puVar1[0xf] = 0;
  puVar1[0xe] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  puVar1[0x12] = 0;
  puVar1[0x13] = 0;
  FUN_005aec20(param_1);
  return;
}



================================================================