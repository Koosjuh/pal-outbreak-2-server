FUNCTION FUN_0000f09c @ 0x0000f09c size=396
CALLERS (1): FUN_00001ab0@0x00001ab0
CALLEES (2): FUN_0000f580@0x0000f580, FUN_0000ec30@0x0000ec30

undefined4 FUN_0000f09c(uint param_1,undefined4 param_2,ushort param_3,int param_4)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar2 = FUN_0000f580(param_1,DAT_00017e14,DAT_00017e10);
  iVar7 = 0;
  if (DAT_0001619a != 0) {
    do {
      iVar3 = (int)(short)iVar7;
      if ((((&DAT_000183fe)[iVar3 * 0xe] & 1) != 0) && ((&DAT_000183f8)[iVar3 * 7] == param_4)) {
        uVar5 = (&DAT_000183f0)[iVar3 * 7];
        (&DAT_00018408)[iVar3 * 0x1c] = 1;
        if (uVar5 == 0) {
          param_3 = param_3 & 4 | 2;
          break;
        }
        uVar6 = param_1 & (&DAT_000183f4)[iVar3 * 7];
        if ((((uVar5 & (&DAT_000183f4)[iVar3 * 7]) == uVar6) ||
            (((param_3 & 4) == 0 && ((uVar5 & uVar2) == uVar6)))) &&
           ((((&DAT_000183fe)[iVar3 * 0xe] & 4) != 0 || ((param_3 & 4) == 0)))) {
          (&DAT_000183fe)[iVar3 * 0xe] = param_3 | 0x23;
          (&DAT_000183f8)[iVar3 * 7] = param_2;
          return 0;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619a);
  }
  sVar1 = FUN_0000ec30(param_1,uVar2,param_2,1,2,param_3 | 0x10);
  uVar4 = 0xffffffff;
  if (sVar1 == 0) {
    uVar4 = 0;
  }
  return uVar4;
}


================================================================