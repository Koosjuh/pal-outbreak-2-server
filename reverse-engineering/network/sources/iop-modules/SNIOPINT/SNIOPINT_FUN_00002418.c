FUNCTION FUN_00002418 @ 0x00002418 size=216
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00002418(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int local_18;
  int local_14;
  
  iVar3 = 0;
  local_18 = param_1 + 0x1c;
  local_14 = 0;
  iVar2 = 0;
  do {
    if (*(int *)((int)&DAT_00009508 + iVar2) < 0) {
      local_14 = iVar3 * 0xc24 + 0x9518;
      break;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 4;
  } while (iVar3 < 4);
  if (local_14 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  }
  else {
    sVar1 = FUN_00003614(&DAT_00004183,&local_18,0);
    *(int *)(param_1 + 0x18) = (int)sVar1;
    (&DAT_00009508)[iVar3] = (int)sVar1;
  }
  return;
}


================================================================