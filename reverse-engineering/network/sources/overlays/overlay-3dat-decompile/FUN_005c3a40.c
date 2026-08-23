FUNCTION FUN_005c3a40 @ 0x005c3a40  size=196
CALLERS (0): 
CALLEES (2): FUN_005c7d00@0x005c7d00, FUN_005bf1e0@0x005bf1e0
----------------------------------------------------------------

void FUN_005c3a40(char *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cba7d = 1;
    uRam006ff2b0 = 1;
    uVar1 = FUN_005bf1e0(2);
    iVar2 = (uVar1 & 0xffff) - 1;
    *(undefined4 *)(iVar2 * 0x24 + 0x6fee8c) = *(undefined4 *)(param_2 + 4);
    func_0x00109eb8(iVar2 * 0x144 + 0x6cfb76,0x6cc01a);
  }
  else if (*param_1 == '\'') {
    uRam006cba7d = 2;
  }
  return;
}



================================================================