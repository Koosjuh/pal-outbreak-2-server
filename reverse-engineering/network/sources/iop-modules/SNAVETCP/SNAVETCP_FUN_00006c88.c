FUNCTION FUN_00006c88 @ 0x00006c88 size=448
CALLERS (4): FUN_0000a7e8@0x0000a7e8, FUN_0000a848@0x0000a848, FUN_000060c0@0x000060c0, FUN_00003088@0x00003088
CALLEES (0): 

undefined4 FUN_00006c88(int *param_1,short param_2,undefined2 param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  if (param_2 < 0x400) {
    param_2 = 0x400;
  }
  iVar8 = 0;
  if (DAT_0001619c != 0) {
    uVar7 = (uint)param_2;
    iVar2 = 0;
    do {
      iVar6 = DAT_00016188 + (iVar2 >> 0x10) * 0x3c;
      if ((*(int *)(iVar6 + 4) != 0) && ((int)uVar7 <= *(int *)(iVar6 + 8))) {
        iVar4 = 0;
        iVar3 = 0;
        do {
          iVar3 = iVar3 >> 0x10;
          iVar5 = iVar6 + iVar3 * 6;
          if (((*(short *)(iVar5 + 0xc) != 0) && (*(short *)(iVar5 + 0xc) == -1)) &&
             (uVar7 <= *(ushort *)(iVar5 + 0x10))) {
            *param_1 = (iVar2 >> 0x10) * 0x1000000 + iVar3 * 0x10000;
            *(undefined1 *)(param_1 + 1) = 2;
            *(undefined2 *)(iVar5 + 0xc) = param_3;
            if (((iVar3 + 1 < 8) && (*(ushort *)(iVar5 + 0x10) != uVar7)) &&
               (iVar8 = iVar6 + (iVar3 + 1) * 6, *(short *)(iVar8 + 0xc) == 0)) {
              *(short *)(iVar8 + 0xe) = *(short *)(iVar5 + 0xe) + param_2;
              sVar1 = *(short *)(iVar5 + 0x10);
              *(undefined2 *)(iVar8 + 0xc) = 0xffff;
              *(short *)(iVar8 + 0x10) = sVar1 - param_2;
              *(short *)(iVar5 + 0x10) = param_2;
            }
            *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + -1;
            *(uint *)(iVar6 + 8) =
                 *(int *)(iVar6 + 8) - (uint)*(ushort *)(iVar6 + (short)iVar4 * 6 + 0x10);
            return 0;
          }
          iVar4 = iVar4 + 1;
          iVar3 = iVar4 * 0x10000;
        } while (iVar4 * 0x10000 >> 0x10 < 8);
      }
      iVar8 = iVar8 + 1;
      iVar2 = iVar8 * 0x10000;
    } while ((uint)(iVar8 * 0x10000 >> 0x10) < (uint)DAT_0001619c);
  }
  return 0xffffffff;
}


================================================================