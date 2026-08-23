FUNCTION FUN_00617980 @ 0x00617980  size=64
CALLERS (1): FUN_006177d0@0x006177d0
CALLEES (1): FUN_00618b60@0x00618b60
----------------------------------------------------------------

void FUN_00617980(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x16) + -1;
  *(short *)(param_1 + 0x16) = sVar1;
  if (sVar1 == 0) {
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
    FUN_00618b60();
  }
  return;
}



================================================================
FUNCTION thunk_FUN_00617a00 @ 0x006179c0  size=8
CALLERS (1): FUN_006177d0@0x006177d0
CALLEES (0): 
----------------------------------------------------------------

void thunk_FUN_00617a00(undefined8 param_1)

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
FUNCTION thunk_FUN_00617a00 @ 0x006179d0  size=8
CALLERS (1): FUN_006177d0@0x006177d0
CALLEES (0): 
----------------------------------------------------------------

void thunk_FUN_00617a00(undefined8 param_1)

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