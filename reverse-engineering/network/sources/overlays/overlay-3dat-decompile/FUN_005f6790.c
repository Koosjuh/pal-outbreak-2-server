FUNCTION FUN_005f6790 @ 0x005f6790  size=472
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_0062fdf0@0x0062fdf0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005f6790(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short unaff_s2_lo;
  undefined1 auStack_40 [64];
  
  *(undefined4 *)(param_1 + 0x30) = 0;
  iVar2 = *(int *)(param_1 + 0x10);
  sVar1 = *(short *)(iVar2 + 0xe);
  *(undefined2 *)(param_1 + 0x26) = 0x28;
  sVar1 = sVar1 + *(char *)(param_1 + 3);
  *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_00649720 + *(char *)(param_1 + 3) * 2);
  *(undefined1 *)(param_1 + 1) = 0;
  if (*(short *)(iVar2 + 8) != 0) {
    FUN_005af2e0(0x12);
    FUN_005af2c0(0);
    func_0x00109728(auStack_40,0x649750,sVar1 + 1);
    FUN_005af1e0(*(short *)(param_1 + 0x26) + 0x21,*(short *)(param_1 + 0x28) + 7,0,auStack_40);
    FUN_005af2c0(0x10);
    func_0x00106b60(auStack_40,0,0x40);
    iVar3 = (sVar1 * 2 + (int)sVar1) * 0x10;
    func_0x001069a8(auStack_40,iVar3 + 0x70a164,0x10);
    FUN_005af1e0(*(short *)(param_1 + 0x26) + 0x70,*(short *)(param_1 + 0x28) + 7,0,auStack_40);
    sVar1 = func_0x001ae3e0(auStack_40);
    unaff_s2_lo = *(short *)(param_1 + 0x26) + 0xde + sVar1 * 9;
    if ((long)*(short *)(iVar2 + 0xc) == (long)*(char *)(param_1 + 3)) {
      FUN_005af2c0(0xf);
    }
    else {
      FUN_005af2c0(0);
    }
    iVar2 = FUN_0062fdf0(10);
    iVar2 = iVar2 + (*(uint *)(iVar3 + 0x70a17c) & 1) * 0xc;
    FUN_005af2e0(*(undefined1 *)(iVar2 + 1));
    FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(short *)(param_1 + 0x28) + 7,
                 *(undefined1 *)(iVar2 + 3),*(undefined4 *)(iVar2 + 8));
  }
  *(short *)(param_1 + 0x26) = unaff_s2_lo;
  *(short *)(param_1 + 0x28) = *(short *)(param_1 + 0x28) + 8;
  return;
}



================================================================