FUNCTION FUN_00001820 @ 0x00001820 size=120
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00001820(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)&DAT_000031b8 + iVar2) = 0xffffffff;
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 4;
  } while (iVar3 < 1);
  local_18 = param_1 + 0x1c;
  local_14 = *(undefined4 *)(param_1 + 0x11c);
  local_10 = *(undefined4 *)(param_1 + 0x120);
  sVar1 = FUN_00002804(&DAT_00004181,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================