FUNCTION FUN_00007da4 @ 0x00007da4 size=56
CALLERS (2): FUN_00007b80@0x00007b80, FUN_00008918@0x00008918
CALLEES (0): 

int FUN_00007da4(char *param_1)

{
  char cVar1;
  short sVar2;
  
  sVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 == ' ') {
    param_1 = param_1 + 1;
    sVar2 = sVar2 + 1;
    cVar1 = *param_1;
  }
  return (int)sVar2;
}


================================================================