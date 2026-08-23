FUNCTION FUN_00006e48 @ 0x00006e48 size=436
CALLERS (4): FUN_00001760@0x00001760, FUN_000030f4@0x000030f4, FUN_0000a8a8@0x0000a8a8, FUN_0000a8e8@0x0000a8e8
CALLEES (0): 

undefined4 FUN_00006e48(int param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = (uint)*(byte *)(param_1 + 2);
  if (((uint)*(byte *)(param_1 + 3) <= (uint)DAT_0001619c) && (uVar6 < 9)) {
    iVar7 = DAT_00016188 + (uint)*(byte *)(param_1 + 3) * 0x3c;
    iVar4 = iVar7 + uVar6 * 6;
    if (*(short *)(iVar4 + 0xc) != -1) {
      *(undefined2 *)(iVar4 + 0xc) = 0xffff;
      *(int *)(iVar7 + 4) = *(int *)(iVar7 + 4) + 1;
      *(uint *)(iVar7 + 8) = *(int *)(iVar7 + 8) + (uint)*(ushort *)(iVar4 + 0x10);
      if ((uVar6 == 7) ||
         (uVar3 = uVar6 + 1, uVar2 = uVar6 + 1, *(short *)(iVar7 + (uVar6 + 1) * 6 + 0xc) != -1)) {
        uVar3 = uVar6;
        uVar2 = uVar6;
      }
      while( true ) {
        uVar2 = uVar2 - 1;
        if ((int)(uVar2 * 0x10000) < 0) {
          return 0;
        }
        iVar4 = iVar7 + (short)uVar2 * 6;
        sVar1 = *(short *)(iVar4 + 0xc);
        if (0 < sVar1) break;
        if (sVar1 == 0) {
          iVar5 = iVar7 + (short)uVar3 * 6;
          *(undefined2 *)(iVar4 + 0xc) = 0xffff;
          *(undefined2 *)(iVar5 + 0xc) = 0;
          *(undefined2 *)(iVar4 + 0xe) = *(undefined2 *)(iVar5 + 0xe);
          sVar1 = *(short *)(iVar5 + 0x10);
          *(short *)(iVar4 + 0x10) = sVar1;
          *(undefined2 *)(iVar5 + 0x10) = 0;
          *(short *)(iVar5 + 0xe) = *(short *)(iVar5 + 0xe) + sVar1;
        }
        else {
          if (sVar1 != -1) {
            return 0;
          }
          iVar5 = iVar7 + (short)uVar3 * 6;
          *(undefined2 *)(iVar5 + 0xc) = 0;
          *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + *(short *)(iVar5 + 0x10);
          *(undefined2 *)(iVar5 + 0x10) = 0;
          *(short *)(iVar5 + 0xe) = *(short *)(iVar4 + 0xe) + *(short *)(iVar4 + 0x10);
        }
        uVar3 = uVar3 - 1;
      }
      return 0;
    }
  }
  return 0xffffffff;
}


================================================================