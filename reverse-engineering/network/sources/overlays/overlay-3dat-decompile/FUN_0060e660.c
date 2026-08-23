FUNCTION FUN_0060e660 @ 0x0060e660  size=160
CALLERS (1): FUN_006153b0@0x006153b0
CALLEES (0): 
----------------------------------------------------------------

void FUN_0060e660(int param_1,int param_2)

{
  int iVar1;
  
  func_0x00109eb8(param_1 + 0x820,param_2 + 0xe00);
  func_0x00109eb8(param_1 + 0x920,param_2 + 0xf00);
  iVar1 = *(int *)(param_2 + 0x1310);
  if (iVar1 == 6) {
    *(undefined1 *)(param_1 + 8) = 4;
  }
  else if (iVar1 == 5) {
    *(undefined1 *)(param_1 + 8) = 3;
  }
  else if (iVar1 == 3) {
    *(undefined1 *)(param_1 + 8) = 2;
  }
  else if (iVar1 == 2) {
    *(undefined1 *)(param_1 + 8) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 8) = 0;
  }
  return;
}



================================================================