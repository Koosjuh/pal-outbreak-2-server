FUNCTION FUN_006153b0 @ 0x006153b0  size=128
CALLERS (2): FUN_00610580@0x00610580, FUN_00610830@0x00610830
CALLEES (2): FUN_0060e440@0x0060e440, FUN_0060e660@0x0060e660
----------------------------------------------------------------

void FUN_006153b0(undefined8 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 auStack_4 [4];
  
  auStack_4[0] = 0;
  FUN_0060e440(0x3c98b0,param_1,auStack_4);
  FUN_0060e660(0x3c98b0,param_1);
  puVar3 = (undefined4 *)0x3ca2d0;
  iVar2 = 0x41;
  puVar4 = (undefined4 *)(iRam0070d1c0 + 0xed0);
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