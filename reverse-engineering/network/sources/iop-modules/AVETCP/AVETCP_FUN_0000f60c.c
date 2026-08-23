FUNCTION FUN_0000f60c @ 0x0000f60c size=600
CALLERS (2): FUN_0000f228@0x0000f228, FUN_0000f344@0x0000f344
CALLEES (0): 

int FUN_0000f60c(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_0001619a != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 >> 0x10;
      if ((((((&DAT_0001835e)[iVar1 * 0xe] & 1) != 0) && (((&DAT_0001835e)[iVar1 * 0xe] & 8) != 0))
          && (((&DAT_00018350)[iVar1 * 7] == ((&DAT_00018354)[iVar1 * 7] & param_1) ||
              ((param_1 == 0xffffffff || (param_1 == 0)))))) &&
         ((&DAT_00018369)[iVar1 * 0x1c] == '\x01')) {
        return (int)(short)iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619a);
  }
  iVar2 = 0;
  if (DAT_0001619a != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 >> 0x10;
      if (((((&DAT_0001835e)[iVar1 * 0xe] & 1) != 0) && (((&DAT_0001835e)[iVar1 * 0xe] & 4) != 0))
         && ((&DAT_00018350)[iVar1 * 7] == ((&DAT_00018354)[iVar1 * 7] & param_1))) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619a);
  }
  iVar2 = 0;
  if (DAT_0001619a != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 >> 0x10;
      if (((((&DAT_0001835e)[iVar1 * 0xe] & 1) != 0) && (((&DAT_0001835e)[iVar1 * 0xe] & 2) != 0))
         && ((&DAT_00018350)[iVar1 * 7] == ((&DAT_00018354)[iVar1 * 7] & param_1))) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619a);
  }
  iVar2 = 0;
  if (DAT_0001619a != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 >> 0x10;
      if (((((&DAT_0001835e)[iVar1 * 0xe] & 1) != 0) && (((&DAT_0001835e)[iVar1 * 0xe] & 2) != 0))
         && ((&DAT_00018350)[iVar1 * 7] == 0)) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619a);
  }
  return -1;
}


================================================================