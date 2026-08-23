FUNCTION FUN_00013b74 @ 0x00013b74 size=136
CALLERS (2): FUN_00013e24@0x00013e24, FUN_00013c48@0x00013c48
CALLEES (0): 

undefined4 FUN_00013b74(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = 0;
  pcVar4 = (char *)*param_2;
  pcVar2 = (char *)*param_1;
  do {
    pcVar3 = pcVar2 + 1;
    cVar1 = *pcVar4;
    if (cVar1 == '\0') {
      uVar6 = 0;
LAB_00013bd8:
      if (iVar5 != 0) {
LAB_00013be0:
        *(char *)*param_1 = (char)iVar5;
      }
      *param_2 = pcVar4;
      *param_1 = pcVar3;
      return uVar6;
    }
    if (cVar1 == '.') {
      pcVar4 = pcVar4 + 1;
      uVar6 = 1;
      if (iVar5 != 0) goto LAB_00013be0;
      *pcVar3 = '.';
      pcVar3 = pcVar2 + 2;
      iVar5 = 1;
      goto LAB_00013bd8;
    }
    pcVar4 = pcVar4 + 1;
    *pcVar3 = cVar1;
    iVar5 = iVar5 + 1;
    pcVar2 = pcVar3;
  } while( true );
}


================================================================