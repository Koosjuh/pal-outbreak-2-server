FUNCTION FUN_00005f10 @ 0x00005f10 size=88
CALLERS (2): FUN_00005828@0x00005828, FUN_00004ec4@0x00004ec4
CALLEES (2): FUN_00001080@0x00001080, FUN_00004254@0x00004254

bool FUN_00005f10(undefined4 param_1,short param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_00004254((int)param_2);
  if (iVar2 == 0) {
    bVar1 = false;
  }
  else {
    uVar3 = FUN_00001080(param_1);
    bVar1 = (uVar3 & 0xff000000) == 0x7f000000;
  }
  return bVar1;
}


================================================================