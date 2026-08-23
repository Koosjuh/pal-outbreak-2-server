FUNCTION FUN_005dfa90 @ 0x005dfa90  size=104
CALLERS (1): FUN_005d7540@0x005d7540
CALLEES (0): 
----------------------------------------------------------------

int FUN_005dfa90(undefined1 *param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  for (; *param_2 != 0; param_2 = param_2 + 1) {
    *param_1 = 0x25;
    iVar1 = iVar1 + 3;
    param_1[1] = s_0123456789ABCDEF_006465c0[(int)(*param_2 & 0xf0) >> 4];
    param_1[2] = s_0123456789ABCDEF_006465c0[*param_2 & 0xf];
    param_1 = param_1 + 3;
  }
  *param_1 = 0;
  return iVar1;
}



================================================================