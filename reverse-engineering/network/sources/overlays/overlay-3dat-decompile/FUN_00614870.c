FUNCTION FUN_00614870 @ 0x00614870  size=228
CALLERS (5): FUN_006140d0@0x006140d0, FUN_00613600@0x00613600, FUN_00613aa0@0x00613aa0, FUN_006130a0@0x006130a0, FUN_006139c0@0x006139c0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00614870(undefined1 *param_1,char *param_2,long param_3)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_4 [4];
  
  if (param_2 != (char *)0x0) {
    lVar2 = func_0x001ae3e0(param_2);
    iVar5 = 0;
    cVar1 = *param_2;
    while (cVar1 != '\0') {
      uVar3 = func_0x001af430(param_2,auStack_4);
      iVar4 = (int)uVar3;
      if ((param_3 < lVar2) && ((int)param_3 + -3 < iVar5 + iVar4)) {
        *param_1 = 0x2e;
        param_1[1] = 0x2e;
        param_1[2] = 0x2e;
        param_1 = param_1 + 3;
        break;
      }
      func_0x0010a4f0(param_1,param_2,uVar3);
      iVar5 = iVar5 + iVar4;
      param_2 = param_2 + iVar4;
      param_1 = param_1 + iVar4;
      cVar1 = *param_2;
    }
  }
  *param_1 = 0;
  return;
}



================================================================