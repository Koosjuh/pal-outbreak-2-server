FUNCTION FUN_0000a8a8 @ 0x0000a8a8 size=64
CALLERS (2): FUN_0000ad44@0x0000ad44, FUN_00007000@0x00007000
CALLEES (1): FUN_00006e48@0x00006e48

undefined4 FUN_0000a8a8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (*(char *)(param_1 + 4) != '\0') {
    FUN_00006e48();
    *(undefined1 *)(param_1 + 4) = 0;
    uVar1 = 0;
  }
  return uVar1;
}


================================================================