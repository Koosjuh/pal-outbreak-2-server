FUNCTION FUN_00000584 @ 0x00000584 size=340
CALLERS (1): FUN_00001298@0x00001298
CALLEES (0): 

int FUN_00000584(int *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = param_1[3];
  iVar7 = *param_1;
  iVar6 = 0;
  while( true ) {
    if (iVar3 < 1) {
      return iVar6;
    }
    uVar1 = *(ushort *)("smap: StartThread -> %d\n" + iVar7 + (param_1[5] & 0x3fU) * 8 + 4);
    if ((uVar1 & 0x8000) != 0) break;
    uVar2 = *(ushort *)
             ((int)("smap: StartThread -> %d\n" + iVar7 + (param_1[5] & 0x3fU) * 8 + 4) + 4);
    if ((uVar1 & 0xf2) != 0) {
      uVar5 = 0;
      piVar4 = param_1;
      do {
        if (((int)(uint)uVar1 >> (uVar5 & 0x1f) & 1U) != 0) {
          piVar4[0x22] = piVar4[0x22] + 1;
        }
        uVar5 = uVar5 + 1;
        piVar4 = piVar4 + 1;
      } while ((int)uVar5 < 0x10);
      param_1[0x37] = param_1[0x37] + 1;
      if ((uVar1 & 0x80) != 0) {
        param_1[0x4b] = param_1[0x4b] + 1;
      }
      if ((uVar1 & 0x40) != 0) {
        param_1[0x4e] = param_1[0x4e] + 1;
      }
      if ((uVar1 & 0x3c) != 0) {
        param_1[0x43] = param_1[0x43] + 1;
      }
      if ((uVar1 & 2) != 0) {
        param_1[0x4c] = param_1[0x4c] + 1;
      }
    }
    iVar6 = iVar6 + 1;
    param_1[2] = param_1[2] + (uVar2 + 3 & 0xfffffffc);
    iVar3 = param_1[3] + -1;
    param_1[3] = iVar3;
    param_1[5] = param_1[5] + 1;
  }
  return iVar6;
}


================================================================