FUNCTION FUN_006335f0 @ 0x006335f0  size=88
CALLERS (2): FUN_00633840@0x00633840, FUN_006336d0@0x006336d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_006335f0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x12;
  *(char *)(iVar1 + 0x7158f0) = (char)(param_1 + param_2);
  *(wchar_t *)(iVar1 + 0x7158f2) = u_____________________<_>_________0068f290[param_1 + param_2];
  *(undefined2 *)(iVar1 + 0x7158f4) = 0;
  return;
}



================================================================