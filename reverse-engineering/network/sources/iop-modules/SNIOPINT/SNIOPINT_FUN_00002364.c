FUNCTION FUN_00002364 @ 0x00002364 size=120
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00002364(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar3 = 3;
  iVar2 = 0xc;
  do {
    *(undefined4 *)((int)&DAT_00009508 + iVar2) = 0xffffffff;
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + -4;
  } while (-1 < iVar3);
  local_18 = param_1 + 0x1c;
  local_14 = *(undefined4 *)(param_1 + 0x11c);
  local_10 = *(undefined4 *)(param_1 + 0x120);
  sVar1 = FUN_00003614(&DAT_00004181,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================