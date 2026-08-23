FUNCTION FUN_00604860 @ 0x00604860  size=144
CALLERS (9): FUN_005b5520@0x005b5520, FUN_006293f0@0x006293f0, FUN_00603f30@0x00603f30, FUN_00619430@0x00619430, FUN_006278e0@0x006278e0, FUN_00604a80@0x00604a80, FUN_0062d430@0x0062d430, FUN_006296a0@0x006296a0, FUN_006049b0@0x006049b0
CALLEES (0): 
----------------------------------------------------------------

int FUN_00604860(int param_1,uint param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if ((int)(param_2 & 0xff) <= iVar3) {
      return -1;
    }
    iVar2 = param_1 + iVar3 * 0x38;
    if ((*(char *)(iVar2 + 0x10) != '\0') &&
       (lVar1 = func_0x0010a338(iVar2 + 0x10,param_3,0x10), lVar1 == 0)) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}



================================================================