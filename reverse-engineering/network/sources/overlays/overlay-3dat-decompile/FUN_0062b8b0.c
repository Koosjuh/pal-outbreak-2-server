FUNCTION FUN_0062b8b0 @ 0x0062b8b0  size=304
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_0062b8b0(int param_1)

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
    *(undefined2 *)(param_1 + 0x26) = 0x128;
    *(undefined2 *)(param_1 + 0x28) = 0x195;
    *(undefined1 *)(param_1 + 1) = 1;
    *(undefined4 *)(param_1 + 0x34) = 0xffffffe6;
  }
  uVar4 = FUN_0062fea0(0x61);
  uVar5 = FUN_0062fea0(0x62);
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
  FUN_005af1e0(iVar6,0x198,2,uVar4);
  FUN_005af1e0((iVar3 >> 1) + 0x140 + iVar2 * -9,0x198,2,uVar5);
  *(short *)(param_1 + 0x26) = (short)iVar6 + (short)iVar1 * 9;
  return;
}



================================================================