FUNCTION FUN_005e9a10 @ 0x005e9a10  size=116
CALLERS (0): 
CALLEES (1): FUN_005eef70@0x005eef70
----------------------------------------------------------------

undefined8 FUN_005e9a10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = func_0x0010a050(param_2);
      (iVar1 != 0 && (iVar2 = (int)param_2 + iVar1, *(char *)(iVar2 + -1) == ' '));
      iVar1 = iVar1 + -1) {
    *(undefined1 *)(iVar2 + -1) = 0;
  }
  FUN_005eef70(param_2);
  *(undefined1 *)(iRam007012a0 + 0x17f) = 0;
  return 0;
}



================================================================