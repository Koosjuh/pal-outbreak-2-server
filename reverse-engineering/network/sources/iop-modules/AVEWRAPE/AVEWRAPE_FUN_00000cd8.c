FUNCTION FUN_00000cd8 @ 0x00000cd8 size=196
CALLERS (1): FUN_00000d9c@0x00000d9c
CALLEES (0): 

void FUN_00000cd8(undefined2 *param_1)

{
  *param_1 = 1;
  param_1[1] = 1;
  param_1[2] = 1;
  param_1[4] = 1;
  *(undefined **)(param_1 + 6) = &DAT_000029f8;
  *(undefined **)(param_1 + 8) = &DAT_00002a00;
  *(undefined **)(param_1 + 10) = &DAT_00002a08;
  *(undefined ***)(param_1 + 0xc) = &PTR_DAT_00002a0c;
  *(char **)(param_1 + 0xe) = "CONNECT";
  *(undefined **)(param_1 + 0x10) = &DAT_00002a18;
  *(char **)(param_1 + 0x12) = "ERROR";
  *(char **)(param_1 + 0x14) = "DELAYED";
  *(char **)(param_1 + 0x16) = "NO CARRIER";
  *(char **)(param_1 + 0x18) = "NO DIALTONE";
  *(undefined **)(param_1 + 0x1a) = &DAT_00002a48;
  *(undefined1 *)(param_1 + 0x1c) = 0xd;
  *(char **)(param_1 + 0x1e) = "error";
  param_1[3] = 0;
  *(char **)(param_1 + 0x20) = "dial \"%t\"\n";
  *(undefined4 *)(param_1 + 0x22) = 0;
  return;
}


================================================================