FUNCTION FUN_00001740 @ 0x00001740 size=156
CALLERS (1): FUN_00001c64@0x00001c64
CALLEES (0): 

void FUN_00001740(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 2;
  puVar1 = param_1 + 2;
  *param_1 = 0xffffffff;
  *(undefined1 *)(param_1 + 4) = 0xff;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  do {
    puVar1[0xe] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  *(undefined1 *)((int)param_1 + 0x97) = 0xff;
  *(undefined1 *)(param_1 + 0x26) = 0xff;
  *(undefined1 *)((int)param_1 + 0x12e) = 0xff;
  *(undefined1 *)((int)param_1 + 0x93) = 0xff;
  *(undefined1 *)(param_1 + 0x25) = 0xff;
  *(undefined1 *)((int)param_1 + 0x91) = 0xff;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  *(undefined1 *)((int)param_1 + 0xf7) = 0;
  *(undefined1 *)(param_1 + 0x3d) = 4;
  param_1[0x4f] = 0xffffffff;
  param_1[0x53] = 0xffffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0x1a] = 0xffffffff;
  param_1[0x22] = 0xffffffff;
  return;
}


================================================================