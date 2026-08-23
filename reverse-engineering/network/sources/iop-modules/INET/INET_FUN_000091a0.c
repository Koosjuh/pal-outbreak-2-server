FUNCTION FUN_000091a0 @ 0x000091a0 size=344
CALLERS (0): 
CALLEES (3): FUN_00019a60@0x00019a60, FUN_00019a40@0x00019a40, FUN_00009e28@0x00009e28

int FUN_000091a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_20 [8];
  int local_18;
  undefined4 local_14;
  
  FUN_00019a40(auStack_20);
  FUN_00019a60(auStack_20,&local_18,&local_14);
  iVar3 = local_18 / 0x15180;
  iVar1 = (local_18 % 0x15180) / 0xe10;
  local_18 = (local_18 % 0x15180) % 0xe10;
  iVar4 = 0;
  iVar2 = local_18 / 0x3c;
  local_18 = local_18 % 0x3c;
  if (0 < iVar3) {
    iVar4 = FUN_00009e28(&DAT_0001b788,iVar3);
  }
  if (iVar1 < 1) {
    if (iVar2 < 1) goto LAB_000092c8;
  }
  else {
    iVar3 = FUN_00009e28(s__02d__0001b78c,iVar1);
    iVar4 = iVar4 + iVar3;
  }
  iVar3 = FUN_00009e28(s__02d__0001b78c,iVar2);
  iVar4 = iVar4 + iVar3;
LAB_000092c8:
  iVar3 = FUN_00009e28("%02d.%06d",local_18,local_14);
  return iVar4 + iVar3;
}


================================================================