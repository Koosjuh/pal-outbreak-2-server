
uint FUN_001c3b90(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = FUN_001c3ab0();
  uVar1 = (uVar1 & 0xffff) - 2;
  uVar2 = FUN_001c3ab0(param_1);
  iVar5 = (int)param_1;
  if ((int)uVar1 < 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = uVar1 & 0xffff;
    if (param_3 < uVar4) {
      uVar4 = 0xfffffffe;
    }
    else {
      if (uVar4 != 0) {
        FUN_001069a8(param_2,*(int *)(iVar5 + 0x34) + (uint)*(ushort *)(iVar5 + 0x40),uVar4);
      }
      if (0 < (int)(param_3 - uVar4)) {
        FUN_00106b60((int)param_2 + uVar4,0);
      }
      uVar3 = FUN_001c3750(param_2,*(undefined1 *)(*(int *)(iVar5 + 0x30) + 5),uVar4,
                           *(undefined2 *)(iVar5 + 0x4c));
      if ((uVar2 & 0xffff) == uVar3) {
        *(short *)(iVar5 + 0x40) = *(short *)(iVar5 + 0x40) + (short)uVar1;
      }
      else {
        uVar4 = 0xfffffffd;
      }
    }
  }
  return uVar4;
}

