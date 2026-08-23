FUNCTION FUN_000090c8 @ 0x000090c8 size=88
CALLERS (1): FUN_0000e870@0x0000e870
CALLEES (1): FUN_00008a8c@0x00008a8c

undefined4 FUN_000090c8(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((*(uint *)(param_1 + 0x48) & 0x400) == 0) {
    uVar1 = 0;
  }
  else {
    local_20 = 0xe0000001;
    if (param_1 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = *(undefined4 *)(param_1 + 0x70);
    }
    uVar1 = FUN_00008a8c(auStack_28);
  }
  return uVar1;
}


================================================================