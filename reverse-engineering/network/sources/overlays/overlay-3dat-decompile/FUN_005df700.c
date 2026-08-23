FUNCTION FUN_005df700 @ 0x005df700  size=128
CALLERS (1): FUN_005df780@0x005df780
CALLEES (0): 
----------------------------------------------------------------

int FUN_005df700(int *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = 0;
  for (; *param_1 != 0; param_1 = param_1 + 1) {
    uVar2 = func_0x0010a050();
    lVar3 = func_0x0010a338(param_2,*param_1,uVar2);
    if (lVar3 == 0) break;
    iVar4 = iVar4 + 1;
  }
  iVar1 = -1;
  if (*param_1 != 0) {
    iVar1 = iVar4;
  }
  return iVar1;
}



================================================================