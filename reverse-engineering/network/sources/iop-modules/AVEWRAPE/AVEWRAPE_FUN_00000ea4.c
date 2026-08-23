FUNCTION FUN_00000ea4 @ 0x00000ea4 size=532
CALLERS (1): FUN_00002098@0x00002098
CALLEES (3): FUN_00002804@0x00002804, FUN_00001b3c@0x00001b3c, FUN_00002850@0x00002850

void FUN_00000ea4(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 *local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_c = 0;
  if (param_1[1] != 0) {
    local_10 = 1;
    local_c = 1;
    FUN_00001b3c(*param_1);
  }
  FUN_00002850(3,&local_10,4);
  local_18 = 2;
  local_16 = 4;
  local_14 = &local_c;
  sVar1 = FUN_00002804(&DAT_0000415a,&local_18,0);
  iVar2 = -1;
  if (sVar1 == 0) {
    DAT_00003118 = *(undefined2 *)(param_1 + 200);
    DAT_0000311a = *(undefined2 *)((int)param_1 + 0x322);
    DAT_0000311c = *(undefined2 *)(param_1 + 0xc9);
    DAT_0000311e = *(undefined2 *)((int)param_1 + 0x326);
    DAT_00003120 = *(undefined2 *)(param_1 + 0xca);
    DAT_00003124 = 0;
    DAT_00003128 = 0;
    DAT_00003168 = &DAT_00003118;
    DAT_00003130 = *(undefined2 *)((int)param_1 + 0x1e);
    DAT_0000313c = param_1 + 0xb8;
    DAT_00003132 = (ushort)(*(char *)(param_1 + 0xb8) != '\0');
    DAT_00003134 = 0x5a;
    DAT_00003136 = 0;
    DAT_00003138 = 0x1e;
    DAT_00003140 = 0;
    DAT_00003144 = 0;
    DAT_0000316c = &DAT_00003130;
    DAT_00003148 = 0;
    DAT_0000314c = 0;
    DAT_00003150 = *(undefined2 *)(param_1 + 2);
    DAT_00003152 = 0x5dc;
    DAT_00003174 = param_1 + 8;
    DAT_00003154 = 0x12345678;
    DAT_00003158 = 0;
    DAT_0000315a = 0;
    DAT_0000315c = 0;
    DAT_00003160 = 0;
    DAT_00003164 = 0;
    DAT_00003178 = param_1 + 0x48;
    DAT_0000317c = param_1 + 0x88;
    DAT_00003180 = param_1 + 0x98;
    DAT_00003184 = param_1 + 0xa8;
    DAT_00003170 = &DAT_00003148;
    DAT_00003188 = 0;
    DAT_0000318c = 0;
    DAT_00003190 = 0;
    DAT_00003194 = 0;
    DAT_00003196 = 0;
    DAT_00003198 = 0x8001;
    if (*(short *)(param_1 + 7) == 0) {
      DAT_00003198 = 1;
    }
    else {
      DAT_000031a0 = 0;
      DAT_000031a4 = 0;
      DAT_000031a8 = 0;
      DAT_000031ac = 0;
      DAT_000031b0 = 0;
      DAT_000031b4 = 0;
    }
    sVar1 = FUN_00002804(&DAT_00004154,&DAT_00003168,0);
    iVar2 = (int)sVar1;
  }
  param_1[6] = iVar2;
  return;
}


================================================================