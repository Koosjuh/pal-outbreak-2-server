FUNCTION FUN_0062c3f0 @ 0x0062c3f0  size=388
CALLERS (1): FUN_0062c350@0x0062c350
CALLEES (1): FUN_005b8da0@0x005b8da0
----------------------------------------------------------------

void FUN_0062c3f0(int param_1,int param_2)

{
  *(undefined2 *)(param_1 + 0x10b8) =
       *(undefined2 *)
        ((*(short *)(param_2 + 10) * 0x44 + (int)*(short *)(param_2 + 10)) * 2 + param_1 + 0x12c2);
  *(undefined2 *)(param_1 + 0x10ba) =
       *(undefined2 *)
        ((*(short *)(param_2 + 10) * 0x44 + (int)*(short *)(param_2 + 10)) * 2 + param_1 + 0x12c4);
  *(undefined2 *)(param_1 + 0x10bc) =
       *(undefined2 *)
        ((*(short *)(param_2 + 10) * 0x44 + (int)*(short *)(param_2 + 10)) * 2 + param_1 + 0x12c6);
  *(undefined1 *)(param_1 + 0x10be) =
       *(undefined1 *)
        ((*(short *)(param_2 + 10) * 0x44 + (int)*(short *)(param_2 + 10)) * 2 + param_1 + 0x12c8);
  *(undefined1 *)(param_1 + 0x10bf) =
       *(undefined1 *)
        ((*(short *)(param_2 + 10) * 0x44 + (int)*(short *)(param_2 + 10)) * 2 + param_1 + 0x12c9);
  func_0x001069a8(param_1 + 0x10c0,
                  param_1 + (*(short *)(param_2 + 10) * 0x44 + (int)*(short *)(param_2 + 10)) * 2 +
                  0x12ca,0x81);
  func_0x001069a8(param_1 + 0xefb,
                  param_1 + *(short *)(param_2 + 10) * 0x24 + (int)*(short *)(param_2 + 10) + 0x1045
                  ,0x10);
  func_0x001069a8(param_1 + 0xf0b,
                  param_1 + *(short *)(param_2 + 10) * 0x24 + (int)*(short *)(param_2 + 10) + 0x1055
                  ,0x10);
  *(undefined1 *)(param_1 + 0x43c) = 1;
  *(undefined1 *)(param_1 + 0x43f) = 0;
  FUN_005b8da0(0xffffffffffffffb0,param_1 + 0x43c);
  *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + '\x01';
  *(undefined1 *)(param_2 + 2) = 0;
  return;
}



================================================================