FUNCTION FUN_0000c028 @ 0x0000c028 size=200
CALLERS (1): FUN_00001ff8@0x00001ff8
CALLEES (5): FUN_0001073c@0x0001073c, FUN_000053b4@0x000053b4, FUN_000107dc@0x000107dc, FUN_00010764@0x00010764, FUN_00010108@0x00010108

undefined4 FUN_0000c028(char *param_1)

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
  param_1[8] = '\0';
  param_1[9] = '\0';
  return 0xffffffff;
}


================================================================