FUNCTION FUN_005c6210 @ 0x005c6210  size=316
CALLERS (2): FUN_00616d30@0x00616d30, FUN_006173c0@0x006173c0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c6210(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 auStack_30 [12];
  
  puVar4 = auStack_30;
  iVar3 = 6;
  do {
    iVar3 = iVar3 + -1;
    uVar1 = param_1[1];
    *puVar4 = *param_1;
    param_1 = param_1 + 2;
    puVar4[1] = uVar1;
    puVar4 = puVar4 + 2;
  } while (0 < iVar3);
  uVar1 = 0xffffffff;
  if (cRam006cbb94 == '\0') {
    func_0x00106b60(0x6ff2bd,0,0x450);
    iVar5 = 0;
    iVar3 = 0;
    do {
      iVar2 = iVar5 * 0x114;
      func_0x001069a8(iVar2 + 0x6ff2bd,*(undefined4 *)((int)auStack_30 + iVar3),0x10);
      func_0x001069a8(iVar2 + 0x6ff2cd,*(undefined4 *)((int)auStack_30 + iVar3 + 0x10),0x10);
      func_0x001069a8(iVar2 + 0x6ff2e1,*(undefined4 *)((int)auStack_30 + iVar3 + 0x20),0xf0);
      iVar5 = iVar5 + 1;
      iVar3 = iVar5 * 4;
    } while (iVar5 < 4);
    cRam006cbb94 = '\x01';
    pcRam006cbb70 = FUN_005c6500;
    uVar1 = 0;
    uRam006cbb90 = 0;
    uRam006cbb74 = param_2;
  }
  return uVar1;
}



================================================================