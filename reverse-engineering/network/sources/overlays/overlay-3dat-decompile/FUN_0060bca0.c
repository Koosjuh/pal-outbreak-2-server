FUNCTION FUN_0060bca0 @ 0x0060bca0  size=424
CALLERS (2): FUN_00608c80@0x00608c80, FUN_00609c60@0x00609c60
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060bca0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = *(uint *)(param_1 + 0x34);
  iVar6 = *(int *)(param_2 + 0x10);
  if (*(uint *)(param_1 + 0x38) < uVar1) {
    iVar3 = *(int *)(param_1 + 0x30) - uVar1;
  }
  else {
    iVar3 = *(uint *)(param_1 + 0x38) - uVar1;
  }
  uVar4 = (long)iVar3;
  if ((ulong)(long)*(int *)(param_2 + 0x14) < (ulong)(long)iVar3) {
    uVar4 = (long)*(int *)(param_2 + 0x14);
  }
  if ((uVar4 != 0) && (param_3 == -5)) {
    param_3 = 0;
  }
  iVar3 = (int)uVar4;
  *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) - iVar3;
  *(ulong *)(param_2 + 0x18) = *(long *)(param_2 + 0x18) + (uVar4 & 0xffffffff);
  if (*(code **)(param_1 + 0x3c) != (code *)0x0) {
    uVar2 = (**(code **)(param_1 + 0x3c))(*(undefined8 *)(param_1 + 0x40),uVar1,uVar4);
    *(undefined8 *)(param_1 + 0x40) = uVar2;
    *(undefined8 *)(param_2 + 0x38) = uVar2;
  }
  func_0x001069a8(iVar6,uVar1,uVar4);
  iVar5 = uVar1 + iVar3;
  iVar6 = iVar6 + iVar3;
  if (iVar5 == *(int *)(param_1 + 0x30)) {
    iVar5 = *(int *)(param_1 + 0x2c);
    if (*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x30)) {
      *(int *)(param_1 + 0x38) = iVar5;
    }
    uVar4 = (ulong)(*(int *)(param_1 + 0x38) - iVar5);
    if ((ulong)(long)*(int *)(param_2 + 0x14) < uVar4) {
      uVar4 = (long)*(int *)(param_2 + 0x14);
    }
    if ((uVar4 != 0) && (param_3 == -5)) {
      param_3 = 0;
    }
    iVar3 = (int)uVar4;
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) - iVar3;
    *(ulong *)(param_2 + 0x18) = *(long *)(param_2 + 0x18) + (uVar4 & 0xffffffff);
    if (*(code **)(param_1 + 0x3c) != (code *)0x0) {
      uVar2 = (**(code **)(param_1 + 0x3c))(*(undefined8 *)(param_1 + 0x40),iVar5,uVar4);
      *(undefined8 *)(param_1 + 0x40) = uVar2;
      *(undefined8 *)(param_2 + 0x38) = uVar2;
    }
    func_0x001069a8(iVar6,iVar5,uVar4);
    iVar6 = iVar6 + iVar3;
    iVar5 = iVar5 + iVar3;
  }
  *(int *)(param_2 + 0x10) = iVar6;
  *(int *)(param_1 + 0x34) = iVar5;
  return param_3;
}



================================================================