FUNCTION FUN_00615430 @ 0x00615430  size=64
CALLERS (2): FUN_00610830@0x00610830, FUN_0060f910@0x0060f910
CALLEES (0): 
----------------------------------------------------------------

void FUN_00615430(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x3c9594;
  iVar2 = 0x41;
  puVar3 = (undefined4 *)(iRam0070d1c0 + 0xed0);
  do {
    iVar2 = iVar2 + -1;
    uVar1 = puVar4[1];
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 2;
    puVar3[1] = uVar1;
    puVar3 = puVar3 + 2;
  } while (0 < iVar2);
  return;
}



================================================================