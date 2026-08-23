FUNCTION FUN_0000d8c0 @ 0x0000d8c0 size=208
CALLERS (2): FUN_000054a8@0x000054a8, FUN_00001d0c@0x00001d0c
CALLEES (6): FUN_000053b4@0x000053b4, FUN_0001073c@0x0001073c, FUN_00010108@0x00010108, FUN_00010764@0x00010764, FUN_000107dc@0x000107dc, FUN_0000a7ac@0x0000a7ac

undefined4 FUN_0000d8c0(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  cVar1 = *param_1;
  pcVar3 = *(char **)(param_1 + 0xc);
  param_1[8] = '\0';
  param_1[9] = '\0';
  while( true ) {
    if (cVar1 == '\x05') {
      param_1[8] = '\0';
      param_1[9] = '\0';
      return 0;
    }
    iVar2 = FUN_000053b4();
    if (((iVar2 != 0) || (*(short *)(param_1 + 8) != 0)) || (*pcVar3 == '\x04')) break;
    FUN_00010764();
    FUN_000107dc();
    FUN_00010108();
    FUN_0001073c();
    cVar1 = *param_1;
  }
  FUN_0000a7ac(param_1);
  param_1[8] = '\0';
  param_1[9] = '\0';
  return 0xffffffff;
}


================================================================