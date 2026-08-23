FUNCTION FUN_00000de4 @ 0x00000de4 size=364
CALLERS (1): FUN_00002858@0x00002858
CALLEES (3): FUN_00003614@0x00003614, FUN_00003818@0x00003818, FUN_00003810@0x00003810

void FUN_00000de4(int param_1)

{
  short sVar1;
  short *psVar2;
  short local_30;
  undefined2 local_2e;
  int local_2c;
  undefined4 local_28;
  short local_20 [3];
  short local_1a;
  undefined2 local_18 [4];
  
  local_18[0] = *(undefined2 *)(param_1 + 0x1c);
  psVar2 = (short *)(param_1 + 0x1c);
  sVar1 = FUN_00003614(&DAT_00004117,local_18,local_20);
  if (sVar1 == 0) {
    if ((local_1a == 0) && (((local_20[0] == 4 || (local_20[0] == 6)) || (local_20[0] == 9)))) {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      local_30 = *psVar2;
      local_2e = *(undefined2 *)(param_1 + 0x1e);
      local_2c = param_1 + 0x20;
      local_28 = 0xb8;
      sVar1 = FUN_00003614(&DAT_00004119,&local_30,0);
      if (sVar1 == -1) {
        FUN_00003818(DAT_00009464);
        if ((&DAT_00009432)[*psVar2 * 10] == 0) {
          *(undefined4 *)(param_1 + 0x18) = 0xfffffff0;
        }
        else {
          *(int *)(param_1 + 0x18) = (int)*(short *)(&DAT_00009434 + *psVar2 * 0x14);
          (&DAT_00009432)[*psVar2 * 10] = 0;
        }
        FUN_00003810(DAT_00009464);
      }
      else {
        *(int *)(param_1 + 0x18) = (int)sVar1;
      }
    }
  }
  else {
    *(int *)(param_1 + 0x18) = (int)sVar1;
  }
  return;
}


================================================================