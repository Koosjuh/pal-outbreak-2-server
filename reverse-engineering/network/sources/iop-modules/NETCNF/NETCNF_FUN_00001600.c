FUNCTION FUN_00001600 @ 0x00001600 size=232
CALLERS (1): FUN_000016e8@0x000016e8
CALLEES (1): FUN_000096fc@0x000096fc

undefined4 FUN_00001600(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char local_18 [8];
  
  iVar4 = 0;
  cVar1 = *param_1;
  while (cVar1 != ':') {
    if (4 < iVar4) goto LAB_000016d0;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    local_18[iVar4] = cVar1;
    iVar4 = iVar4 + 1;
    cVar1 = *param_1;
  }
  local_18[iVar4] = *param_1;
  local_18[iVar4 + 1] = '\0';
  iVar4 = FUN_000096fc(local_18,0x5001,0,0,0,0);
  iVar2 = FUN_000096fc(local_18,0x5002,0,0,0,0);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0x3ff;
  }
  uVar3 = 0xfffffff0;
  if (param_2 <= iVar2 * (iVar4 >> 10)) {
LAB_000016d0:
    uVar3 = 0;
  }
  return uVar3;
}


================================================================