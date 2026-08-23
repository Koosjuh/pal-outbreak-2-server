FUNCTION FUN_000019a4 @ 0x000019a4 size=608
CALLERS (1): FUN_00002858@0x00002858
CALLEES (3): FUN_00003660@0x00003660, FUN_00003614@0x00003614, FUN_000001c8@0x000001c8

void FUN_000019a4(int *param_1)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [2];
  
  if (*param_1 == 0) {
    local_28 = 0;
    local_24 = 0;
    local_20[0] = 0x28;
  }
  else {
    local_28 = 1;
    local_24 = 1;
    local_20[0] = 10;
    FUN_000001c8(param_1[1]);
  }
  FUN_00003660(3,&local_28,4);
  local_30 = 2;
  local_2c = &local_24;
  local_2e = 4;
  sVar2 = FUN_00003614(&DAT_0000415a,&local_30,0);
  iVar3 = -1;
  if (sVar2 == 0) {
    local_2c = local_20;
    local_30 = 1;
    local_2e = 4;
    sVar2 = FUN_00003614(&DAT_0000415a,&local_30,0);
    iVar3 = -1;
    if (sVar2 == 0) {
      DAT_00009468 = 6;
      DAT_0000946a = 0;
      DAT_0000946c = 0;
      DAT_0000946e = 3;
      DAT_00009470 = 1;
      DAT_00009474 = 0;
      DAT_00009478 = 0;
      DAT_000094b8 = &DAT_00009468;
      DAT_00009480 = *(undefined2 *)((int)param_1 + 0x1e);
      bVar1 = (char)param_1[200] == '\0';
      DAT_0000948c = param_1 + 200;
      if (bVar1) {
        DAT_0000948c = (int *)&DAT_00003864;
      }
      DAT_00009482 = (ushort)!bVar1;
      DAT_00009484 = 0x5a;
      DAT_00009486 = 0;
      DAT_00009488 = 0x1e;
      DAT_00009490 = 0;
      DAT_00009494 = 0;
      DAT_000094bc = &DAT_00009480;
      DAT_00009498 = 0;
      DAT_0000949c = 0;
      DAT_000094a0 = (undefined2)param_1[2];
      DAT_000094a2 = 0x5dc;
      DAT_000094d0 = param_1 + 0x48;
      DAT_000094a4 = 0x12345678;
      DAT_000094b0 = 0;
      DAT_000094b4 = 0;
      DAT_000094a8 = 0;
      DAT_000094aa = 0;
      DAT_000094ac = 0;
      DAT_000094d4 = param_1 + 0x88;
      DAT_000094c0 = &DAT_00009498;
      DAT_000094c4 = 0;
      DAT_000094c8 = 0;
      DAT_000094cc = 0;
      DAT_000094d8 = &DAT_00003864;
      DAT_000094dc = 0;
      DAT_000094e0 = 0;
      DAT_000094e4 = 0;
      DAT_000094e6 = 0;
      DAT_000094e8 = 0x8001;
      if ((short)param_1[7] == 0) {
        DAT_000094e8 = 1;
      }
      else {
        DAT_000094f0 = 0;
        DAT_000094f4 = 0;
        DAT_000094f8 = 0;
        DAT_000094fc = 0;
        DAT_00009500 = 0;
        DAT_00009504 = 0;
      }
      sVar2 = FUN_00003614(&DAT_00004154,&DAT_000094b8,0);
      iVar3 = (int)sVar2;
    }
  }
  param_1[6] = iVar3;
  return;
}


================================================================