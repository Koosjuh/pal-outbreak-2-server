FUNCTION FUN_005c51a0 @ 0x005c51a0  size=488
CALLERS (1): FUN_005c54e0@0x005c54e0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c51a0(undefined8 param_1,ushort param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = (uint)param_2;
  iVar3 = uVar2 * 0x24;
  func_0x00109eb8(iVar3 + 0x6fee6c,param_1);
  iVar4 = (int)param_1;
  *(undefined4 *)(iVar3 + 0x6fee8c) = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 *)(iVar3 + 0x6fee7c) = *(undefined4 *)(iVar4 + 0x10);
  *(undefined4 *)(iVar3 + 0x6fee88) = *(undefined4 *)(iVar4 + 0x1c);
  *(undefined4 *)(iVar3 + 0x6fee84) = *(undefined4 *)(iVar4 + 0x18);
  *(undefined4 *)(iVar3 + 0x6fee80) = *(undefined4 *)(iVar4 + 0x14);
  if (*(int *)(iVar4 + 0x10) == *(int *)(iVar4 + 0x1c)) {
    *(undefined1 *)(uVar2 * 0x144 + 0x6cfb74) = 4;
  }
  else {
    *(undefined1 *)(uVar2 * 0x144 + 0x6cfb74) = 3;
  }
  iVar3 = uVar2 * 0x144;
  iVar1 = uVar2 * 0x144;
  *(ushort *)(iVar1 + 0x6cfb60) = param_2 + 1;
  *(short *)(iVar1 + 0x6cfb66) = (short)*(undefined4 *)(iVar4 + 0x1c);
  *(short *)(iVar1 + 0x6cfb62) = (short)*(undefined4 *)(iVar4 + 0x10);
  *(uint *)(iVar1 + 0x6cfb5c) = *(uint *)(iVar4 + 0x18) >> 1;
  if ((*(uint *)(iVar1 + 0x6cfb5c) & 0x8000) == 0) {
    *(undefined1 *)(iVar3 + 0x6cfb75) = 0;
  }
  else {
    *(undefined1 *)(iVar3 + 0x6cfb75) = 1;
  }
  func_0x00109eb8(iVar3 + 0x6cfb76,param_1);
  return;
}



================================================================