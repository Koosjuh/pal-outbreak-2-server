FUNCTION FUN_000008d8 @ 0x000008d8 size=188
CALLERS (1): FUN_00004754@0x00004754
CALLEES (1): FUN_0000057c@0x0000057c

void FUN_000008d8(int param_1)

{
  undefined4 uVar1;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x70);
    local_26 = 0x800;
    local_24 = 6;
    local_28 = 1;
    local_23 = 4;
    local_22 = 1;
    local_16 = *(undefined2 *)(param_1 + 0x88);
    local_14 = *(undefined2 *)(param_1 + 0x8a);
    local_12 = *(undefined2 *)(param_1 + 0x8c);
    local_1c = DAT_0001b3ec;
    local_20 = DAT_0001b3e8;
    local_10 = (undefined1)uVar1;
    local_1e = DAT_0001b3ea;
    local_f = (undefined1)((uint)uVar1 >> 8);
    local_e = (undefined1)((uint)uVar1 >> 0x10);
    local_d = (undefined1)((uint)uVar1 >> 0x18);
    local_1a = 0;
    local_19 = 0;
    local_18 = 0;
    local_17 = 0;
    FUN_0000057c(param_1,&local_28);
  }
  return;
}


================================================================