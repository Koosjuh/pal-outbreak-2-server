FUNCTION FUN_005be0a0 @ 0x005be0a0  size=128
CALLERS (15): FUN_005bfe00@0x005bfe00, FUN_005c2390@0x005c2390, FUN_005bebf0@0x005bebf0, FUN_005c0750@0x005c0750, FUN_005c28f0@0x005c28f0, FUN_005bfa70@0x005bfa70, FUN_005beb40@0x005beb40, FUN_005c2120@0x005c2120, FUN_005bdb00@0x005bdb00, FUN_005c0a00@0x005c0a00, FUN_005c02b0@0x005c02b0, FUN_005c04f0@0x005c04f0, ...
CALLEES (0): 
----------------------------------------------------------------

int FUN_005be0a0(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1 * 0x20;
    if (0x7f < iVar1) {
      return -1;
    }
    if (*(char *)(iVar2 + 0x6ca980) == '\0') break;
    iVar1 = iVar1 + 1;
  }
  *(undefined1 *)(iVar2 + 0x6ca980) = param_1;
  *(undefined1 *)(iVar2 + 0x6ca981) = 0;
  *(undefined4 *)(iVar2 + 0x6ca96c) = param_3;
  *(undefined4 *)(iVar2 + 0x6ca968) = param_2;
  return iVar1;
}



================================================================