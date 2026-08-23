FUNCTION FUN_000049c4 @ 0x000049c4 size=108
CALLERS (1): FUN_000046d4@0x000046d4
CALLEES (2): FUN_0000ec30@0x0000ec30, FUN_00004254@0x00004254

undefined4 FUN_000049c4(short param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_00004254((int)param_1);
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    sVar1 = FUN_0000ec30(*(uint *)(iVar2 + 4) & *(uint *)(iVar2 + 0x10),
                         *(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 4),0,1,0);
    uVar3 = 0xffffffff;
    if (sVar1 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}


================================================================