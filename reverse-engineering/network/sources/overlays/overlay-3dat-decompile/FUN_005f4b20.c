FUNCTION FUN_005f4b20 @ 0x005f4b20  size=80
CALLERS (1): FUN_005f4be0@0x005f4be0
CALLEES (0): 
----------------------------------------------------------------

int FUN_005f4b20(char *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_4 [4];
  
  iVar2 = 0;
  for (; *param_1 != '\0'; param_1 = param_1 + iVar1) {
    iVar1 = func_0x001af430(param_1,auStack_4);
    iVar2 = iVar2 + iVar1;
  }
  return iVar2;
}



================================================================