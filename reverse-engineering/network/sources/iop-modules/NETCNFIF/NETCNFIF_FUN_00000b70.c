FUNCTION FUN_00000b70 @ 0x00000b70 size=120
CALLERS (2): FUN_0000161c@0x0000161c, FUN_000003c0@0x000003c0
CALLEES (1): FUN_000028f0@0x000028f0

void FUN_00000b70(int param_1)

{
  FUN_000028f0(param_1,0,0x1340);
  *(undefined4 *)(param_1 + 0x1300) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1304) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1308) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x130c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1310) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1314) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1318) = 0xffffffff;
  FUN_00001320[param_1] = (code)0xff;
  *(undefined1 *)(param_1 + 0x1321) = 0xff;
  *(undefined1 *)(param_1 + 0x1322) = 0xff;
  *(undefined1 *)(param_1 + 0x1323) = 0;
  *(undefined1 *)(param_1 + 0x1324) = 4;
  *(undefined1 *)(param_1 + 0x1325) = 0xff;
  *(undefined1 *)(param_1 + 0x1326) = 0xff;
  *(undefined1 *)(param_1 + 0x1327) = 0xff;
  *(undefined1 *)(param_1 + 0x1328) = 0xff;
  return;
}


================================================================