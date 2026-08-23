FUNCTION FUN_0060f680 @ 0x0060f680  size=428
CALLERS (1): FUN_0060e060@0x0060e060
CALLEES (0): 
----------------------------------------------------------------

void FUN_0060f680(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4,int param_5)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  
  if (param_4 == 0) {
    iVar3 = 0;
    if (param_5 == 0) {
      do {
        lVar2 = func_0x0011a9f8(param_1,param_2,param_3);
      } while (lVar2 < 0);
    }
    else {
      bVar1 = 0 < param_5;
      while ((bVar1 && (lVar2 = func_0x0011a9f8(param_1,param_2,param_3), lVar2 < 0))) {
        iVar3 = iVar3 + 1;
        bVar1 = iVar3 < param_5;
      }
    }
  }
  else {
    iVar3 = 0;
    if (param_5 == 0) {
      do {
        lVar2 = func_0x0011aa18(param_1,param_2,param_3,param_4);
      } while (lVar2 < 0);
    }
    else {
      bVar1 = 0 < param_5;
      while ((bVar1 && (lVar2 = func_0x0011aa18(param_1,param_2,param_3,param_4), lVar2 < 0))) {
        iVar3 = iVar3 + 1;
        bVar1 = iVar3 < param_5;
      }
    }
  }
  return;
}



================================================================