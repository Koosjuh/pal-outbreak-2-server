FUNCTION FUN_005ede80 @ 0x005ede80  size=388
CALLERS (2): FUN_005e9790@0x005e9790, FUN_005e98e0@0x005e98e0
CALLEES (1): FUN_005d92f0@0x005d92f0
----------------------------------------------------------------

void FUN_005ede80(byte *param_1)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  
  while ((*param_1 != 0 && (((&DAT_006491b0)[*param_1] & 2) != 0))) {
    param_1 = param_1 + 1;
  }
  uVar1 = func_0x0010a050(param_1);
  if ((uVar1 & 0xffff) != 0) {
    for (pbVar5 = param_1 + ((uVar1 & 0xffff) - 1); (*pbVar5 == 0x20 || (*pbVar5 == 9));
        pbVar5 = pbVar5 + -1) {
      *pbVar5 = 0;
    }
  }
  uVar2 = 0;
  uVar1 = func_0x0010a050(param_1);
  for (uVar4 = 0; uVar4 < (uVar1 & 0xffff); uVar4 = uVar4 + 1 & 0xffff) {
    uVar6 = (uint)param_1[uVar4];
    if ((param_1[uVar4] & 0x80) != 0) {
      do {
        uVar3 = uVar6 << 1;
        uVar6 = uVar3 & 0xff;
        uVar4 = uVar4 + 1 & 0xffff;
      } while ((uVar3 & 0x80) != 0);
      uVar4 = uVar4 - 1 & 0xffff;
    }
    uVar2 = uVar2 + 1;
  }
  if (*(ushort *)(iRam007012a0 + 0x18) < uVar2) {
    *(ushort *)(iRam007012a0 + 0x18) = uVar2;
  }
  if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
    FUN_005d92f0(param_1,iRam007012a0 + 0x7f1,*(undefined1 *)(iRam007012a0 + 0x8f1));
    *(undefined1 *)(iRam007012a0 + 0x8f1) = 0;
  }
  return;
}



================================================================