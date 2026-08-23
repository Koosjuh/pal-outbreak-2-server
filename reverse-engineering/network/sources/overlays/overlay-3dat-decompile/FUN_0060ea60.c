FUNCTION FUN_0060ea60 @ 0x0060ea60  size=56
CALLERS (3): FUN_0060e250@0x0060e250, FUN_0060e440@0x0060e440, FUN_00612120@0x00612120
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_0060ea60(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (; (uVar1 = 0, iVar2 < 4 && (uVar1 = 1, *param_1 == '\0')); param_1 = param_1 + 1) {
    iVar2 = iVar2 + 1;
  }
  return uVar1;
}



================================================================