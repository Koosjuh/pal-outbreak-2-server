FUNCTION FUN_0000ad44 @ 0x0000ad44 size=180
CALLERS (9): FUN_0000c428@0x0000c428, FUN_0000c870@0x0000c870, FUN_0000d704@0x0000d704, FUN_00007000@0x00007000, FUN_0000d42c@0x0000d42c, FUN_0000dfe4@0x0000dfe4, FUN_0000c704@0x0000c704, FUN_0000ca20@0x0000ca20, FUN_0000c088@0x0000c088
CALLEES (5): FUN_0000becc@0x0000becc, FUN_0000eecc@0x0000eecc, FUN_0000a8e8@0x0000a8e8, FUN_0001168c@0x0001168c, FUN_0000a8a8@0x0000a8a8

int FUN_0000ad44(int param_1)

{
  if (param_1 != 0) {
    FUN_0000eecc(param_1 + 0x130);
    if ((*(byte *)(param_1 + 0x13f) & 0x80) != 0) {
      FUN_0000a8a8(param_1);
      FUN_0000a8e8(param_1);
      FUN_0001168c((param_1 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(param_1 + 0x168),3
                   ,0xff);
      *(undefined2 *)(param_1 + 0x138) = 0;
      return 0;
    }
    *(undefined2 *)(param_1 + 0x13a) = 0;
    FUN_0000becc(param_1);
    if (DAT_00016194 != 0) {
      return param_1;
    }
  }
  return 0;
}


================================================================