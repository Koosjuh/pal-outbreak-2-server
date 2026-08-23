FUNCTION FUN_000139bc @ 0x000139bc size=112
CALLERS (2): FUN_00013c48@0x00013c48, FUN_00013e24@0x00013e24
CALLEES (1): FUN_000008d4@0x000008d4

bool FUN_000139bc(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
                 undefined2 param_5)

{
  bool bVar1;
  short sVar2;
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined2 local_18;
  undefined1 local_16;
  undefined2 local_14;
  undefined4 local_10;
  
  if ((&DAT_00016fa0)[param_1] == 0) {
    bVar1 = false;
  }
  else {
    local_20[0] = *(undefined2 *)((&DAT_00016fa0)[param_1] + 2);
    local_16 = 1;
    local_14 = param_5;
    local_1c = param_2;
    local_18 = param_3;
    local_10 = param_4;
    sVar2 = FUN_000008d4(&LAB_00004120_1,local_20,0);
    bVar1 = sVar2 == 0;
  }
  return bVar1;
}


================================================================