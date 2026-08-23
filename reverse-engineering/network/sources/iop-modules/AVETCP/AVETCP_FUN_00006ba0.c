FUNCTION FUN_00006ba0 @ 0x00006ba0 size=232
CALLERS (1): FUN_00004620@0x00004620
CALLEES (0): 

undefined4 FUN_00006ba0(void)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = DAT_00016188;
  uVar3 = (uint)DAT_0001619c;
  DAT_000168b0 = DAT_00016184;
  iVar6 = 0;
  if (uVar3 != 0) {
    uVar7 = (uint)DAT_000154f0;
    do {
      iVar4 = 1;
      piVar5 = (int *)(iVar1 + (short)iVar6 * 0x3c);
      piVar5[1] = 8;
      piVar5[2] = 0x2000;
      *(undefined2 *)(piVar5 + 3) = 0xffff;
      *(undefined2 *)((int)piVar5 + 0xe) = 0;
      *(undefined2 *)(piVar5 + 4) = 0x2000;
      *piVar5 = DAT_000168b0;
      DAT_000168b0 = DAT_000168b0 + uVar7;
      do {
        sVar2 = (short)iVar4;
        iVar4 = iVar4 + 1;
        *(undefined2 *)((int)piVar5 + sVar2 * 6 + 0xc) = 0;
        *(undefined2 *)((int)piVar5 + sVar2 * 6 + 0xe) = 0x2000;
        *(undefined2 *)((int)piVar5 + sVar2 * 6 + 0x10) = 0;
      } while (iVar4 * 0x10000 >> 0x10 < 8);
      iVar6 = iVar6 + 1;
    } while ((uint)(iVar6 * 0x10000 >> 0x10) < uVar3);
  }
  return 0;
}


================================================================