FUNCTION FUN_00628cc0 @ 0x00628cc0  size=324
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_00628cc0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined2 *)(param_1 + 0x26) = 0xce;
    *(undefined2 *)(param_1 + 0x28) = 0x165;
    *(undefined1 *)(param_1 + 1) = 1;
  }
  if (**(byte **)(param_1 + 0x10) < 2) {
    uVar4 = FUN_0062fea0(0x5a);
    uVar5 = FUN_0062fea0(0x5b);
    iVar1 = func_0x001ae3e0(uVar4);
    iVar2 = func_0x001ae3e0(uVar5);
    iVar6 = (iVar2 + iVar1) * 9;
    iVar3 = iVar6 + 0x18;
    if (iVar3 < 0) {
      iVar3 = iVar6 + 0x19;
    }
    FUN_005af2e0(0x12);
    FUN_005af2c0(0);
    iVar6 = 0x140 - (iVar3 >> 1);
    FUN_005af1e0(iVar6,0x168,2,uVar4);
    FUN_005af1e0((iVar3 >> 1) + 0x140 + iVar2 * -9,0x168,2,uVar5);
    *(short *)(param_1 + 0x26) = (short)iVar6 + (short)iVar1 * 9;
    *(undefined1 *)(param_1 + 1) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



================================================================