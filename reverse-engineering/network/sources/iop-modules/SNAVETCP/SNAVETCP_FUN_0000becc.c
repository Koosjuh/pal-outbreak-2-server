FUNCTION FUN_0000becc @ 0x0000becc size=56
CALLERS (3): FUN_0000ad44@0x0000ad44, FUN_00007000@0x00007000, FUN_0000c968@0x0000c968
CALLEES (0): 

void FUN_0000becc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    *(undefined2 *)(param_1 + (iVar1 >> 0xf) + 0x124) = 0;
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 4);
  return;
}


================================================================